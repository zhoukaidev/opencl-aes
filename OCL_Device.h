#pragma once
#include <CL/opencl.h>

namespace ocl
{
	cl_context creteContext();

	cl_command_queue createCommandQueue(cl_context context, 
		cl_device_id* device);

	cl_program CreateProgram(cl_context context, cl_device_id device, 
		const char *fileName);
}