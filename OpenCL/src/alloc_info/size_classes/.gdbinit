set logging file ../info.cfg

# Size classes detection
break size_classes.c:main:break_01
run
break mmap thread 1
continue
set logging overwrite off
set logging on
if main::superior_size == main::pool_size
    printf "SCD %d\n", 0
else
    printf "SCD %d\n", 1
end
set logging off
delete

# Finalization
continue
quit