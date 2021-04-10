#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, M, K, ans;

typedef struct
{
    int r, c, m, s, d;
} info;

vector<info> map[50][50];
vector<info> fireball;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve()
{
    while (K--)
    {
        for (int i = 0; i < fireball.size(); i++)
        {
            int rd = fireball[i].d; // ¹æÇâ
            int nr = (fireball[i].r + dr[rd] * fireball[i].s) % N;
            int nc = (fireball[i].c + dc[rd] * fireball[i].s) % N;
            if (nr < 0)
                nr += N;
            if (nc < 0)
                nc += N;
            fireball[i].r = nr;
            fireball[i].c = nc;
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                map[i][j].clear();

        for (int i = 0; i < fireball.size(); i++)
            map[fireball[i].r][fireball[i].c].push_back(fireball[i]);

        fireball.clear();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j].size() == 1)
                    fireball.push_back(map[i][j][0]);
                else if (map[i][j].size() > 1)
                {
                    int mass = 0, speed = 0;
                    bool odd = true, even = true;
                    for (int k = 0; k < map[i][j].size(); k++)
                    {
                        mass += map[i][j][k].m;
                        speed += map[i][j][k].s;
                        if (map[i][j][k].d % 2 == 0)
                            odd = false;
                        else
                            even = false;
                    }

                    if (mass / 5 == 0)
                        continue;

                    for (int k = 0; k < 4; k++)
                    {
                        if (even || odd)
                            fireball.push_back({i, j, mass / 5, speed / (int)map[i][j].size(), k * 2});
                        else
                            fireball.push_back({i, j, mass / 5, speed / (int)map[i][j].size(), k * 2 + 1});
                    }
                }
            }
        }
    }
    for (int i = 0; i < fireball.size(); i++)
        ans += fireball[i].m;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++)
    {
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        fireball.push_back({a - 1, b - 1, c, d, e});
    }
    solve();
    printf("%d", ans);
    return 0;
}