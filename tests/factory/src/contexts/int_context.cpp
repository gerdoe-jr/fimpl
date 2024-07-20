#include <fimpl/factory.hpp>

#include "../interface.hpp"

class int_context : public icontext {
public:
	int return_something() override {
		return 42;
	}
};

template<> icontext *create_instance<"int">() {
    return new int_context;
}
