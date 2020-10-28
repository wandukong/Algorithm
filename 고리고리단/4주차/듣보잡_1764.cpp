#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N, M;
map<string, int> m;
vector<string> v;

int main()
{
    string temp;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        m[temp]++;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        m[temp]++;
    }

    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
        if (it->second == 2)
            v.push_back(it->first);

    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++)
        printf("%s\n", v[i].c_str());
}