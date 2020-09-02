pool_size:
	-@$(CC) -g pool_size.c -o pool_size -l OpenCL

get_alloc_info: pool_size
	-@gdb -batch-silent -iex "set auto-load safe-path /" pool_size 2>/dev/null

.PHONY: clean

clean:
	-@rm -f pool_size