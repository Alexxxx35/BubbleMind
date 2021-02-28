cmake_minimum_required(VERSION 3.17)
project(bubble_mind)

set(CMAKE_CXX_STANDARD 11)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
include_directories(..)
add_executable(bubble_mind main.cpp AbstractEntity.hh AbstractEntity.cpp ISerializable.hh CircleEntity.h CircleEntity.cpp EntityFactory.h EntityFactory.cpp WindowManager.h WindowManager.cpp Scene.hh Scene.cpp TimeManager.hh TimeManager.cpp ISerializable.hh IObservable.hh IObserver.hh)
target_link_libraries(bubble_mind CONAN_PKG::sfml)