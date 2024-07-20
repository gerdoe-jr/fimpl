#include <cassert>
#include <iostream>

#include <fimpl/factory.hpp>

#include "interface.hpp"

#define ASSERT(expr) \
    { \
        std::cout << "[" #expr "] is running..." << std::endl; \
        assert(expr); \
        std::cout << "[" #expr "] have been passed successfully!" << std::endl; \
    };

int main() {
    icontext *float_instance = create_instance<"float", icontext>();
    icontext *int_instance = create_instance<"int", icontext>();

    ASSERT(float_instance->return_something() == 24); 
    ASSERT(int_instance->return_something() == 42);
}
