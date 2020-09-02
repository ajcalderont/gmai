set logging file ../info.cfg

# Granularity extraction
break granularity.c:main:break_01
run
break mmap thread 1
continue
set logging overwrite off
set logging on
printf "GRN %d\n", (main::pool_size/main::iteration)
set logging off
set variable main::flag = 1
delete

# Finalization
continue
quit