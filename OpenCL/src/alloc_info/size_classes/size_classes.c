#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

int main(int argc, char* argv[])
{
	// Initialization
	/*----------------------------------------------------------------------------------------*/
    static int pool_size = 0, granularity = 0;
    pool_size = atoi(argv[1]);
    granularity = atoi(argv[2]);

    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint num_platforms;
    cl_uint num_devices;
    cl_int ret;
    
    ret = clGetPlatformIDs(1, &platform_id, &num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devices);
    
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
	
	// Size classes detection
	/*----------------------------------------------------------------------------------------*/
    static int inferior_size = 0, superior_size = 0;
	inferior_size = granularity;
	superior_size = granularity;
    cl_mem d_data_inf = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, inferior_size, NULL, &ret);
	break_01: __attribute__((unused));
    while(superior_size < pool_size)
    {
        superior_size += granularity;
        cl_mem d_data_sup = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, superior_size, NULL, &ret);
        clReleaseMemObject(d_data_sup);
    }

	// Finalization
	/*----------------------------------------------------------------------------------------*/
    ret = clReleaseMemObject(d_data_inf);
    ret = clReleaseContext(context);

	return 0;
}