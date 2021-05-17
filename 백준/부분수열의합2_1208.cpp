#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, S;
long long arr[41], ans;
vector<long long> a, b;

void solve(int idx, int end, long long sum, vector<long long> &v)
{
    if (idx == end)
    {
        v.push_back(sum);
        return;
    }
    solve(idx + 1, end, sum, v);
    solve(idx + 1, end, sum + arr[idx], v);
}

int main()
{
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%lld", &arr[i]);

    solve(0, N / 2, 0, a);
    solve(N / 2, N, 0, b);
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++)
    {
        int temp = S - a[i];
        int l = lower_bound(b.begin(), b.end(), temp) - b.begin();
        int r = upper_bound(b.begin(), b.end(), temp) - b.begin();
        ans += r - l;
    }
    if (S == 0)
        ans--;
    printf("%lld", ans);
    return 0;
}