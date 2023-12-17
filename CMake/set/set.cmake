cmake_minimum_required(VERSION 3.10)
set(Var1 "This is Var1")
message(${Var1})

# 设置多个值
set(LISTVALUE a1 a2)
message(${LISTVALUE})

# $PATH
message($ENV{PATH})
set(ENV{CXX} "g++")
message($ENV{CXX})

#unset
unset(ENV{CXX})
message($ENV{CXX}) # error