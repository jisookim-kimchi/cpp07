#include "Array.hpp"

int main (void)
{
    Array<int> arr = {0,1,2};

    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    try
    {
        arr[3] = 0;
    }
    catch (const Array<int>::ExceptionOutOfBounds &err)
    {
        std::cerr << "catch : 다따라따따 다따라따따 음음음 베이베 " <<err.what() << std::endl;
    }
    
    int out_value = 0;
    Array<int>::Status status = arr.get(3, out_value);
    if (status == Array<int>::SUCCESS)
    {
        std::cout << "success: " << out_value << std::endl;
    }
    else if (status == Array<int>::ERR_OUT_OF_BOUNDS)
    {
        std::cout << "out" << std::endl;
    }

    Array<int> arr2 = {-3,-2,-1};
    for (auto &a : arr2)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    Array<int> arr4 = arr + arr2;
    for (auto &a : arr4)
    {
        std::cout << ++a << " ";
    }
    std::cout << std::endl;
    
    return 0;
}