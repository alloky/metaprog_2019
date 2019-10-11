// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>

struct NIL {
    typedef NIL head;
    typedef NIL tail;
};

template <typename H, typename T=NIL> struct List {
    typedef H head;
    typedef T tail;
};

template <class Btype> struct box {
    typedef Btype _t;
};

template<typename T, typename U>
struct is_same
{
    static const bool value = false;
};

template<typename T>
struct is_same<T, T>
{
    static const bool value = true;
};

template <int d, typename search, typename head, typename list>
struct _GetIndex {
    const static int result =  is_same<search, head>::value ? d : _GetIndex<d + 1, search, typename list::head, typename list::tail>::result; 
};

template <int d, typename search, typename head>
struct _GetIndex<d, search, head, NIL> {
    const static int result = d * is_same<search, head>::value - (1 - is_same<search, head>::value);
};


template <typename search, typename list>
struct getIndexOf {
    const static int result = _GetIndex<0, search, typename list::head, typename list::tail>::result; 
};

int main()
{
    std::cout << getIndexOf< box<short>, List < box<int>, List < box<double>, List < box<char> > > > >::result;
    return 0;
}


