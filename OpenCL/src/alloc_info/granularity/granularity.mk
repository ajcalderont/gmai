POOL_SIZE := $$(awk '/PSZ/ {print $$2}' ../info.cfg)

granularity:
	-@$(CC) -g granularity.c -o granularity -l OpenCL

get_alloc_info: granularity
	-@gdb -batch-silent -iex "set auto-load safe-path /" --args granularity $(POOL_SIZE) 2>/dev/null

.PHONY: clean

clean:
	-@rm -f granularity