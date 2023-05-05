#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
 Vector<int>v{1,2,3,4,5,6};
 for (auto iter{v.begin_a()}; iter != v.end_a(); ++iter)
    {
        std::cout << *iter << "\t";
    }
    std::cout << std::endl;
}

