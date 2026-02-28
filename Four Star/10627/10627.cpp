#include <iostream>
using namespace std;

//  回傳a、b的最大公因數
long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cout.sync_with_stdio(false);

    long long int length;

    //  the speed
    long long int u, v;

    long long int time;

    //  the meet times
    long long int meet;

    while (cin >> length >> u >> v >> time && length != 0)
    {
        meet = 0;

        if (u < v)
            swap(u, v);

        //  迎面遇到次數
        meet += (time * (u + v) / length + 1) / 2;

        //  倒追次數
        meet += (time * (u - v) / length + 1) / 2;

        //  factor = u, v的最大公因數
        long long int factor = gcd(u, v);

        //  判斷是否有在端點相遇，有的話需要扣除在端點相遇的次數
        if ( ((u - v) / factor) % 2 == 1)
        {
            meet -= (factor * time + length) / (2 * length);
        }

        //  output
        cout << meet << '\n';
    }
    return 0;
}