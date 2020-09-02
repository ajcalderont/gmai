#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

int main(int argc, char* argv[])
{
	// Initialization
	/*----------------------------------------------------------------------------------------*/
    static int pool_size = 0;
    pool_size = atoi(argv[1]);
    
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint num_platforms;
    cl_uint num_devices;
    cl_int ret;
    
    ret = clGetPlatformIDs(1, &platform_id, &num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devices);
    
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

    // Shrinking support
	/*----------------------------------------------------------------------------------------*/
    cl_mem buf_A = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, pool_size, NULL, &ret);
    cl_mem buf_B = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, pool_size, NULL, &ret);
    
    static int flag = 0;
    break_01: __attribute__((unused));
    ret = clReleaseMemObject(buf_A);
    flag = 1;
    ret = clReleaseMemObject(buf_B);
    flag = 2;
    break_02: __attribute__((unused));

	// Finalization
	/*----------------------------------------------------------------------------------------*/
    ret = clReleaseContext(context);

	return 0;
}