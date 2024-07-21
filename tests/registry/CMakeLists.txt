add_executable(registry
    src/contexts/float_context.cpp
    src/contexts/int_context.cpp
    src/interface.hpp
    src/main.cpp
)

target_link_libraries(registry PRIVATE fimpl)
