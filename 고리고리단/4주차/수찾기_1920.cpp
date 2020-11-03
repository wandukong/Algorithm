#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N, M, a;
map<int, int> m;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int a;
        scanf("%d", &a);
        m[a]++;
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &a);
        if (m[a])
            printf("1\n");
        else
            printf("0\n");
    }
}