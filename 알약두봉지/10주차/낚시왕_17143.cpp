#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int R, C, M, arr[102][102], temp[102][102], ans, cnt = 1;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

struct info
{
    int r, c, s, d, z;
};

bool cmp(info a, info b)
{
    return a.z > b.z;
}
vector<info> shark;
queue<info> nextShark;

void sovle()
{
    while (cnt <= C)
    {
        int r = 0;
        int c = cnt;
        for (int i = 1; i <= R; i++)
            if (arr[i][cnt])
            {
                r = i;
                break;
            }
        while (!nextShark.empty())
        {
            if (r == nextShark.front().r && c == nextShark.front().c)
            {
                ans += nextShark.front().z;
                nextShark.pop();
                continue;
            }
            shark.push_back(nextShark.front());
            nextShark.pop();
        }
        sort(shark.begin(), shark.end(), cmp);

        for (int i = 0; i < shark.size(); i++) // 상어 이동
        {
            r = shark[i].r;
            c = shark[i].c;
            int move = shark[i].s;
            int dir = shark[i].d;

            if (dir == 0 || dir == 1)
            {
                move = move % ((R - 1) * 2);
            }
            else
            {
                move = move % ((C - 1) * 2);
            }

            while (move--)
            {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                if (nr < 1) // 위로 가다가 벗어남
                    dir = 1;
                else if (nc < 1) // 왼쪽으로 가다가 벗어남
                    dir = 2;
                else if (nc > C) // 오른쪽으로 가다가 벗어남
                    dir = 3;
                else if (nr > R) // 아래로 가다가 벗어남
                    dir = 0;
                r += dr[dir];
                c += dc[dir];
            }
            if (temp[r][c] != 0)
                continue;
            nextShark.push({r, c, shark[i].s, dir, shark[i].z});
            temp[r][c] = shark[i].z;
        }
        cnt++;
        memcpy(arr, temp, sizeof(temp));
        memset(temp, 0, sizeof(temp));
        shark.clear();
    }
}

int main()
{
    scanf("%d %d %d", &R, &C, &M);
    for (int i = 0; i < M; i++)
    {
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        nextShark.push({a, b, c, d - 1, e});
        arr[a][b] = e;
    }
    sovle();
    printf("%d", ans);
    return 0;
}