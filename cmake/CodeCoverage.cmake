if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    message(STATUS "Adding measuring code coverage for ${CMAKE_CXX_COMPILER_ID} compiler")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} --coverage")
    set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} --coverage")
elseif (CMAKE_CXX_COMPILER_ID MATCHES Clang OR CMAKE_CXX_COMPILER_ID MATCHES AppleClang)
    message(STATUS "Adding measuring code coverage for ${CMAKE_CXX_COMPILER_ID} compiler")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-instr-generate -fcoverage-mapping")
    set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fprofile-instr-generate -fcoverage-mapping")
endif ()
