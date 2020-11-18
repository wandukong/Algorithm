#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, ans = 1, endTime;
vector<pair<int, int>> v;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back({a, b});
        endTime = max(endTime, b);
    }
    sort(v.begin(), v.end());

    int tempStart = v[0].first, tempEnd = v[0].second;

    for (int i = 1; i < N; i++)
    {
        if (v[i].second < tempEnd)
        {
            tempStart = v[i].first;
            tempEnd = v[i].second;
        }
        else if (tempEnd <= v[i].first)
        {
            ans++;
            tempStart = v[i].first;
            tempEnd = v[i].second;
        }
    }
    printf("%d\n", ans);
}