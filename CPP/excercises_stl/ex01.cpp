#include <iostream>
#include <vector>

using namespace std;

int main(void){

    vector<int> num;

    for (int i = 1; i <= 10; i++)
    {
        num.push_back(i);
    }

    for (const auto& n: num)
    {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}
