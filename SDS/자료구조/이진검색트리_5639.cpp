#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

void recursive(int s, int e)
{

    if (s == e)
    {
        printf("%d\n", v[s]);
        return;
    }
    else if (s > e)
        return;
    else
    {
        int where = s + 1;
        while (where <= e)
        {
            if (v[where] > v[s])
                break;
            else
                where++;
        }
        recursive(s + 1, where - 1); // ¿ÞÂÊ
        recursive(where, e);         // ¿À¸¥ÂÊ
        printf("%d\n", v[s]);
    }
}

int main()
{
    while (true)
    {
        int a;
        if (scanf("%d", &a) == -1)
            break;
        else
            v.push_back(a);
    }
    recursive(0, v.size() - 1);
    return 0;
}