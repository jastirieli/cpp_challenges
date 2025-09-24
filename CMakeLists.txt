cmake_minimum_required(VERSION 4.1.1)

if(POLICY CMP0115)
    cmake_policy(SET CMP0115 NEW)
endif()

project(Cpp_Challenges  
    VERSION 1.0.0 
    DESCRIPTION "Various C/C++ and Fortran challenges"
    HOMEPAGE_URL "https://github.com/jastirieli/cppchallenges"
    LANGUAGES C CXX Fortran)

# Verificar compilador Fortran
if(NOT CMAKE_Fortran_COMPILER)
    message(FATAL_ERROR "❌ Compilador Fortran não encontrado! Instale gfortran.")
endif()

message(STATUS "🔧 Compilador Fortran: ${CMAKE_Fortran_COMPILER}")
message(STATUS "🔧 Versão: ${CMAKE_Fortran_COMPILER_VERSION}")

include(CheckFortranCompilerFlag)

# Testar suporte a F2023
check_fortran_compiler_flag("-std=f2023" HAS_FORTRAN_2023)

if(HAS_FORTRAN_2023)
    message(STATUS "🎉 Compilador suporta Fortran 2023!")
    set(CMAKE_Fortran_STANDARD 2023)
    set(FORTRAN_STANDARD_USED "2023")
else()
    message(STATUS "⚠️  Fortran 2023 não suportado, usando 2018")
    set(CMAKE_Fortran_STANDARD 2018)
    set(FORTRAN_STANDARD_USED "2018")
endif()

set(CMAKE_Fortran_STANDARD_REQUIRED ON)
set(CMAKE_Fortran_EXTENSIONS OFF)

message(STATUS "🔧 Usando Fortran Standard: ${FORTRAN_STANDARD_USED}")

# Política Fortran
if(POLICY CMP0079)
    cmake_policy(SET CMP0079 NEW)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 🔥 CORREÇÃO: Flags separadas corretamente
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "🔧 Configurando build Debug")
    add_compile_definitions(DEBUG)
    
    # 🔧 CORREÇÃO: Flags separadas para cada linguagem
    add_compile_options(
        "$<$<COMPILE_LANGUAGE:CXX>:-g>"
        "$<$<COMPILE_LANGUAGE:CXX>:-O0>"
        "$<$<COMPILE_LANGUAGE:CXX>:-Wall>"
        "$<$<COMPILE_LANGUAGE:CXX>:-Wextra>"
        "$<$<COMPILE_LANGUAGE:CXX>:-Wpedantic>"
        "$<$<COMPILE_LANGUAGE:CXX>:-Werror>"
        
        "$<$<COMPILE_LANGUAGE:Fortran>:-g>"
        "$<$<COMPILE_LANGUAGE:Fortran>:-O0>"
        "$<$<COMPILE_LANGUAGE:Fortran>:-Wall>"
        "$<$<COMPILE_LANGUAGE:Fortran>:-Wextra>"
        "$<$<COMPILE_LANGUAGE:Fortran>:-fcheck=all>"
    )
    
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "🔧 Configurando build Release")
    add_compile_definitions(NDEBUG)
    
    add_compile_options(
        "$<$<COMPILE_LANGUAGE:CXX>:-O3>"
        "$<$<COMPILE_LANGUAGE:CXX>:-Wall>"
        
        "$<$<COMPILE_LANGUAGE:Fortran>:-O3>"
        "$<$<COMPILE_LANGUAGE:Fortran>:-Wall>"
    )
    
else()
    message(STATUS "🔧 Build type não especificado, usando padrão")
    
    # 🔧 CORREÇÃO: Especificar build type padrão
    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build" FORCE)
    endif()
    
    add_compile_options(
        "$<$<COMPILE_LANGUAGE:CXX>:-O2>"
        "$<$<COMPILE_LANGUAGE:CXX>:-Wall>"
        "$<$<COMPILE_LANGUAGE:CXX>:-Wextra>"
        
        "$<$<COMPILE_LANGUAGE:Fortran>:-O2>"
        "$<$<COMPILE_LANGUAGE:Fortran>:-Wall>"
        "$<$<COMPILE_LANGUAGE:Fortran>:-Wextra>"
    )
endif()

# 🔧 CORREÇÃO ALTERNATIVA: Usar target_compile_options (mais moderno)
# Isso será aplicado nos targets específicos

# Resumo final
message(STATUS "")
message(STATUS "===========================================")
message(STATUS "✅ CONFIGURAÇÃO FINAL DO PROJETO")
message(STATUS "===========================================")
message(STATUS "📋 Projeto: ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "🔧 C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "🔧 Fortran Standard: ${FORTRAN_STANDARD_USED}")
message(STATUS "🔧 Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "🔧 Compilador C++: ${CMAKE_CXX_COMPILER}")
message(STATUS "🔧 Compilador Fortran: ${CMAKE_Fortran_COMPILER}")
message(STATUS "===========================================")
message(STATUS "")

add_subdirectory(src)
add_subdirectory(app)