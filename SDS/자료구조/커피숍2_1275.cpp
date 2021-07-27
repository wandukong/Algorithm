#include <algorithm>
#include <iostream>
using namespace std;
#define PIV (1 << 17)

int N, M;
long long tree[PIV * 2];

void update(int idx, long long value)
{
    idx += PIV;
    tree[idx] = value;
    while (idx >>= 1)
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

long long sum(int l, int r)
{
    l += PIV, r += PIV;
    long long ret = 0;
    while (l <= r)
    {
        if (l % 2)
            ret += tree[l++];
        if (!(r % 2))
            ret += tree[r--];
        l /= 2, r /= 2;
    }
    return ret;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        long long num;
        scanf("%lld", &num);
        update(i, num);
    }
    for (int i = 0, x, y, a; i < M; i++)
    {
        long long b;
        scanf("%d %d %d %lld", &x, &y, &a, &b);
        if (x > y)
            swap(a, b);
        printf("%lld\n", sum(x, y));
        update(a, b);
    }
    return 0;
}