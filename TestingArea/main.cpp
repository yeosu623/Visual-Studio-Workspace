#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device dev;
    mt19937 seed(dev());
    uniform_int_distribution<mt19937::result_type> randon_int(0, 2);

    for (int i = 0; i < 10; i++)
        cout << randon_int(seed) << '\n';
}