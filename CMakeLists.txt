cmake_minimum_required(VERSION 3.26)
project(ALL_IECI)

set(CMAKE_CXX_STANDARD 17)

add_executable(ALL_IECI main.cpp
        config.cpp
        config.h
        ver_asignaturas.cpp
        connect_server.cpp
        verCursoLinux.cpp
        ver_todas_asignaturas.cpp)
target_link_libraries(ALL_IECI curl)

# Agrega la ubicación de los archivos de cabecera y bibliotecas de libcurl
include_directories(/usr/include/curl)
link_directories(/usr/lib/x86_64-linux-gnu)

