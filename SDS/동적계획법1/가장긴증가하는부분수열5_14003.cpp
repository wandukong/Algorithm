#include <iostream>
#include <algorithm>

using namespace std;

#define PIV (1 << 20)

int N, tree[PIV * 2], dp[PIV], p[PIV], route[PIV], ans;
pair<int, int> arr[PIV];

bool op(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

void update(int idx, int value)
{
    idx += PIV;
    tree[idx] = value;
    while (idx >>= 1)
    {
        tree[idx] = max(tree[idx], value);
    }
}

int sum(int idx)
{
    int l = PIV, r = idx + PIV;
    int ret = 0;
    while (l <= r)
    {
        if (l % 2)
            ret = max(ret, tree[l++]);
        if (!(r % 2))
            ret = max(ret, tree[r--]);
        l /= 2, r /= 2;
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0, num; i < N; i++)
        scanf("%d", &num), arr[i] = {num, i}, p[i] = num;
    sort(arr, arr + N, op);
    for (int i = 0; i < N; i++)
    {
        int ret = sum(arr[i].second - 1) + 1; // 이전 인덱스까지의 합
        update(arr[i].second, ret);
        dp[arr[i].second] = ret;
        ans = max(ans, ret);
    }
    printf("%d\n", ans);
    int cnt = ans, ret = 1000000005;
    for (int i = N - 1; i >= 0; i--)
        if (dp[i] == cnt && p[i] < ret)
            route[--cnt] = p[i], ret = p[i];
    for (int i = 0; i < ans; i++)
        printf("%d ", route[i]);
    return 0;
}