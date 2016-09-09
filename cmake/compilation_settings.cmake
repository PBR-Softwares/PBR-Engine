##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program; If not, see <http://www.gnu.org/licenses/>.
##
## Copyright (C) 2016 PBR-Softwares (contact@pbr-softwares.com)
##

FUNCTION(CONFIGURE_COMPILATION)

    IF (CMAKE_COMPILER_IS_GNUCXX)

        # Warnings flags

        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wctor-dtor-privacy)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wnoexcept)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wnon-virtual-dtor)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Weffc++)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wstrict-null-sentinel)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wold-style-cast)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Woverloaded-virtual)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wno-pmf-conversions)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsign-promo)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wmultiple-inheritance)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wvirtual-inheritance)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wdouble-promotion)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wmissing-include-dirs)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wswitch-default)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wswitch-enum)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-attribute=pure)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-attribute=const)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-attribute=noreturn)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-final-types)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-final-methods)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-override)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wduplicated-cond)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wfloat-equal)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wzero-as-null-pointer-constant)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wuseless-cast)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wconversion)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wlogical-op)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wmissing-declarations)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Winline)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wshadow)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wall)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wextra)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -std=c++14)


        # Debug flags

        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-g3>)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-ggdb3>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=address>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=thread>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=leak>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=undefined>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=shift>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=integer-divide-by-zero>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=unreachable>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=vla-bound>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=null>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=return>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=signed-integer-overflow>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=bounds>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=alignment>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=object-size>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=float-divide-by-zero>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=float-cast-overflow>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=nonnull-attribute>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=returns-nonnull-attribute>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=bool>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=enum>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-fsanitize=vptr>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-pg>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:--coverage>)

        # Release flags

        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:RelWithDebInfo>:-O2>)
        #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:RelWithDebInfo>:-O3>)
        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:RelWithDebInfo>:-Ofast>)

    ELSEIF(CMAKE_CXX_COMPILER_ID MATCHES "Clang")

        TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -std=c++14)

        ## TODO Clang options.

    ENDIF()

    ## TODO Visual Studio and others.

ENDFUNCTION()
