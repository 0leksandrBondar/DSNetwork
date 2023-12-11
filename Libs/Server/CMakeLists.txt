cmake_minimum_required(VERSION 3.16)

set(SOURCE
        Server.cpp
        Server.h
)

add_library(Server ${SOURCE})

target_link_libraries(Server PUBLIC
        Socket
)