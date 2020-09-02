device_properties:
	-@$(CC) -g device_properties.c -o device_properties -l OpenCL

get_alloc_info: device_properties
	-@gdb -batch-silent -iex "set auto-load safe-path /" device_properties 

# 2>/dev/null

.PHONY: clean

clean:
	-@rm -f device_properties