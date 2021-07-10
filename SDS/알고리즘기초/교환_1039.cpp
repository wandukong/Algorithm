#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int n, k;
queue<int> q;
map<pair<string, int>, bool> check;

bool isok(int num)
{
    if (num < 10)
        return false;
    if (num < 100 && num % 10 == 0)
        return false;
    return true;
}

int main()
{
    scanf("%d%d", &n, &k);
    if (n == 1000000)
    {
        printf("%d", n);
        return 0;
    }
    if (!isok(n))
    {
        printf("-1");
        return 0;
    }
    q.push(n);
    for (int i = 0; i < k; i++)
    {
        int qSize = q.size();
        for (int j = 0; j < qSize; j++)
        {
            int cur = q.front();
            q.pop();
            int len = to_string(cur).size();
            for (int s = 0; s < len; s++)
            {
                for (int e = s + 1; e < len; e++)
                {
                    string temp = to_string(cur);
                    swap(temp[s], temp[e]);
                    if (temp[0] == '0')
                        continue;
                    if (check[{temp, i}])
                        continue;
                    check[{temp, i}] = true;
                    q.push(stoi(temp));
                }
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (ans < cur)
            ans = cur;
    }
    printf("%d", ans);
}