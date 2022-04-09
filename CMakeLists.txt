cmake_minimum_required(VERSION 3.20)
project(feup_da_PackageDelivery)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/dataset")

add_executable(feup_da_PackageDelivery src/main.cpp
        src/ExpressDelivery.cpp src/ExpressDelivery.h src/NormalDelivery.cpp src/NormalDelivery.h
        src/Driver.cpp src/Driver.h src/Company.cpp src/Company.h src/LoadData.cpp src/LoadData.h)
