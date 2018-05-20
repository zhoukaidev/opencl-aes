#include "OCL_Device.h"
#include <iostream>
#include <fstream>
#include <sstream>

cl_context ocl::creteContext()
{
	cl_int errNum;
	cl_uint numPlatforms;
	cl_platform_id firstPlatformId[3]; //at most 3 platform? my system has cpu, intel hd graphic and nvidia graphic! 
	cl_context context = NULL;
	errNum = clGetPlatformIDs(0, NULL, &numPlatforms);
	//errNum = clGetPlatformIDs(1, &firstPlatformId, &numPlatforms);
	errNum = clGetPlatformIDs(3, firstPlatformId, &numPlatforms);
	if (CL_SUCCESS != errNum || numPlatforms <= 0) {
		std::cerr << "Failed to find any OpenCL platforms." << std::endl;
		return NULL;
	}
	cl_context_properties contextProperties[] = {
		CL_CONTEXT_PLATFORM,
		(cl_context_properties)firstPlatformId[0], //use the first opencl platform in system
		//(cl_context_properties)firstPlatformId[1], //use the second opencl platform in system
		0
	};
	context = clCreateContextFromType(contextProperties,
		CL_DEVICE_TYPE_GPU,
		NULL, NULL, &errNum);
	if (CL_SUCCESS != errNum) {
		std::cout << "Could not create GPU context,try CPU..." << std::endl;
		context = clCreateContextFromType(contextProperties,
			CL_DEVICE_TYPE_CPU,
			NULL, NULL, &errNum);
		if (CL_SUCCESS != errNum) {
			std::cerr << "Failed to create an OpenCL GPU or CPU context.";
			return NULL;
		}
	}
	return context;
}

cl_command_queue ocl::createCommandQueue(cl_context context, cl_device_id* device)
{
	cl_int errNum;
	cl_device_id * devices;
	cl_command_queue commandQueue = NULL;
	std::size_t deviceBufferSize = -1;
	errNum = clGetContextInfo(context, CL_CONTEXT_DEVICES, 0, NULL,
		&deviceBufferSize);
	if (CL_SUCCESS != errNum) {
		std::cerr << "Failed call to clGetContextInfo(...,GL_CONTEXT_DEVICES,...)";
		return NULL;
	}
	if (deviceBufferSize <= 0) {
		std::cerr << "No devices avaliable.";
		return NULL;
	}
	devices = new cl_device_id[deviceBufferSize / sizeof(cl_device_id)];
	errNum = clGetContextInfo(context, CL_CONTEXT_DEVICES,
		deviceBufferSize, devices, NULL);
	if (CL_SUCCESS != errNum) {
		std::cerr << "Failed to get device IDs";
		return	NULL;
	}
	commandQueue = clCreateCommandQueue(context, devices[0], 0, NULL);
	if (NULL == commandQueue) {
		std::cerr << "Failed to create commandQueue for device 0";
		return	NULL;
	}
	*device = devices[0];
	delete[]devices;
	return commandQueue;
}

cl_program ocl::CreateProgram(cl_context context, cl_device_id device, const char *fileName)
{
	cl_int errNum;
	cl_program program;
	std::ifstream kernelFile(fileName, std::ios::in);
	if (!kernelFile.is_open()) {
		std::cerr << "Failed to open file for reading: " << fileName
			<< std::endl;
		return	NULL;
	}
	std::ostringstream oss;
	oss << kernelFile.rdbuf();
	std::string srcStdStr = oss.str();
	const char *srcStr = srcStdStr.c_str();
	program = clCreateProgramWithSource(context, 1, (const char**)&srcStr,
		NULL, NULL);
	if (NULL == program) {
		std::cerr << "Failed to create CL program from source." << std::endl;
		return NULL;
	}
	errNum = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	if (CL_SUCCESS != errNum) {
		char buildLog[16384];
		clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG,
			sizeof(buildLog), buildLog, NULL);
		std::cerr << "Error in kernel: " << std::endl;
		std::cerr << buildLog;
		clReleaseProgram(program);
		return NULL;
	}
	return program;
}