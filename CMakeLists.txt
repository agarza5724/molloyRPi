cmake_minimum_required(VERSION 2.8.9)
project (exploringPi)
include_directories(include)
include_directories(${ARMADILLO_INCLUDE_DIRS})
find_package(Armadillo REQUIRED)
file(GLOB SOURCES "source/*.cpp")
set(all_project_libs
	${ARMADILLO_LIBRARIES}
	${DLIB_LIBRARIES}
	${BOOST_LIBRARIES}
	${OPENCV_LIBRARIES}
)
#screwing with git again
add_executable(exploringPi ${SOURCES})
target_link_libraries(exploringPi  ${all_project_libs} ${PROJECT_LINK_LIBS} )
