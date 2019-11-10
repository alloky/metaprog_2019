#include "genhiracy.hpp"
#include <iostream>

template <class T>
class Holder {
public:
	T value;
};

using classHiracy = GenScatterHierarchy<TypeList<int, TypeList<bool, TypeList<double, NullType>>>, Holder>;


void main() {

	classHiracy g;
	get_value<int>(g).value = 42;
	get_value<bool>(g).value = false;
	get_value<double>(g).value = 2.3;
	std::cout << get_value<int>(g).value << "\n";
	std::cout << get_value<bool>(g).value << "\n";
	std::cout << get_value<double>(g).value << "\n";
}
