#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, ans, interview;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        vector<pair<int, int>> v;
        scanf("%d", &N);
        ans = 1;
        for (int i = 0; i < N; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());

        interview = v[0].second;
        for (int i = 1; i < N; i++)
        {
            if (interview > v[i].second)
            {
                interview = v[i].second;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}