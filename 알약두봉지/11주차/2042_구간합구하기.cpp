#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int N, M, K;
long long arr[1000001], tree[1000001];

long long sum(int idx)
{
    long long result = 0;
    while (idx > 0)
    {
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

void update(int idx, long long diff)
{
    while (idx <= N)
    {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &arr[i]);
        update(i, arr[i]);
    }
    int T = M + K, a;
    while (T--)
    {
        scanf("%d", &a);
        if (a == 1) // update
        {
            int idx;
            long long value;
            scanf("%d %lld", &idx, &value);
            update(idx, value - arr[idx]);
            arr[idx] = value;
        }
        else // sum
        {
            int start, end;
            scanf("%d %d", &start, &end);
            printf("%lld\n", sum(end) - sum(start - 1));
        }
    }
    return 0;
}
