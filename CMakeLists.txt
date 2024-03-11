cmake_minimum_required(VERSION 3.24)
project(Legemfest)

set(CMAKE_CXX_STANDARD 20)

add_executable(decodefest cppmain.cpp cppmain.h decodefest.cpp)

IF(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
   target_link_libraries(decodefest -L/usr/local/lib)
ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")

target_link_libraries(decodefest -lmedfest)

add_executable(dumpfestdata cppmain.cpp cppmain.h dumpfestdata.cpp)
target_link_libraries(dumpfestdata -lmedfest)

add_executable(copyfestdata copyfestdata.cpp cppmain.cpp cppmain.h)
target_link_libraries(copyfestdata -lmedfest)

add_executable(addtofest addtofest.cpp cppmain.cpp cppmain.h)
target_link_libraries(addtofest -lmedfest)

install(TARGETS decodefest dumpfestdata copyfestdata addtofest
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)
