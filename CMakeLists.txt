cmake_minimum_required(VERSION 3.16)
project(urbanease LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/headers)

set(SOURCES
    src/main.cpp

    src/stakeholder/person.cpp
    src/stakeholder/employee.cpp
    src/stakeholder/manager.cpp

    src/stores/coordinates.cpp
    src/stores/store.cpp

    src/analytics/analytics.cpp

    src/cluster/cluster.cpp
    src/cluster/subcluster.cpp

    src/report/report.cpp
    src/report/forecast.cpp

    src/helper/helper.cpp

    src/visualization/visual.cpp
)

add_executable(urbanease ${SOURCES})