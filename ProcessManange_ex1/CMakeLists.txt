# /**
#  * @file:		CMakeLists.txt
#  * @author:		胡文博
#  * @email:		huwenbo@mail.dlut.edu.cn
#  * @dateTime:		2017-04-30 12:31:03
#  * @description: 	
#  */
project(ProcessManage_ex1)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
aux_source_directory(./ SRC_LIST)
add_executable( "max" max.cpp )
add_executable( "min" min.cpp )
add_executable( "average" average.cpp )
add_executable( "shell" shell.cpp )
add_executable( "forkTest1" forkTest1.cpp )
add_executable( "forkTest2" forkTest2.cpp )
# install (TARGETS max DESTINATION bin)
# install (TARGETS min DESTINATION bin)
# install (TARGETS average DESTINATION bin)
