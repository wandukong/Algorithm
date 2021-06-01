#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
string S;
bool check[16];
string temp;
vector<string> v;

void go(int cnt, int loc)
{
    if (cnt == L)
    {
        int mo = 0, za = 0;
        for (int i = 0; i < L; i++)
        {
            if (temp[i] == 97 || temp[i] == 101 || temp[i] == 105 || temp[i] == 111 || temp[i] == 117)
                mo++;
            else
                za++;
        }
        if (mo > 0 && za > 1)
            v.push_back(temp);
    }

    for (int i = loc; i < C; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            temp.push_back(S[i]);
            go(cnt + 1, i + 1);
            temp.erase(temp.end() - 1);
            check[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &L, &C);
    for (int i = 0; i < C; i++)
    {
        char c;
        cin >> c;
        S.push_back(c);
    }
    sort(S.begin(), S.end());
    go(0, 0);
    for (int i = 0; i < v.size(); i++)
        printf("%s\n", v[i].c_str());
    return 0;
}