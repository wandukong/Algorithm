#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

string S;
int K, ans;
bool check[1000001][11];

int bfs()
{
    int strLength = S.size();
    if ((S[strLength - 1] == '0' && strLength == 2) || strLength == 1)
    {
        return -1;
    }

    queue<pair<string, int>> q;
    q.push({S, 0});
    check[stoi(S)][0] = true;

    while (!q.empty())
    {
        string curStr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cnt == K)
        {
            ans = max(ans, stoi(curStr));
            continue;
        }

        for (int i = 0; i < strLength; i++)
        {
            for (int j = 0; j < strLength; j++)
            {
                if (i == j)
                    continue;
                string temp = curStr;
                swap(temp[i], temp[j]);

                if (temp[0] == '0')
                    continue;

                if (!check[stoi(temp)][cnt + 1])
                {
                    q.push({temp, cnt + 1});
                    check[stoi(temp)][cnt + 1] = true;
                }
            }
        }
    }
    return ans;
}

int main()
{
    cin >> S;
    scanf("%d", &K);

    printf("%d", bfs());
    return 0;
}