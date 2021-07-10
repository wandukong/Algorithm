#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> empty_space;
int sudoku[9][9];

void recur(int pos)
{
    if (pos == empty_space.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                printf("%d ", sudoku[i][j]);
            printf("\n");
        }
        exit(0);
    }
    int curR = empty_space[pos].first;
    int curC = empty_space[pos].second;
    int chkR = curR / 3 * 3, chkC = curC / 3 * 3;

    for (int i = 1; i <= 9; i++)
    {
        bool chkBox = false, chkSero = false, chkGaro = false;
        // 정사각형 중복 체크
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
                if (sudoku[chkR + j][chkC + k] == i)
                {
                    chkBox = true;
                    break;
                }
            if (chkBox)
                break;
        }
        if (chkBox)
            continue;
        // 세로 중복 체크
        for (int j = 0; j < 9; j++)
            if (sudoku[j][curC] == i)
            {
                chkSero = true;
                break;
            }
        if (chkSero)
            continue;
        // 가로 중복 체크
        for (int j = 0; j < 9; j++)
            if (sudoku[curR][j] == i)
            {
                chkGaro = true;
                break;
            }
        if (chkGaro)
            continue;
        sudoku[curR][curC] = i;
        recur(pos + 1);
        sudoku[curR][curC] = 0;
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j] == 0)
                empty_space.push_back({i, j});
        }
    recur(0);
    return 0;
}