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

file(GLOB hrds ./*.hpp)
file(GLOB srcs ./*.cpp)
add_executable(http_service ${hrds} ${srcs})
if(APPLE)
    target_link_libraries(http_service  ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY})
else()
    target_link_libraries(http_service Boost::thread ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY})
endif()
