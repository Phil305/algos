set logging file gdb.log
set logging overwrite
set logging on

up 3

define hook-stop
    i lo
end
