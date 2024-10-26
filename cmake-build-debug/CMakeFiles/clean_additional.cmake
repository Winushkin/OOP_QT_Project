# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/OOP_QT_Project_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/OOP_QT_Project_autogen.dir/ParseCache.txt"
  "OOP_QT_Project_autogen"
  )
endif()
