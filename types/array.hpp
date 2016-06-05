#ifndef TYPES_ARRAY_HPP
#define TYPES_ARRAY_HPP

#include <yasli/yasli.hpp>
#include <array>

namespace yasli
{
	template<class Archive, class T, size_t N> inline
	std::enable_if_t <std::is_arithmetic<T>::value, void>
		save(Archive & a, std::array<T, N> const & arr)
	{
		for (auto & i : arr)
			a << i;
	}
	template<class Archive, class T, size_t N> inline
	std::enable_if_t <std::is_arithmetic<T>::value, void>
		load(Archive & a, std::array<T, N> & arr)
	{
		for (auto & i : arr)
			a >> i;
	}
}
#endif // !TYPES_ARRAY_HPP
