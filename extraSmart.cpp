#include <iostream>
#include <memory>

//------------------------------------------------------------------
// Make a copy of some data and return a unique_ptr to it.
//------------------------------------------------------------------
template<typename T>
std::unique_ptr<T> make_unique(T t) {
    return std::unique_ptr<T>(new T(t));
}

//------------------------------------------------------------------
// Explicitly instantiating what the make_unique template almost
// generates when given a std::unique_ptr<double>. Passing to this
// object requires a std::move(). We also add an explicit use of
// std::move() otherwise it won't compile.
//
// Is this the behaviour that you want????
// -----------------------------------------------------------------
std::unique_ptr<std::unique_ptr<double> >
move_unique(std::unique_ptr<double> t) {
    return std::unique_ptr<std::unique_ptr<double>>(new std::unique_ptr<double>(std::move(t)));
}

template <typename T>
std::unique_ptr<T> make_unique(std::unique_ptr<T>& up)
{
    return std::unique_ptr<T>(new T(*up));
}

template <typename T>
T getBase(T t) {
    return t;
}

template <typename T>
auto getBase(T *t) -> decltype(*t) {
    return *t;
}

int main() {
    auto dptr = make_unique(3.14);
    std::cout << *dptr << std::endl;

    auto dptr2 = make_unique(dptr);
    std::cout << *dptr2 << std::endl;

    int i = 9;
    int* iptr = &i;
    std::cout << getBase(i) << std::endl;
    std::cout << getBase(iptr) << std::endl;
    //std::cout << getBase(dptr) << std::endl; not compile

    return 0;
}