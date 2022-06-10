## CMakeLists.txt
## Stanislaw Grams <stanislawgrams@gmail.com>
##
## 2021, fmdx.pl
## For license information, see LICENSE

cmake_minimum_required (VERSION 3.20)
project (sdr2)

set (PACKAGE ${PROJECT_NAME})

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
    add_definitions (-Wall)
    add_definitions (-Wextra)
    add_definitions (-fmodules-ts) ## until C++23 triggers this flag
endif ()

set (CMAKE_CXX_STANDARD 23)

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Gather all src files from subdirs
function (add_src_files list)
    get_property (is_defined GLOBAL PROPERTY SRC_LIST DEFINED)
    if (NOT is_defined)
        define_property (GLOBAL PROPERTY ${list}
            BRIEF_DOCS "List of source files"
            FULL_DOCS "List of source files to be compiled in one library")
    endif ()
    # make absolute paths
    set (SRC)
    foreach (s IN LISTS ARGN)
        if (NOT IS_ABSOLUTE "${s}")
            get_filename_component (s "${s}" ABSOLUTE)
        endif ()
        list (APPEND SRC "${s}")
    endforeach ()
    # append to global list
    set_property (GLOBAL APPEND PROPERTY ${list} "${SRC}")
endfunction (add_src_files)

add_subdirectory (src)
