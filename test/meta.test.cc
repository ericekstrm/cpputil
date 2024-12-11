#include <gtest/gtest.h>
#include <cpputil/meta.h>

#include <vector>
#include <string>
#include <list>

// template<instantiation_of<std::vector> T>
template<typename T>
void fun(T const& a_vector) requires instantiation_of<T, std::vector>
{
    SUCCEED();
}

TEST(Meta, instantiation_of)
{
    std::vector<int> v;
    std::list<int> l;

    fun(v);
    fun(std::vector<std::string>{});
    // Ska inte kompilera:
    // fun(l);
    // fun(5);
    // fun("hej");
}
