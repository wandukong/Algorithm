#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define PIVOT (1 << 10)
#define pii pair<int, int>

int N, ans, tree[PIVOT * 2], dp[PIVOT], order[PIVOT], number[PIVOT];
vector<pii> arr;

bool op(pii a, pii b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int query(int idx)
{
    int l = PIVOT, r = idx + PIVOT;
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

void update(int idx, int value)
{
    idx += PIVOT;
    tree[idx] = value;
    while (idx >>= 1)
        tree[idx] = max(tree[idx], value);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0, num; i < N; i++)
    {
        scanf("%d", &num);
        arr.push_back({num, i});
        number[i] = num;
    }
    sort(arr.begin(), arr.end(), op);
    for (int i = 0; i < N; i++)
    {
        int value = query(arr[i].second - 1) + 1;
        update(arr[i].second, value);
        ans = max(value, ans);
        dp[arr[i].second] = value;
    }
    int cnt = ans, value = 1000000005;
    for (int i = N - 1; i >= 0; i--)
    {
        if (dp[i] == cnt && number[i] < value)
        {
            order[--cnt] = number[i];
            value = number[i];
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++)
        printf("%d ", order[i]);
    return 0;
}