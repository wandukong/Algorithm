#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, arr[100001], tree[400004];

int init(int n, int s, int e)
{
    if (s == e)
        return tree[n] = arr[s];
    int mid = (s + e) / 2;
    return tree[n] = min(init(n * 2, s, mid), init(n * 2 + 1, mid + 1, e));
}

int get(int n, int s, int e, int l, int r)
{
    if (l <= s && e <= r)
        return tree[n];
    if (e < l || s > r)
        return 2000000001;
    int mid = (s + e) / 2;
    return min(get(n * 2, s, mid, l, r), get(n * 2 + 1, mid + 1, e, l, r));
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i <= N * 4; i++)
        tree[i] = 2000000001;
    init(1, 1, N);
    while (M--)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", get(1, 1, N, s, e));
    }
    return 0;
}