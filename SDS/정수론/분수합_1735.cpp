#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int a, b, c, d, under, up, num;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    under = b * d;
    up = a * d + b * c;
    num = gcd(up, under);
    printf("%d %d", up/num, under/num);
    return 0;
}