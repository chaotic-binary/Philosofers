cmake_minimum_required(VERSION 3.16)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

add_executable(philosophers
		main.c act.c print_state.c prm_setup.c init.c time_utils.c philo_three.h free_data.c num_to_buf.c)

set(CMAKE_CXX_FLAGS "-pthread")
