cmake_minimum_required(VERSION 3.10)
list(APPEND port p1 p2 p3)
message(${port})

# 获取长度,把长度写入到len变量
list(LENGTH port len)
message(${len})

#查找
list(FIND port p2 index)
message(${index})

#删除
list(REMOVE_ITEM port p1)
message(${port})

#添加
list(INSERT port 1 p5)
message(${port})

#反转
list(REVERSE port)
message(${port})

#排序
list(SORT port)
message(${port})