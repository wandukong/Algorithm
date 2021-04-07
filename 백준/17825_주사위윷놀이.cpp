#include <iostream>
#include <algorithm>

using namespace std;

int dice[10], ans;
int mal[4];
int arr[35];
int score[35];
int turn[35];
bool check[35];

void dfs(int cnt, int sum)
{
    if (cnt == 10)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int pre = mal[i];
        int cur = pre;
        int move = dice[cnt];

        if (turn[cur] > 0)
        {
            cur = turn[cur];
            move--;
        }
        while (move--)
            cur = arr[cur];

        if (check[cur] && cur != 21)
            continue;

        mal[i] = cur;
        check[pre] = false;
        check[cur] = true;
        dfs(cnt + 1, sum + score[cur]);
        mal[i] = pre;
        check[pre] = true;
        check[cur] = false;
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
        scanf("%d", &dice[i]);

    for (int i = 0; i < 21; i++)
        arr[i] = i + 1;
    arr[21] = 21; // 종료 지점
    arr[22] = 23, arr[23] = 24, arr[24] = 25;
    arr[25] = 26, arr[26] = 27, arr[27] = 20;
    arr[28] = 29, arr[29] = 25;
    arr[30] = 31, arr[31] = 32, arr[32] = 25;

    turn[5] = 30, turn[10] = 28, turn[15] = 22;

    for (int i = 0; i < 21; i++)
        score[i] = i * 2;

    score[22] = 28, score[23] = 27, score[24] = 26;
    score[25] = 25, score[26] = 30, score[27] = 35;
    score[28] = 22, score[29] = 24;
    score[30] = 13, score[31] = 16, score[32] = 19;

    dfs(0, 0);
    printf("%d", ans);
    return 0;
}