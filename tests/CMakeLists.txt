include(CTest)

set(TEST_NAMES
    factory
    registry
)

foreach(TEST_NAME ${TEST_NAMES})
    add_subdirectory(${TEST_NAME})
    add_test(NAME test_${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
