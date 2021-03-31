#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int N;
string input[5];
bool check[10];
vector<vector<char>> v;
vector<vector<int>> avaliableNumber;

string number[10] = {
    "######...######",
    "..........#####",
    "#.####.#.####.#",
    "#.#.##.#.######",
    "###....#..#####",
    "###.##.#.##.###",
    "######.#.##.###",
    "#....#....#####",
    "######.#.######",
    "###.##.#.######"};

bool checkAvailable(vector<char> inputV, string numbers)
{
    for (int k = 0; k < 15; k++)
        if (inputV[k] == '#' && numbers[k] == '.')
            return false;
    return true;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < 5; i++)
        cin >> input[i];

    v.resize(N);
    avaliableNumber.resize(N);
    int idx = 0;
    for (int i = 0; i < 4 * N - 1; i++)
    {
        if (i % 4 == 3)
        {
            idx++;
            continue;
        }
        for (int j = 0; j < 5; j++)
            v[idx].push_back(input[j][i]);
    }
    for (int i = 0; i < N; i++)
    {
        bool chk = false;
        for (int j = 0; j < 10; j++)
            if (checkAvailable(v[i], number[j]))
            {
                avaliableNumber[i].push_back(j);
                chk = true;
            }
        if (!chk)
        {
            printf("-1");
            return 0;
        }
    }
    double ans = 0, g = 1;
    for (int i = N - 1; i >= 0; i--)
    {
        int temp = 0;
        for (int j = 0; j < avaliableNumber[i].size(); j++)
            temp += avaliableNumber[i][j];
        ans += g * temp / avaliableNumber[i].size();
        g *= 10;
    }
    printf("%lf", ans);
    return 0;
}