#include <fimpl/registry.hpp>

#include "../interface.hpp"

class float_context : public icontext {
public:
	int return_something() override {
		return 24.f;
	}
};

fimpl_define_impl("float", icontext)() {
	return new float_context;
}
