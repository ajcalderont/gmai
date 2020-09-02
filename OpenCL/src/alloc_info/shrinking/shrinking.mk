POOL_SIZE := $$(awk '/PSZ/ {print $$2}' ../info.cfg)

shrinking:
	-@$(CC) -g shrinking.c -o shrinking -l OpenCL

get_alloc_info: shrinking
	-@gdb -batch-silent -iex "set auto-load safe-path /" --args shrinking $(POOL_SIZE) 2>/dev/null

.PHONY: clean

clean:
	-@rm -f shrinking