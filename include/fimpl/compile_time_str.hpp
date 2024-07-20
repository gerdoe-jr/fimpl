#pragma once

#include <algorithm>
#include <cstddef>

/// pretty common c++20 solution for compile-time strings

template<std::size_t N>
struct compile_time_str {
	char data[N]{};

	consteval compile_time_str(const char (&str)[N]) {
		std::copy_n(str, N, data);
	}

	consteval bool operator==(const compile_time_str<N> str) const {
		return std::equal(str.data, str.data + N, data);
	}

	template<std::size_t M>
	consteval bool operator==(const compile_time_str<M> s) const {
		return false;
	}
};
