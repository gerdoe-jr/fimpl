#pragma once

#include <array>
#include <cstring>
#include <tuple>

#include "compile_time_str.hpp"
#include "type_list.hpp"

template<typename X, typename V, typename F>
constexpr auto first_entry_id(X &container, V &key, F comp) {
	for(typename X::size_type counter = 0; counter < container.size(); ++counter)
		if(comp(container[counter], key) == 0)
			return counter;

	return container.size();
}

template<compile_time_str Name, typename Interface>
struct named_interface {
	using interface = Interface;
	constexpr static compile_time_str name = Name;
};

template<typename Interface, compile_time_str... Names>
class implementation_registry;

template<typename Interface>
class implementation_factory {
	template<typename I, compile_time_str... Tn>
	friend class implementation_registry;

protected:
	implementation_factory() {}
	~implementation_factory() {}

protected:
	template<compile_time_str Name>
	Interface *create_instance();
};

template<typename Interface, compile_time_str... Names>
class implementation_registry {
	constexpr static std::array<const char *, sizeof...(Names)> names = {Names.data...};
	constexpr static implementation_factory<Interface> factory = {};

	std::array<Interface *, sizeof...(Names)> impls = {};

public:
	template<compile_time_str Name>
	Interface *get() {
		constexpr auto id = first_entry_id(names, Name.data, std::strcmp);

		if(impls[id] == nullptr)
			impls[id] = factory.template create_instance<Name>();

		return impls[id];
	}
};

template<named_interface... NamedInterfaces>
class interface_registry {
	using interface_list = type_list<typename decltype(NamedInterfaces)::interface...>;

	constexpr static std::array<const char *, sizeof...(NamedInterfaces)> names = {NamedInterfaces.name.data...};
	interface_list::template wrap<implementation_registry>::template to<std::tuple> impls;

public:
	template<typename Interface>
	implementation_registry<Interface> &get_registry() {
		return std::get<implementation_registry<Interface>>(impls);
	}

	template<compile_time_str Name, typename Interface>
	implementation_registry<Interface> &get_registry() {
		return std::get<first_entry_id(names, Name.data, std::strcmp)>(impls);
	}
};

#define fimpl_add(type) \
	named_interface<#type, type> {}

#define fimpl_define_impl(name, interface) \
	template<> \
	template<> \
	interface *implementation_factory<interface>::create_instance<name>
