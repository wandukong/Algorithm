#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isNotPrime[3200];
vector<int> prime;
int N;

int main()
{
    for (int i = 2; i < 3200; i++)
    {
        if (isNotPrime[i])
            continue;
        for (int j = i + i; j < 3200; j += i)
            if (!isNotPrime[j])
                isNotPrime[j] = true;
    }
    for (int i = 2; i < 3200; i++)
        if (!isNotPrime[i])
            prime.push_back(i);

    scanf("%d", &N);
    if (N == 1)
        return 0;

    for (int i = 0; i < prime.size(); i++)
    {
        while (N % prime[i] == 0)
        {
            printf("%d\n", prime[i]);
            N /= prime[i];
        }
        if (N == 0)
            break;
    }
    if (N > 1)
        printf("%d\n", N);
    return 0;
}