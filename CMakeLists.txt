
cmake_minimum_required(VERSION 3.20)

project(NebulaRTC VERSION 2.0 LANGUAGES CXX)

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

add_library(nebulartc_core
    src/core/logger.cpp
)

add_library(nebulartc_sip
    src/sip/sip_parser.cpp
)

add_library(nebulartc_media
    src/media/media_session.cpp
)

add_library(nebulartc_network
    src/network/server.cpp
    src/network/session.cpp
)

add_executable(voip_server
    src/main.cpp
)

target_link_libraries(nebulartc_network PUBLIC
    nebulartc_core
    nebulartc_sip
)

target_link_libraries(voip_server PRIVATE
    nebulartc_core
    nebulartc_sip
    nebulartc_media
    nebulartc_network
    Boost::system
    Boost::thread
    OpenSSL::SSL
    OpenSSL::Crypto
)
