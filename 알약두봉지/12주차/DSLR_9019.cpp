#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int T, B, A;
bool check[10000];

string bfs()
{
    queue<pair<int, string>> q;
    q.push({A, ""});
    while (!q.empty())
    {
        int cur = q.front().first;
        string command = q.front().second;
        q.pop();

        if (cur == B)
            return command;

        //D
        int nextValue = (cur * 2) % 10000;
        if (!check[nextValue])
        {
            check[nextValue] = true;
            q.push({nextValue, command + "D"});
        }
        //S
        if (cur == 0)
            nextValue = 9999;
        else
            nextValue = cur - 1;
        if (!check[nextValue])
        {
            check[nextValue] = true;
            q.push({nextValue, command + "S"});
        }

        //L
        string curStr = to_string(cur);
        if (curStr.size() <= 3)
        {
            nextValue = cur * 10;
        }
        else
        {
            swap(curStr[0], curStr[1]);
            swap(curStr[1], curStr[2]);
            swap(curStr[2], curStr[3]);
            nextValue = stoi(curStr);
        }
        if (!check[nextValue])
        {
            check[nextValue] = true;
            q.push({nextValue, command + "L"});
        }

        //R
        curStr = to_string(cur);
        if (curStr.size() <= 3)
        {
            nextValue = cur / 10;
        }
        else
        {
            swap(curStr[3], curStr[2]);
            swap(curStr[2], curStr[1]);
            swap(curStr[1], curStr[0]);
            nextValue = stoi(curStr);
        }
        if (!check[nextValue])
        {
            check[nextValue] = true;
            q.push({nextValue, command + "R"});
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &A, &B);
        printf("%s\n", bfs().c_str());
        memset(check, 0, sizeof(check));
    }
    return 0;
}