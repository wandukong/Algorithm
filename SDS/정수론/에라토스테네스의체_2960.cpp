#include <iostream>
#include <algorithm>

using namespace std;

int isNotPrime[1001];

int main()
{
    int n, k, cnt = 0;
    scanf("%d %d", &n, &k);
    for (int i = 2; i <= n; i++)
    {
        if (isNotPrime[i])
            continue;
        for (int j = i; j <= n; j += i)
        {
            if (!isNotPrime[j])
            {
                isNotPrime[j] = true;
                cnt++;
                if (cnt == k)
                {
                    printf("%d", j);
                    return 0;
                }
            }
        }
    }
    return 0;
}