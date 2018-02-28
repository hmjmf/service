
find_package(Boost REQUIRED COMPONENTS thread system)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()


INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})



add_executable(echo_service_tcp echo_service_tcp.cpp)
target_link_libraries(echo_service_tcp ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY})







