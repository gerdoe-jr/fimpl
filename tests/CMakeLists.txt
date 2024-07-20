include(CTest)

add_subdirectory(factory)

add_test(NAME test_factory COMMAND factory)
