POOL_SIZE := $$(awk '/PSZ/ {print $$2}' ../info.cfg)

pool_usage:
	-@$(CC) -g pool_usage.c -o pool_usage -l OpenCL

get_alloc_info: pool_usage
	-@gdb -batch-silent -iex "set auto-load safe-path /" --args pool_usage $(POOL_SIZE) 2>/dev/null

.PHONY: clean

clean:
	-@rm -f pool_usage