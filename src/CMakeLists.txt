## src/CMakeLists.txt
## Stanisław Grams <sgrams@fmdx.pl>
##
## secpass.org
## © 2019

list (APPEND CMAKE_MODULE_PATH cmake)
set (CMAKE_CXX_STANDARD 17)

## src ext dependencies
find_library(LIQUIDDSP
    NAMES liquid
)

# add src subdirs
add_subdirectory (core)
#add_subdirectory (ui-nc) ## TODO: enable ncurses based ui
#add_subdirectory (ui-qt) ## TODO: enable Qt based ui
