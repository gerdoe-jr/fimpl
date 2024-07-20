#include <iostream>

#include <fimpl/factory.hpp>

#include "interface.hpp"

int main() {
    icontext *float_instance = create_instance<"float", icontext>();
    icontext *int_instance = create_instance<"int", icontext>();

    std::cout << "float instance says: I'm " << float_instance->return_something() << std::endl;
    std::cout << "int instance says: And I'm " << int_instance->return_something() << std::endl;
}
