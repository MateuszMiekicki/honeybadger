include(third_party/googletest.cmake)

option(INTEGRATION_TESTS "Enable integration tests" ON)
if (INTEGRATION_TESTS)
    add_subdirectory(integration_tests)
endif ()

option(UNIT_TESTS "Enable unit tests" ON)
if (UNIT_TESTS)
    add_subdirectory(unit_tests)
endif ()