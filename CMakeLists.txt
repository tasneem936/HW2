cmake_minimum_required(VERSION 3.15)
project(HW2)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW2 main.cpp DynamicArray.h BeverageItem.cpp BeverageItem.h Customer.cpp Customer.h BookkeepingEntry.cpp BookkeepingEntry.h BeverageStore.cpp BeverageStore.h)