#pragma once

template<auto Index, typename Type, typename... Tail>
struct _get_nth_type_inner;

template<typename Type, typename... Tail>
struct _get_nth_type_inner<0, Type, Tail...> {
	using type = Type;
};

template<auto Index, typename T, typename... Tail>
struct _get_nth_type_inner {
	using type = typename _get_nth_type_inner<Index - 1, Tail...>::type;
};

template<auto Index, typename... Tail>
struct _get_nth_type {
	using type = typename _get_nth_type_inner<Index, Tail...>::type;
};

template<auto Index>
struct _get_nth_type<Index> {};

template<typename... Items>
struct type_list {
	template<template<typename> class Wrapper>
	using wrap = type_list<Wrapper<Items>...>;

	template<auto Index>
	using get = typename _get_nth_type<Index, Items...>::type;

	template<template<typename...> class U>
	using to = U<Items...>;
};
