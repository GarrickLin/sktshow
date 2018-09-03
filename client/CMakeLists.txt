

add_library(sktshowClient sktimshow.cpp)
target_link_libraries(sktshowClient ${OpenCV_LIBS})

install(TARGETS sktshowClient
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(FILES sktimshow.hpp
        DESTINATION include)