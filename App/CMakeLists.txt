cmake_minimum_required(VERSION 3.16)

set(SOURCE main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} PUBLIC
        wsock32
        ws2_32
        Socket
)