#include <iostream>
#include <algorithm>

using namespace std;

bool isNotPrime[1000001];

int main()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (isNotPrime[i])
            continue;
        for (int j = i + i; j <= 1000000; j += i)
            if (!isNotPrime[j])
                isNotPrime[j] = true;
    }
    while (true)
    {
        int N;
        scanf("%d", &N);
        if (N == 0)
            break;
        bool chk = true;
        for (int i = 3; i <= N; i++)
        {
            if (!isNotPrime[i] && !isNotPrime[N - i])
            {
                printf("%d = %d + %d\n", N, i, N - i);
                chk = false;
                break;
            }
        }
        if (chk)
            printf("Goldbach's conjecture is wrong\n");
    }
}