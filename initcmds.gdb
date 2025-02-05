set logging on
set logging overwrite
set logging file gdb.log

up 3

define hook-stop
    i lo
end
