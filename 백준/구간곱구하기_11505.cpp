#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define PIVOT (1 << 20)
#define MOD 1000000007

int N, M, K;
long long arr[PIVOT], tree[PIVOT * 2];

void update(int idx, long long value)
{
    idx += PIVOT;
    tree[idx] = value;
    while (idx >>= 1)
        tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % MOD;
}

long long query(int l, int r)
{
    l += PIVOT, r += PIVOT;
    long long ret = 1;
    while (l <= r)
    {
        if (l % 2)
            ret = (ret * tree[l++]) % MOD;
        if (!(r % 2))
            ret = (ret * tree[r--]) % MOD;
        l /= 2, r /= 2;
    }
    return ret;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &arr[i]);
    for (int i = 0; i <= PIVOT * 2; i++)
        tree[i] = 1;
    for (int i = 1; i <= N; i++)
        update(i, arr[i]);
    int a, b, c;
    for (int i = 0; i < M + K; i++)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            long long c;
            scanf("%d %lld", &b, &c);
            update(b, c);
        }
        else
        {
            scanf("%d %d", &b, &c);
            printf("%lld\n", query(b, c));
        }
    }
    return 0;
}