#include <iostream>
#include <algorithm>

using namespace std;

#define PIVOT (1 << 18)

int N, K, arr[PIVOT], tree[PIVOT * 2];

int sum(int k) // count query
{
    int idx = 1; // 일반 인덱스 트리랑 다르게 1부터 시작
    while (idx < PIVOT)
    {
        idx *= 2;
        if (tree[idx] < k)
            k -= tree[idx], idx++;
    }
    return idx - PIVOT;
}

void update(int idx, int value)
{
    idx += PIVOT;
    tree[idx] += value;
    while (idx >>= 1)
        tree[idx] += value;
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= K; i++)
        update(arr[i], 1);
    long long ans = 0;
    for (int i = 1; i <= N - K + 1; i++)
    {
        ans += sum((K + 1) / 2);
        update(arr[i], -1);
        update(arr[i + K], 1);
    }
    printf("%lld", ans);
    return 0;
}