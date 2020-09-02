set logging file ../info.cfg

# Pool size extraction
break pool_size.c:main:break_01
run
break mmap thread 1
continue
set logging overwrite off
set logging on
printf "PSZ %d\n", len
set logging off
set variable main::pool_size = len
delete

# Finalization
continue
quit