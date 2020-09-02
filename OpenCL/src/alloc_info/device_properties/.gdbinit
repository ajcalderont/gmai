set logging file ../info.cfg

# Device properties extraction
break device_properties.c:main:break_01
run
set logging overwrite on
set logging on
printf "DEV %s\n", main::device_name
printf "DRV %s\n", main::driver_version
set logging off
delete

# Finalization
continue
quit