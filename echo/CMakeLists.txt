
find_package(Boost REQUIRED COMPONENTS thread system)
find_package(Glog REQUIRED)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

if(NOT Glog_FOUND)
    message(FATAL_ERROR "Could not find Glog!")
endif()


INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})



add_executable(echo_service_tcp echo_service_tcp.cpp)
target_link_libraries(echo_service_tcp ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY} glog::glog)







