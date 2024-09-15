cmake_minimum_required(VERSION 3.16)

project(object LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(object main.cpp
    file_handler.cpp file_handler.h
    group_sort.cpp group_sort.h
    object.cpp object.h
    ${SQLITE_SOURCES})  


include_directories(
    ${Boost_INCLUDE_DIRS}             
    ${SQLITE_MODERN_CPP_INCLUDE_DIR}
    ${SQLITE_INCLUDE_DIR}
    ${CROW_INCLUDE_DIR}
    ${ASIO_INCLUDE_DIR}
)


# target_link_libraries(object PRIVATE ${SQLITE_LIBRARY})


target_link_libraries(object PRIVATE ${Boost_LIBRARIES})

include(GNUInstallDirs)
install(TARGETS object
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
