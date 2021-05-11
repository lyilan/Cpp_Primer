#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item book1, book2;
    std::cin >> book1 >> book2;
    book1 += book2;
    std::cout << book1 << std::endl;
    return 0;
}