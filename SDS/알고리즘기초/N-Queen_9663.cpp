#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, ans;
int chess[14][14]; // 초기화가 이미 0으로 되어있음

void recur(int line)
{
    if (line == n)
    {
        ans++;
        return;
    }
    // line어딘가에다가 queen을 놓아본다
    for (int i = 0; i < n; i++)
    {
        if (chess[line][i] != -1)
            continue;
        chess[line][i] = line;

        for (int x = 0; x < n; x++) // 가로
            if (chess[line][x] == -1)
                chess[line][x] = line;
        for (int y = line; y < n; y++) // 아래
            if (chess[y][i] == -1)
                chess[y][i] = line;
        // 대각선
        for (int y = line, x = i; y < n && 0 <= x; y++, x--)
            if (chess[y][x] == -1)
                chess[y][x] = line;
        for (int y = line, x = i; y < n && x < n; y++, x++)
            if (chess[y][x] == -1)
                chess[y][x] = line;

        recur(line + 1);

        for (int x = 0; x < n; x++) //가로
            if (chess[line][x] == line)
                chess[line][x] = -1;
        for (int y = line; y < n; y++) // 아래
            if (chess[y][i] == line)
                chess[y][i] = -1;
        // 대각선
        for (int y = line, x = i; y < n && 0 <= x; y++, x--)
            if (chess[y][x] == line)
                chess[y][x] = -1;
        for (int y = line, x = i; y < n && x < n; y++, x++)
            if (chess[y][x] == line)
                chess[y][x] = -1;
    }
}

int main()
{
    memset(chess, -1, sizeof(chess));
    scanf("%d", &n);
    recur(0);
    printf("%d", ans);
}