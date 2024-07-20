add_executable(factory
    src/contexts/float_context.cpp
    src/contexts/int_context.cpp
    src/interface.hpp
    src/main.cpp
)

target_link_libraries(factory PRIVATE fimpl)
