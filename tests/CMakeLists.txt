include(thirdparty/googletest.cmake)

option(INTEGRATION_TEST "Enable integration test" ON)
if (INTEGRATION_TEST)
    add_subdirectory(integration)
endif ()

option(UNIT_TEST "Enable unit test" ON)
if (INTEGRATION_TEST)
    add_subdirectory(unit)
endif ()