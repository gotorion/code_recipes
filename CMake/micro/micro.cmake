cmake_minimum_required(VERSION 3.10)
macro(Test myVar)
    set(myVar "new value") #创建了新的myVar变量
    message("argument: ${myVar}")
endmacro()

set(myVar "First value")
message(${myVar})
Test("value")
message("myVar: ${myVar}")