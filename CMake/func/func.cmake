cmake_minimum_required(VERSION 3.10)

function(MYFUNC FirstArg)
    message("MyFunc Name: ${CMAKE_CURRENT_FUNCTION}")
    message("FirstArg ${FirstArg}")
    set(FirstArg "New value")
    message("FirstArg ${FirstArg}")
    message("ARGV0 ${ARGV0}")
    message("ARGV1 ${ARGV1}")
    message("ARGV2 ${ARGV2}")
endfunction()

set(Var "init value")
MyFunc(${Var})