[ Load Executable File ]

$ gdb EXEC_FILE
$ gdb --args EXEC_FILE [ARGUMENT...]


[ Search Path ]

# source file
(gdb) dir PATH_NAME

# object file
(gdb) path PATH_NAME


[ List Sourde Code ]

(gdb) list
(gdb) list LINE_NUMBER
(gdb) list FILE:LINE_NUMBER
(gdb) list FUNCTION

# current linu number
(gdb) where
(gdb) info line


[ Break Point ]

(gdb) break LINE_NUMBER
(gdb) break FILE:LINE_NUMBER
(gdb) break FUNCTION

(gdb) clear LINE_NUMBER
(gdb) clear FILE:LINE_NUMBER
(gdb) clear FUNCTION
(gdb) delete BREAK_POINT

# list all break points
(gdb) info break

(gdb) disable BREAK_POINT
(gdb) enable BREAK_POINT

# break with contition
(gdb) break SOMEWHERE if VAR==VALUE
(gdb) cond BREAK_POINT VAR==VALUE


[ Run Program ]

(gdb) run
(gdb) continue
(gdb) kill

# step in
(gdb) step

# step over
(gdb) next

# exit a while/for loop
(gdb) until

# exit a subroutine
(gdb) finish
(gdb) return

# show backtrace of subroutines
(gdb) bt

# exit GDB
(gdb) quit


[ Watch Variables ]

# information
(gdb) info var
(gdb) info func
(gdb) info thread
(gdb) info sources

# arguments
(gdb) show args
(gdb) show dir

# monitor variables
(gdb) print VAR
(gdb) print &VAR
(gdb) print *VAR

# set value
(gdb) print VAR=VALUE
(gdb) set variable VAR=VALUE

# monitor variables
(gdb) display
(gdb) display VAR
(gdb) undisplay
(gdb) undisplay NUMBER

# dump memory
(gdb) x/32xb ADDRESS


[ Stack ]

(gdb) backtrace
(gdb) frame


