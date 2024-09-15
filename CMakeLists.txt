cmake_minimum_required(VERSION 3.16)

project(object LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление исполняемых файлов
add_executable(object main.cpp
    file_handler.cpp file_handler.h
    group_sort.cpp group_sort.h
    object.cpp object.h
    ${SQLITE_SOURCES})  # Добавление исходников SQLite

# Указание директорий для заголовочных файлов
include_directories(
    ${Boost_INCLUDE_DIRS}             # Подключение заголовков Boost
    ${SQLITE_MODERN_CPP_INCLUDE_DIR}
    ${SQLITE_INCLUDE_DIR}
    ${CROW_INCLUDE_DIR}
    ${ASIO_INCLUDE_DIR}
)

# Линковка библиотеки SQLite (если требуется, добавьте соответствующую библиотеку)
# target_link_libraries(object PRIVATE ${SQLITE_LIBRARY})

# Линковка библиотек Boost (если вы используете какие-либо компоненты)
target_link_libraries(object PRIVATE ${Boost_LIBRARIES})

include(GNUInstallDirs)
install(TARGETS object
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
