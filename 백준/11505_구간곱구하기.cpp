#include <iostream>
#include <algorithm>

int N, M, K;
long long arr[1000001], tree[4000001];

long long init(int n, int s, int e)
{
    if (s == e)
        return tree[n] = arr[s];
    int mid = (s + e) / 2;
    return tree[n] = ((init(n * 2, s, mid) % 1000000007) * (init(n * 2 + 1, mid + 1, e) % 1000000007)) % 1000000007;
}

long long update(int n, int s, int e, int idx, long long value)
{
    if (!(s <= idx && idx <= e))
        return tree[n];
    if (s == e)
        return tree[n] = value;
    int mid = (s + e) / 2;
    return tree[n] = ((update(n * 2, s, mid, idx, value) % 1000000007) * (update(n * 2 + 1, mid + 1, e, idx, value) % 1000000007)) % 1000000007;
}

long long multiply(int l, int r, int n, int s, int e)
{
    if (l <= s && e <= r)
        return tree[n];
    else if (l > e || r < s)
        return 1;
    int mid = (s + e) / 2;
    return ((multiply(l, r, n * 2, s, mid) % 1000000007) * (multiply(l, r, n * 2 + 1, mid + 1, e) % 1000000007)) % 1000000007;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    M += K;
    for (int i = 1; i <= N; i++)
        scanf("%lld", &arr[i]);
    init(1, 1, N);
    while (M--)
    {
        int a;
        scanf("%d", &a);
        if (a == 1)
        {
            int idx;
            long long value;
            scanf("%d %lld", &idx, &value);
            update(1, 1, N, idx, value);
        }
        else
        {
            int start, end;
            scanf("%d %d", &start, &end);
            printf("%lld\n", multiply(start, end, 1, 1, N));
        }
    }
    return 0;
}