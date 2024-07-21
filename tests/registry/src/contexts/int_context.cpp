#include <fimpl/registry.hpp>

#include "../interface.hpp"

class int_context : public icontext {
public:
	int return_something() override {
		return 42;
	}
};

fimpl_define_impl("int", icontext)() {
	return new int_context;
}
