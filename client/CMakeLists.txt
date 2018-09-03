

add_library(sktshowClient SHARED sktimshow.cpp)
target_link_libraries(sktshowClient ${OpenCV_LIBS})
if(WIN32)
    target_link_libraries(sktshowClient ws2_32)
endif()

install(TARGETS sktshowClient
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(FILES sktimshow.hpp
        DESTINATION include)