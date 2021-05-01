#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int T, N;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        bool check = true;
        vector<string> v;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < N - 1; i++)
            if (v[i].size() < v[i + 1].size() && v[i + 1].find(v[i]) == 0)
            {
                check = false;
                break;
            }
        if (check)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}