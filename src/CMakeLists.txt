## src/CMakeLists.txt
## Stanislaw Grams <stanislawgrams@gmail.com>
##
## 2021, fmdx.pl
## For license information, see LICENSE

list (APPEND CMAKE_MODULE_PATH cmake)
set (CMAKE_CXX_STANDARD 20)

## src ext dependencies
find_library (LIQUIDDSP NAMES liquid)

find_package(nlohmann_json 3.2.0 REQUIRED)

# add src subdirs
add_subdirectory (core)
#add_subdirectory (ui-nc) ## TODO: enable ncurses based ui
#add_subdirectory (ui-qt) ## TODO: enable Qt based ui
