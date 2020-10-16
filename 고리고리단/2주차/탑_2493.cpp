#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int n;
int ans[500005];
stack<pair<int, int>> st;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
// ���� ���� �۽�ž�� ã�� ���� �߽�ž�� �������� ����

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        st.push({a, i});
    }

    pair<int, int> cur = st.top();
    st.pop();

    while (!st.empty())
    {
        pair<int, int> next = st.top();
        st.pop();

        q.push(cur);

        while (next.first > q.top().first && !q.empty())
        {
            ans[q.top().second] = next.second + 1;
            q.pop();
        }
        cur = next;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}