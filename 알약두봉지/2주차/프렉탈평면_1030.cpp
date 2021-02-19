#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int s, N, K, R1, R2, C1, C2;
int ans[55][55];
vector<int> total;
vector<int> black;

int main()
{
    scanf("%d %d %d %d %d %d %d", &s, &N, &K, &R1, &R2, &C1, &C2);

    int num = 1;
    for (int i = 0; i < s; i++)
        num *= N;
    int a = N;
    int b = K;

    do
    {
        total.push_back(a);
        black.push_back(b);
        a *= N;
        b *= N;
    } while (a <= num);

    for (int i = 0; i <= R2 - R1; i++)
    {
        for (int j = 0; j <= C2 - C1; j++)
        {
        }
    }

    return 0;
}