#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

int main(int argc, char* argv[])
{
	// Initialization
	/*----------------------------------------------------------------------------------------*/
    static int granularity = 0;
    granularity = atoi(argv[1]);
    
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint num_platforms;
    cl_uint num_devices;
    cl_int ret;
    
    ret = clGetPlatformIDs(1, &platform_id, &num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devices);
    
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

    // Splitting support
	/*----------------------------------------------------------------------------------------*/
    cl_mem buf_1 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, granularity * 2, NULL, &ret);
    cl_mem buf_2 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, granularity, NULL, &ret);
    char *h_1 = (char*)clEnqueueMapBuffer(command_queue, buf_1, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, granularity * 2, 0, NULL, NULL, &ret);
    char *h_2 = (char*)clEnqueueMapBuffer(command_queue, buf_2, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, granularity, 0, NULL, NULL, &ret);

    ret = clEnqueueUnmapMemObject(command_queue, buf_1, h_1, 0, NULL, NULL);
    clFinish(command_queue);
    ret = clReleaseMemObject(buf_1);
    
    cl_mem buf_3 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, granularity, NULL, &ret);
    char *h_3 = (char*)clEnqueueMapBuffer(command_queue, buf_3, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, granularity, 0, NULL, NULL, &ret);
    break_01: __attribute__((unused));

    ret = clEnqueueUnmapMemObject(command_queue, buf_2, h_2, 0, NULL, NULL);
    ret = clEnqueueUnmapMemObject(command_queue, buf_3, h_3, 0, NULL, NULL);
    clFinish(command_queue);

	// Finalization
	/*----------------------------------------------------------------------------------------*/
    ret = clReleaseMemObject(buf_2);
    ret = clReleaseMemObject(buf_3);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);
	return 0;
}