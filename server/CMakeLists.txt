
add_executable(sktshowServer main.cpp)
target_link_libraries(sktshowServer ${OpenCV_LIBS})

install(TARGETS sktshowServer
        RUNTIME DESTINATION bin)