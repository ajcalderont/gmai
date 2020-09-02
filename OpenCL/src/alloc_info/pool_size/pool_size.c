#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

int main()
{
	// Initialization
	/*----------------------------------------------------------------------------------------*/
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint num_platforms;
    cl_uint num_devices;
    cl_int ret;
    
    ret = clGetPlatformIDs(1, &platform_id, &num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devices);
    
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
	
	// Pool size
	/*----------------------------------------------------------------------------------------*/
	static int pool_size = 1;
	break_01: __attribute__((unused));
    cl_mem d_data_A = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, 1, NULL, &ret);
    
    // Finalization
	/*----------------------------------------------------------------------------------------*/
    ret = clReleaseMemObject(d_data_A);
    ret = clReleaseContext(context);
    
	return 0;
}