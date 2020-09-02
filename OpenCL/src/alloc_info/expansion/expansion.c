#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

int main(int argc, char* argv[])
{
	// Initialization
	/*----------------------------------------------------------------------------------------*/
    static int pool_size = 7, granularity = 8;
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
    
    // Expansion policy
	/*----------------------------------------------------------------------------------------*/
    static int max_allocations = 0;
    max_allocations = (pool_size / granularity) + 1;
    cl_mem *data_array_A = (cl_mem*) malloc(max_allocations * sizeof(cl_mem));
	data_array_A[0] = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, granularity, NULL, &ret);
	break_01: __attribute__((unused));
	static int index = 1;
	while(index < max_allocations)
	{ 
		data_array_A[index] = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, granularity, NULL, &ret);
        index++;
	}
    
	// Finalization
	/*----------------------------------------------------------------------------------------*/
    for(int i = 0; i < index; i++)
    {
        ret = clReleaseMemObject(data_array_A[i]);
    }
	free(data_array_A);
    ret = clReleaseContext(context);

	return 0;
}