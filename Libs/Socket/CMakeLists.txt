cmake_minimum_required(VERSION 3.16)

set(SOURCE
        AbstractSocket.cpp
        AbstractSocket.h
        TCPSocket.cpp
        TCPSocket.h
        UDPSocket.cpp
        UDPSocket.h
)

add_library(Socket ${SOURCE})

target_include_directories(Socket PUBLIC ./)

