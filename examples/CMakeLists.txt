
include_directories(${CMAKE_CURRENT_LIST_DIR}/../client)

add_executable(client_example client_example.cpp)
target_link_libraries(client_example sktshowClient)