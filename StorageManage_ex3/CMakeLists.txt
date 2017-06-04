# /**
#  * 
#  * @author:		胡文博
#  * @email:		huwenbo@mail.dlut.edu.cn
#  * @dateTime:		2017-06-04 15:40:45
#  * @description: 	
#  */
project(StorageManage_ex3)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
aux_source_directory(./ SRC_LIST)
add_executable( ${PROJECT_NAME} ${SRC_LIST} )
# install (TARGETS max DESTINATION bin)
