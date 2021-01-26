cmake_minimum_required(VERSION 3.17)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

add_executable(philosophers
        main.c error.c free_data.c print_state.c prm_setup.c init_arrays.c dlist.c philo_one.h)

set(CMAKE_CXX_FLAGS "-pthread")