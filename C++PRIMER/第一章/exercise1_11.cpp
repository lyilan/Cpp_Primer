#include <iostream>
int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int low = 0, high = 0;
    std::cin >> low >> high;
    while (low <= high)
    {
        std::cout << low << std::endl;
        low++;
    }
    return 0;
}