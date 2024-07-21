#include <cassert>
#include <iostream>

#include <fimpl/registry.hpp>

#include "interface.hpp"

#define ASSERT(expr) \
	{ \
		std::cout << "[" #expr "] is running..." << std::endl; \
		assert(expr); \
		std::cout << "[" #expr "] have been passed successfully!" << std::endl; \
	};

static implementation_registry<icontext, "float", "int"> impl_registry;

int main() {
	icontext *float_instance = impl_registry.get<"float">();
	icontext *int_instance = impl_registry.get<"int">();

	ASSERT(float_instance->return_something() == 24);
	ASSERT(int_instance->return_something() == 42);
}
