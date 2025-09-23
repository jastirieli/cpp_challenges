cmake_minimum_required(VERSION 4.1.1)

if(POLICY CMP0115)
    cmake_policy(SET CMP0115 NEW)
endif()

project(politeia 
    VERSION 1.0.0 
    DESCRIPTION "Various C++ challenges"
    HOMEPAGE_URL "https://github.com/jastirieli/cppchallenges"
    LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Abordagem IF - mais simples para Makefiles/Ninja
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Configurando build Debug")
    add_compile_definitions(DEBUG)
    add_compile_options(-g -O0 -Wall -Wextra -Wpedantic -Werror)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Configurando build Release")
    add_compile_options(-O3 -Wall -DNDEBUG)
else()
    message(STATUS "Build type não especificado, usando padrão")
    add_compile_options(-O2 -Wall -Wextra)
endif()

add_subdirectory(src)
add_subdirectory(app)