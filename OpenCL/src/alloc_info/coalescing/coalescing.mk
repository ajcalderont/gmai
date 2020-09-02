GRANULARITY := $$(awk '/GRN/ {print $$2}' ../info.cfg)

coalescing:
	-@$(CC) -g coalescing.c -o coalescing -l OpenCL

get_alloc_info: coalescing
	-@gdb -batch-silent -iex "set auto-load safe-path /" --args coalescing $(GRANULARITY) 2>/dev/null

.PHONY: clean

clean:
	-@rm -f coalescing