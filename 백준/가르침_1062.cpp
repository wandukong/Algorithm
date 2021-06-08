#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K, N, ans;
vector<string> str;
bool check[26];

void go(int cnt, int loc)
{
    if (cnt == K)
    {
        int sum = 0;
        for (int i = 0; i < str.size(); i++)
        {
            bool chk = false;
            for (int j = 0; j < str[i].size(); j++)
                if (!check[str[i][j] - 'a'])
                {
                    chk = true;
                    break;
                }
            if (!chk)
                sum++;
        }
        ans = max(sum, ans);
    }
    for (int i = loc; i < 26; i++)
        if (!check[i])
        {
            check[i] = true;
            go(cnt + 1, i + 1);
            check[i] = false;
        }
}

int main()
{
    scanf("%d %d", &N, &K);
    K -= 5;
    check['a' - 'a'] = check['t' - 'a'] = check['i' - 'a'] = check['n' - 'a'] = check['c' - 'a'] = true;
    for (int i = 0; i < N; i++)
    {
        string temp, s;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] == 'a' || temp[j] == 't' || temp[j] == 'i' || temp[j] == 'n' || temp[j] == 'c')
                continue;
            s.push_back(temp[j]);
        }
        str.push_back(s);
    }
    go(0, 0);
    printf("%d", ans);
    return 0;
}