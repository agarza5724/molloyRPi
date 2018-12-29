
cmake_minimum_required(VERSION 2.8.9)
project (exploringPi)
find_package(Armadillo REQUIRED)
find_package(Boost REQUIRED)
find_package(dlib REQUIRED)
find_package(OpenCL REQUIRED)
include_directories(include)
file(GLOB SOURCES "source/*.cpp")
set(all_project_libs
	${ARMADILLO_LIBRARIES}
	${DLIB_LIBRARIES}
	${BOOST_LIBRARIES}
	${OPENCV_LIBRARIES}
	${OpenCL_LIBRARIES}
)
add_executable(exploringPi ${SOURCES})
target_link_libraries(exploringPi  ${all_project_libs} ${PROJECT_LINK_LIBS} )
