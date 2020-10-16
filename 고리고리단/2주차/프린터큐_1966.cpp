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
        queue<pair<int, int>> q; // �߿䵵�� ������ ���� queue
        vector<int> order;       // �μ� �߿䵵 �������� ������ queue

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
            if (order[0] == q.front().first) // �߿䵵�� ���Ƽ� ���
            {
                ans++;
                if (q.front().second == m) // ã������ �ߴ� ����
                {
                    printf("%d\n", ans);
                    break;
                }
                order.erase(order.begin(), order.begin() + 1);
                q.pop();
            }
            else // �ش� �������� �� �߿��� ������ �־ �ǵڷ� �̵�
            {
                pair<int, int> temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
    }
    return 0;
}