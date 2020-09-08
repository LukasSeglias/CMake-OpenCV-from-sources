add_executable(exampleUsingOpenCV app.cpp)

set(BUILD_SHARED_LIBS "${LINK_OPENCV_SHARED_LIB}")
find_package(OpenCV REQUIRED CONFIG)

target_include_directories(exampleUsingOpenCV
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${OpenCV_INCLUDE_DIRS}
        )
target_link_libraries(exampleUsingOpenCV PRIVATE ${OpenCV_LIBS})

configure_file(opencv.png    ${CMAKE_CURRENT_BINARY_DIR}/opencv.png     COPYONLY)

# Copy OpenCV-Library files (like DLLs) to the location of the executable in order for them to be found when running it.
# This is done after the build of the executable.
if(LINK_OPENCV_SHARED_LIB)
    foreach(OpenCV_LIB ${OpenCV_LIBS})
        add_custom_command(TARGET exampleUsingOpenCV POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E echo "Copy $<TARGET_FILE:${OpenCV_LIB}> to $<TARGET_FILE_DIR:exampleUsingOpenCV>"
                COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${OpenCV_LIB}> $<TARGET_FILE_DIR:exampleUsingOpenCV>
                )
    endforeach()
endif(LINK_OPENCV_SHARED_LIB)
