cmake_minimum_required(VERSION 3.1)

project(FailTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(src)

set(PROJECT_SRC src/main.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

get_target_property(ALL_SOURCE ${PROJECT_NAME} SOURCES)

find_program(CPPCHECK_EXECUTABLE NAMES cppcheck)

add_custom_target(
        cppcheck
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${CPPCHECK_EXECUTABLE}
        --enable=warning,performance,portability,information
        --suppress=missingIncludeSystem
        --std=c++14
        --verbose
        --quiet
        ${ALL_SOURCE}
)
find_program(PVS_STUDIO_EXECUTABLE NAMES pvs-studio)
foreach (source_file ${ALL_SOURCE})
        add_custom_target(
                preprocessor
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                COMMAND ${CMAKE_CXX_COMPILER}
                ${CMAKE_CXX_FLAGS} -E -o "${source_file}.i" ${source_file}
        )
        add_custom_target(
                pvs
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                COMMAND ${PVS_STUDIO_EXECUTABLE}
                --cfg
                "${CMAKE_CURRENT_SOURCE_DIR}/cfg/PVS-Studio.cfg"
                --output-file
                PVS-Studio.log
                --i-file "${source_file}.i"
                --source-file
                ${source_file}
        )
endforeach(source_file)

add_dependencies(pvs preprocessor)
