#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define PIVOT (1 << 18)

int N, K, arr[PIVOT], tree[PIVOT * 2];
long long ans;

void update(int idx, int value)
{
    idx += PIVOT;
    tree[idx] = value;
    while (idx >>= 1)
        tree[idx] += value;
}

int query(int value)
{
    int idx = 1;
    while (idx < PIVOT)
    {
        idx *= 2;
        if (tree[idx] < value)
        {
            value -= tree[idx];
            idx++;
        }
    }
    return idx - PIVOT;
}
//https://www.acmicpc.net/problem/1572
int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < K; i++)
        update(arr[i], 1);
    for (int i = 0; i < N - K + 1; i++)
    {
        ans += query((K + 1) / 2);
        update(arr[i], -1);
        update(arr[i + K], 1);
    }
    printf("%lld", ans);
    return 0;
}