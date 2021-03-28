#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, K, L, cnt = 0;
int arr[102][102];
bool check[102][102];
queue<pair<int, int>> dir;
queue<pair<int, int>> tail;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int main()
{
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
    }
    scanf("%d", &L);
    for (int i = 0; i < L; i++)
    {
        int a;
        char b;
        scanf("%d %c", &a, &b);
        if (b == 'L')
            dir.push({a, -1});
        if (b == 'D')
            dir.push({a, 1});
    }

    int r = 1, c = 1; // 현재 위치
    check[r][c] = true;
    tail.push({r, c}); // 꼬리 위치

    int s = dir.front().first, d = dir.front().second; // 방향 전환
    int dirIdx = 0;
    while (true)
    {

        r += dr[(dirIdx + 4) % 4];
        c += dc[(dirIdx + 4) % 4];
        cnt++;

        if (check[r][c] || r < 1 || c < 1 || r > N || c > N)
            break;

        check[r][c] = true;
        tail.push({r, c});

        if (!arr[r][c]) //사과 x -> 꼬리 짧아짐
        {
            check[tail.front().first][tail.front().second] = false;
            tail.pop();
        }
        else // 사과 o
            arr[r][c] = 0;
        if (s == cnt) //왼쪽 회전
        {
            dirIdx += d;
            if (dirIdx < 0)
                dirIdx += 4;
            else if (dirIdx > 3)
                dirIdx -= 4;
            dir.pop();
            s = dir.front().first;
            d = dir.front().second;
        }
    }
    printf("%d", cnt);
    return 0;
}