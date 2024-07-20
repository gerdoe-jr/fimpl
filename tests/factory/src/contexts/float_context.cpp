#include <fimpl/factory.hpp>

#include "../interface.hpp"

class float_context : public icontext {
public:
	int return_something() override {
		return 24.f;
	}
};

template<> icontext *create_instance<"float">() {
    return new float_context;
}
