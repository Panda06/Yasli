#ifndef TYPES_VECTOR_HPP
#define TYPES_VECTOR_HPP

#include <yasli/yasli.hpp>

#include <vector>
namespace yasli
{
	template<class Archive, class T, class A>
	std::enable_if_t <std::is_arithmetic<T>::value, void>
		save(Archive & a, std::vector<T, A> const & vec)
	{
		a << vec.size();
		for (auto & i : vec)
			a << i;
	}
	template<class Archive, class T, class A>
	std::enable_if_t <std::is_arithmetic<T>::value, void>
		load(Archive & a, std::vector<T, A> & vec)
	{
		size_t size;
		a >> size;
		vec.resize(size);
			for (auto & i : vec)
				a >> i;
	}
}
#endif // !TYPES_VECTOR_HPP
