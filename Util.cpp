#include "Util.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

void ocl::CHECK_OPENCL_ERROR(cl_int err)
{
	if (err != CL_SUCCESS)
	{
		switch (err)
		{
		case CL_DEVICE_NOT_FOUND:
			printf("CL_DEVICE_NOT_FOUND\n"); //exit(-1);
		case CL_DEVICE_NOT_AVAILABLE:
			printf("CL_DEVICE_NOT_AVAILABLE\n"); //exit(-1);
		case CL_COMPILER_NOT_AVAILABLE:
			printf("CL_COMPILER_NOT_AVAILABLE\n"); //exit(-1);
		case CL_MEM_OBJECT_ALLOCATION_FAILURE:
			printf("CL_MEM_OBJECT_ALLOCATION_FAILURE\n"); //exit(-1);
		case CL_OUT_OF_RESOURCES:
			printf("CL_OUT_OF_RESOURCES\n"); //exit(-1);
		case CL_OUT_OF_HOST_MEMORY:
			printf("CL_OUT_OF_HOST_MEMORY\n"); //exit(-1);
		case CL_PROFILING_INFO_NOT_AVAILABLE:
			printf("CL_PROFILING_INFO_NOT_AVAILABLE\n"); //exit(-1);
		case CL_MEM_COPY_OVERLAP:
			printf("CL_MEM_COPY_OVERLAP\n"); //exit(-1);
		case CL_IMAGE_FORMAT_MISMATCH:
			printf("CL_IMAGE_FORMAT_MISMATCH\n"); //exit(-1);
		case CL_IMAGE_FORMAT_NOT_SUPPORTED:
			printf("CL_IMAGE_FORMAT_NOT_SUPPORTED\n"); //exit(-1);
		case CL_BUILD_PROGRAM_FAILURE:
			printf("CL_BUILD_PROGRAM_FAILURE\n"); //exit(-1);
		case CL_MAP_FAILURE:
			printf("CL_MAP_FAILURE\n"); //exit(-1);
		case CL_MISALIGNED_SUB_BUFFER_OFFSET:
			printf("CL_MISALIGNED_SUB_BUFFER_OFFSET\n"); //exit(-1);
		case CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST:
			printf("CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST\n"); //exit(-1);
		case CL_COMPILE_PROGRAM_FAILURE:
			printf("CL_COMPILE_PROGRAM_FAILURE\n"); //exit(-1);
		case CL_LINKER_NOT_AVAILABLE:
			printf("CL_LINKER_NOT_AVAILABLE\n"); //exit(-1);
		case CL_LINK_PROGRAM_FAILURE:
			printf("CL_LINK_PROGRAM_FAILURE\n"); //exit(-1);
		case CL_DEVICE_PARTITION_FAILED:
			printf("CL_DEVICE_PARTITION_FAILED\n"); //exit(-1);
		case CL_KERNEL_ARG_INFO_NOT_AVAILABLE:
			printf("CL_KERNEL_ARG_INFO_NOT_AVAILABLE\n"); //exit(-1);

		case CL_INVALID_VALUE:
			printf("CL_INVALID_VALUE\n"); //exit(-1);
		case CL_INVALID_DEVICE_TYPE:
			printf("CL_INVALID_DEVICE_TYPE\n"); //exit(-1);
		case CL_INVALID_PLATFORM:
			printf("CL_INVALID_PLATFORM\n"); //exit(-1);
		case CL_INVALID_DEVICE:
			printf("CL_INVALID_DEVICE\n"); //exit(-1);
		case CL_INVALID_CONTEXT:
			printf("CL_INVALID_CONTEXT\n"); //exit(-1);
		case CL_INVALID_QUEUE_PROPERTIES:
			printf("CL_INVALID_QUEUE_PROPERTIES\n"); //exit(-1);
		case CL_INVALID_COMMAND_QUEUE:
			printf("CL_INVALID_COMMAND_QUEUE\n"); //exit(-1);
		case CL_INVALID_HOST_PTR:
			printf("CL_INVALID_HOST_PTR\n"); //exit(-1);
		case CL_INVALID_MEM_OBJECT:
			printf("CL_INVALID_MEM_OBJECT\n"); //exit(-1);
		case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR:
			printf("CL_INVALID_IMAGE_FORMAT_DESCRIPTOR\n"); //exit(-1);
		case CL_INVALID_IMAGE_SIZE:
			printf("CL_INVALID_IMAGE_SIZE\n"); //exit(-1);
		case CL_INVALID_SAMPLER:
			printf("CL_INVALID_SAMPLER\n"); //exit(-1);
		case CL_INVALID_BINARY:
			printf("CL_INVALID_BINARY\n"); //exit(-1);
		case CL_INVALID_BUILD_OPTIONS:
			printf("CL_INVALID_BUILD_OPTIONS\n"); //exit(-1);
		case CL_INVALID_PROGRAM:
			printf("CL_INVALID_PROGRAM\n"); //exit(-1);
		case CL_INVALID_PROGRAM_EXECUTABLE:
			printf("CL_INVALID_PROGRAM_EXECUTABLE\n"); //exit(-1);
		case CL_INVALID_KERNEL_NAME:
			printf("CL_INVALID_KERNEL_NAME\n"); //exit(-1);
		case CL_INVALID_KERNEL_DEFINITION:
			printf("CL_INVALID_KERNEL_DEFINITION\n"); //exit(-1);
		case CL_INVALID_KERNEL:
			printf("CL_INVALID_KERNEL\n"); //exit(-1);
		case CL_INVALID_ARG_INDEX:
			printf("CL_INVALID_ARG_INDEX\n"); //exit(-1);
		case CL_INVALID_ARG_VALUE:
			printf("CL_INVALID_ARG_VALUE\n"); //exit(-1);
		case CL_INVALID_ARG_SIZE:
			printf("CL_INVALID_ARG_SIZE\n"); //exit(-1);
		case CL_INVALID_KERNEL_ARGS:
			printf("CL_INVALID_KERNEL_ARGS\n"); //exit(-1);
		case CL_INVALID_WORK_DIMENSION:
			printf("CL_INVALID_WORK_DIMENSION\n"); //exit(-1);
		case CL_INVALID_WORK_GROUP_SIZE:
			printf("CL_INVALID_WORK_GROUP_SIZE\n"); //exit(-1);
		case CL_INVALID_WORK_ITEM_SIZE:
			printf("CL_INVALID_WORK_ITEM_SIZE\n"); //exit(-1);
		case CL_INVALID_GLOBAL_OFFSET:
			printf("CL_INVALID_GLOBAL_OFFSET\n"); //exit(-1);
		case CL_INVALID_EVENT_WAIT_LIST:
			printf("CL_INVALID_EVENT_WAIT_LIST\n"); //exit(-1);
		case CL_INVALID_EVENT:
			printf("CL_INVALID_EVENT\n"); //exit(-1);
		case CL_INVALID_OPERATION:
			printf("CL_INVALID_OPERATION\n"); //exit(-1);
		case CL_INVALID_GL_OBJECT:
			printf("CL_INVALID_GL_OBJECT\n"); //exit(-1);
		case CL_INVALID_BUFFER_SIZE:
			printf("CL_INVALID_BUFFER_SIZE\n"); //exit(-1);
		case CL_INVALID_MIP_LEVEL:
			printf("CL_INVALID_MIP_LEVEL\n"); //exit(-1);
		case CL_INVALID_GLOBAL_WORK_SIZE:
			printf("CL_INVALID_GLOBAL_WORK_SIZE\n"); //exit(-1);
		case CL_INVALID_PROPERTY:
			printf("CL_INVALID_PROPERTY\n"); //exit(-1);
		case CL_INVALID_IMAGE_DESCRIPTOR:
			printf("CL_INVALID_IMAGE_DESCRIPTOR\n"); //exit(-1);
		case CL_INVALID_COMPILER_OPTIONS:
			printf("CL_INVALID_COMPILER_OPTIONS\n"); //exit(-1);
		case CL_INVALID_LINKER_OPTIONS:
			printf("CL_INVALID_LINKER_OPTIONS\n"); //exit(-1);
		case CL_INVALID_DEVICE_PARTITION_COUNT:
			printf("CL_INVALID_DEVICE_PARTITION_COUNT\n"); //exit(-1);
		}
	}
}

void ocl::DisplayContextInfo(cl_context context)
{
	cl_int errNum;
	cl_uint deviceCount;
	size_t size;
	cl_uint computeUnits;
	errNum = clGetContextInfo(context, CL_CONTEXT_NUM_DEVICES, sizeof(cl_uint), 
		&deviceCount, NULL);
	ocl::CHECK_OPENCL_ERROR(errNum);
	std::clog << "this context contain " << deviceCount << " devices" << std::endl;
	cl_device_id* devices = new cl_device_id[deviceCount];
	clGetContextInfo(context, CL_CONTEXT_DEVICES, sizeof(cl_device_id)*deviceCount, devices, NULL);
	for (cl_uint i = 0; i < deviceCount; ++i) {
		cl_device_type type;
		clGetDeviceInfo(devices[i], CL_DEVICE_TYPE, sizeof(cl_device_type), &type, NULL);
		std::clog << "Device[" << i << "] : ";
		switch (type)
		{
		case CL_DEVICE_TYPE_GPU:
			std::clog << "CL_DEVICE_TYPE_gPU" << std::endl;
			break;
		case CL_DEVICE_TYPE_CPU:
			std::clog << "CL_DEVICE_TYPE_cPU" << std::endl;
			break;
		case CL_DEVICE_TYPE_ACCELERATOR:
			std::clog << "CL_DEVICE_TYPE_ACCELERATOR" << std::endl;
			break;
		default:
			break;
		}
		
		errNum = clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 0, NULL, &size);
		ocl::CHECK_OPENCL_ERROR(errNum);
		char* name = new char[size];
		clGetDeviceInfo(devices[i], CL_DEVICE_NAME, size, name, NULL);
		std::cout << "Device[" << i << "]: " << name << std::endl;
		errNum = clGetDeviceInfo(devices[i], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &computeUnits, NULL);
		std::clog << "Device[" << i << "] max compute units: " << computeUnits << std::endl;
		delete[]name;
	}
}
