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

template<typename T, typename U>
bool eqTypes() { return is_same<T, U>::value; }

template <typename search>
int getIndex(int depth) {
    return depth;
}

template <typename search, typename list>
int getIndex(int depth) {
    if(eqTypes<search, typename list::head>()){
        return depth;
    }
    if(eqTypes<typename list::tail, NIL>()){
        return -1;
    }
    return getIndex<search, typename list::tail>(depth+1);
}

int main()
{
    std::cout << (getIndex<box<short>, List < box<int>, List < box<double>, List < box<char> > > > >(0));
    return 0;
}


