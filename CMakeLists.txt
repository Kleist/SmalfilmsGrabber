cmake_minimum_required(VERSION 2.8)

set(OPENCV_ROOT_PATH 
   /usr/local/Cellar/opencv/2.2
)
include_directories(
   ${OPENCV_ROOT_PATH}/include/opencv
)

link_directories(
   ${OPENCV_ROOT_PATH}/lib
)

add_executable(test opencvdemo.cpp)
add_executable(main main.cpp smalfilmsgrabber.cpp)

target_link_libraries(test opencv_core opencv_highgui opencv_imgproc)
target_link_libraries(main opencv_core opencv_highgui opencv_imgproc)
