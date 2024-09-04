# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\ql_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ql_autogen.dir\\ParseCache.txt"
  "ql_autogen"
  )
endif()
