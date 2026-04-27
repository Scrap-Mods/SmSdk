cmake_minimum_required(VERSION 3.10)
project(MinHook)

add_library(MinHook STATIC
	src/hook.c
	src/buffer.c
	src/trampoline.c
	src/hde/hde32.c
	src/hde/hde64.c
)

target_include_directories(MinHook PUBLIC include)