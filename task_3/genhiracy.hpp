#pragma once

class NullType;

template <class T1, class T2>
class TypeList {
public:
	using Head = T1;
	using Tail = T2;
};

template <class TL, template <class> class Unit>
class GenScatterHierarchy;

template <class T1, class T2, template <class> class Unit>
class GenScatterHierarchy<TypeList<T1, T2>, Unit> :
	public GenScatterHierarchy<T1, Unit>,
	public GenScatterHierarchy<T2, Unit> {
public:
	template <class T>
	struct curType {
		typedef Unit<T> res;
	};
	using TList = TypeList<T1, T2>;
	using LeftBase = GenScatterHierarchy<T1, Unit>;
	using RightBase = GenScatterHierarchy<T2, Unit>;
};

template <class AtomicType, template <class> class Unit>
class GenScatterHierarchy : public Unit<AtomicType> {

};

template <template <class> class Unit>
class GenScatterHierarchy<NullType, Unit> {
	template <class T>
	struct curType {
		typedef Unit<T> res;
	};
};


template <class T, class H>
typename H::template curType<T>::res& get_value(H& obj) {
	return obj;
}