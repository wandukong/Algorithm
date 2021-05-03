#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int N, M, K;
long long arr[1000001], tree[3000001];

long long init(int n, int s, int e)
{
    if (s == e)
        tree[n] = arr[s];
    int m = (s + e) / 2;
    tree[n] = init(n * 2, s, m) + init(n * 2 + 1, m + 1, e);
    return tree[n];
}

void update(int n, int s, int e, int idx, long long diff)
{
    if (s <= idx && idx <= e)
        tree[n] += diff;
    else
        return;
    if (s == e)
        return;
    int mid = (s + e) / 2;
    update(n * 2, s, mid, idx, diff);
    update(n * 2 + 1, mid + 1, e, idx, diff);
}

long long sum(int l, int r, int n, int s, int e)
{
    if (l <= s && e <= r)
        return tree[n];
    if (r < s || l > e)
        return 0;
    int mid = (s + e) / 2;
    return sum(l, r, n * 2, s, mid) + sum(l, r, n * 2 + 1, mid + 1, e);
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &arr[i]);
    init(1, 1, N);
    int T = M + K, a;
    while (T--)
    {
        scanf("%d", &a);
        if (a == 1) // update
        {
            int idx;
            long long value;
            scanf("%d %lld", &idx, &value);
            int diff = value - arr[idx];
            arr[idx] = value;
            update(1, 1, N, idx, diff);
        }
        else // sum
        {
            int start, end;
            scanf("%d %d", &start, &end);
            printf("%lld\n", sum(start, end, 1, 1, N));
        }
    }
    return 0;
}
