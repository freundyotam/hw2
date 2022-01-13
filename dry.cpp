#include <vector>
#include <iostream>
#include <memory>
#include <exception>

class BadInput : public std::exception
{
};

template <class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop)
{
    int size = vec.size();
    if (start < 0 || start >= size || stop < 0 || stop > size || step <= 0)
        throw BadInput();

    std::vector<T> sliced_vec;
    for (auto i = vec.begin() + start; i < vec.begin() + stop; i += step)
    {
        sliced_vec.push_back(*i);
    }

    return sliced_vec;
}

class A
{
public:
    std::vector<std::shared_ptr<int>> values;
    void add(int x) { values.push_back(std::make_shared<int>(x)); }
};

int main()
{
    // this syntax initializes a vector with values a,b,c,d,e
    std::vector<char> vec1{'a', 'b', 'c', 'd', 'e'};
    // returns vector with values a,c
    std::vector<char> vec_sliced = slice(vec1, 0, 2, 4);
    // returns vector with values b,c,d,e
    std::vector<char> vec_sliced2 = slice(vec1, 1, 1, 5);

    A a, sliced;
    a.add(0);
    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);
    sliced.values = slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;
}