cmake_minimum_required(VERSION 3.20)
project(feup_da_PackageDelivery)

set(CMAKE_CXX_STANDARD 14)

add_executable(feup_da_PackageDelivery src/main.cpp src/order.cpp src/order.h src/ExpressDelivery.cpp src/ExpressDelivery.h src/NormalDelivery.cpp src/NormalDelivery.h)
