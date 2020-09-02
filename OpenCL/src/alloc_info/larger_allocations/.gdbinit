set logging file ../info.cfg

# Larger allocations multiple
break larger_allocations.c:main:break_01
run
break mmap thread 1
continue
set logging overwrite off
set logging on
printf "LGM %d\n", len - main::pool_size
set logging off
delete

# Finalization
continue
quit