#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, p, d, ans;
bool check[10001];
priority_queue<pair<int, int>> pq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p, &d);
        pq.push({p, d});
    }
    while (!pq.empty())
    {
        int pay = pq.top().first;
        int day = pq.top().second;
        pq.pop();
        bool chk = false;
        while (day)
        {
            if (!check[day])
            {
                ans += pay;
                check[day] = true;
                chk = true;
            }
            if (chk)
                break;
            day--;
        }
    }
    printf("%d", ans);
    return 0;
}