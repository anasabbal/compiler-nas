cmake_minimum_required(VERSION 3.23)
project(assembly_do C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_ASM_SOURCE_FILE_EXTENSIONS index.asm)

set_source_files_properties(${CMAKE_ASM_SOURCE_FILE_EXTENSIONS} PROPERTIES LANGUAGE ASM_NASM)
add_executable(assembly_do main.c memory.h common.h object.h chunk.h value.h table.h scanner.h scanner.c table.c)
