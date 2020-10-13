#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int tc;

int main()
{
    scanf("%d", &tc);
    while (tc--)
    {
        int n, m, ans = 0;
        queue<pair<int, int>> q; // 중요도와 순서를 담은 queue
        vector<int> order;       // 인쇄 중요도 내림차순 정렬한 queue

        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            q.push({a, i});
            order.push_back(a);
        }

        sort(order.begin(), order.end(), greater<int>());

        while (!order.empty())
        {
            if (order[0] == q.front().first) // 중요도가 높아서 출력
            {
                ans++;
                if (q.front().second == m) // 찾으려고 했던 문서
                {
                    printf("%d\n", ans);
                    break;
                }
                order.erase(order.begin(), order.begin() + 1);
                q.pop();
            }
            else // 해당 문서보다 더 중요한 문서가 있어서 맨뒤로 이동
            {
                pair<int, int> temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
    }
    return 0;
}