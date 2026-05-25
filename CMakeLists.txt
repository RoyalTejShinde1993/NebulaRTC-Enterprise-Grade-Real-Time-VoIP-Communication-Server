
cmake_minimum_required(VERSION 3.20)

project(VoIPRTCServer
    VERSION 2.0.0
    DESCRIPTION "Enterprise Grade VoIP Real-Time Communication Server"
    LANGUAGES CXX)

option(ENABLE_CPP17 "Enable C++17" OFF)
option(ENABLE_CPP20 "Enable C++20" ON)
option(ENABLE_CPP23 "Enable C++23" OFF)
option(ENABLE_CPP26 "Enable C++26" OFF)

if(ENABLE_CPP17)
    set(CMAKE_CXX_STANDARD 17)
elseif(ENABLE_CPP20)
    set(CMAKE_CXX_STANDARD 20)
elseif(ENABLE_CPP23)
    set(CMAKE_CXX_STANDARD 23)
elseif(ENABLE_CPP26)
    set(CMAKE_CXX_STANDARD 26)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system thread)
find_package(OpenSSL REQUIRED)

include_directories(include)

add_executable(voip_server
    src/main.cpp
    src/server.cpp
    src/session.cpp
    src/logger.cpp
)

target_link_libraries(voip_server PRIVATE
    Boost::system
    Boost::thread
    OpenSSL::SSL
    OpenSSL::Crypto
)

if(MSVC)
    target_compile_options(voip_server PRIVATE /W4)
else()
    target_compile_options(voip_server PRIVATE -Wall -Wextra -pedantic)
endif()
