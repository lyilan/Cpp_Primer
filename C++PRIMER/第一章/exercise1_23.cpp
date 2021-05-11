#include <iostream>
#include "Sales_item.h"
int main()
{
    //  currVal 是正在统计的书，读入的新书存入book
    Sales_item currBook = {0}, book = {0};
    //  读取第一本书，并确保有书可以处理
    if (std::cin >> currBook)
    {
        int cnt = 1;             //保存正在处理的当前书的数量
        while (std::cin >> book) //读取剩余的书
        {
            if (book.isbn() == currBook.isbn()) //如果书相同
                ++cnt;                          //将cnt加一
            else
            { //否则打印前一本书的个数
                std::cout << currBook << " occurs "
                          << cnt << " times" << std::endl;
                currBook = book; //记住新书
                cnt = 1;         //重制计数器
            }
        }
        std::cout << currBook << " occurs "
                  << cnt << " times" << std::endl;
    }
    return 0;
}