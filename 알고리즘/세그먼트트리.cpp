// https://www.acmicpc.net/problem/2042

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
long long arr[1000001], tree[4000001];

long long init(int n, int s, int e)
{
    if (s == e)
        return tree[n] = arr[s];

    int mid = (s + e) / 2;
    return tree[n] = init(n * 2, s, mid) + init(n * 2 + 1, mid + 1, e);
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
    return tree[n] = sum(l, r, n * 2, s, mid) + sum(l, r, n * 2 + 1, mid + 1, e);
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &arr[i]);
    M += K;
    init(1, 1, N);
    while (M--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int idx;
            long long value;
            scanf("%d %lld", &idx, &value);
            long long diff = value - arr[idx];
            arr[idx] = value;
            update(1, 1, N, idx, diff);
        }
        else
        {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%lld\n", sum(a, b, 1, 1, N));
        }
    }
    return 0;
}