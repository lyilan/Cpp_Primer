#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> v;
    int input;
    while (cin >> input)
    {
        v.push_back(input);
    }
    for (int i = 0, j = v.size() - 1; i < j; i++, j--)
    {
        cout << v[i] + v[j] << " ";
    }
    cout << endl;
    return 0;
}