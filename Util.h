#pragma once

#include <CL/opencl.h> 
namespace ocl
{
	void CHECK_OPENCL_ERROR(cl_int err);
	void DisplayContextInfo(cl_context context);
}

namespace util
{
	
}