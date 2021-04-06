#include <iostream>
#include <algorithm>

using namespace std;

int N;
bool prime[1000001];

int main()
{
    scanf("%d", &N);

    for (int i = 2; i <= N; i++)
    {
        if (prime[i])
            continue;
        for (int j = i + i; j <= N; j += i)
            prime[j] = true;
    }

    if (N < 8)
    {
        printf("-1");
        return 0;
    }

    if (N % 2) // È¦¼ö
    {
        printf("2 3 ");
        N -= 5;
    }
    else // Â¦¼ö
    {
        printf("2 2 ");
        N -= 4;
    }
    for (int i = 2; i <= N; i++)
        if (!prime[i] && !prime[N - i])
        {
            printf("%d %d", i, N - i);
            return 0;
        }

    return 0;
}