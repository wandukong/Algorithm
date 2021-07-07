#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> a, b, c, d, ab, cd;
long long ans, cnt;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int u, v, w, x;
        scanf("%d %d %d %d", &u, &v, &w, &x);
        a.push_back(u);
        b.push_back(v);
        c.push_back(w);
        d.push_back(x);
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    // 规过1
    for (int i = 0; i < ab.size(); i++)
        ans += upper_bound(cd.begin(), cd.end(), ab[i] * -1) - lower_bound(cd.begin(), cd.end(), ab[i] * -1);

    // 规过2
    // int cdIdx = cd.size() - 1;
    // for (int i = 0; i < ab.size(); i++)
    // {
    //     int target = ab[i] * -1;
    //     if (0 < i && ab[i] == ab[i - 1])
    //         ans += cnt;
    //     else
    //     {
    //         while (0 <= cdIdx && target < cd[cdIdx])
    //             cdIdx--;
    //         cnt = 0;
    //         while (0 <= cdIdx && target == cd[cdIdx])
    //         {
    //             cnt++;
    //             cdIdx--;
    //         }
    //         ans += cnt;
    //     }
    // }
    printf("%lld", ans);
}