#include <iostream>
int main()
{ //1.11
    std::cout << "Enter two numbers: " << std::endl;
    int low = 0, high = 0;
    std::cin >> low >> high;
    for (int index = low; index <= high; index++)
        std::cout << index << std::endl;
    return 0;
}