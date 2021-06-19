#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int amountA, amountB, goalA, goalB;

struct info
{
    int waterA, waterB, cnt;
};

map<pair<int, int>, int> m;

int bfs()
{
    queue<info> q;
    q.push({0, 0, 0});
    m[{0, 0}] = 1;

    while (!q.empty())
    {
        int A = q.front().waterA;
        int B = q.front().waterB;
        int cnt = q.front().cnt;
        q.pop();

        if (A == goalA && B == goalB)
            return cnt;
        for (int i = 0; i < 6; i++)
        {
            int na = A, nb = B;
            if (i == 0) // Fill A
                na = amountA;
            else if (i == 1) // Fill B
                nb = amountB;
            else if (i == 2) // Empty A
                na = 0;
            else if (i == 3) // Empty B
                nb = 0;
            else if (i == 4) // Move water from A to B
            {
                if (A <= amountB - B)
                {
                    na = 0;
                    nb = B + A;
                }
                else
                {
                    nb = amountB;
                    na = A - (amountB - B);
                }
            }
            else if (i == 5) // Move water from B to A
            {
                if (B <= amountA - A)
                {
                    na = A + B;
                    nb = 0;
                }
                else
                {
                    na = amountA;
                    nb = B - (amountA - A);
                }
            }

            if (m[{na, nb}] != 0)
                continue;

            q.push({na, nb, cnt + 1});
            m[{na, nb}] = 1;
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d %d %d", &amountA, &amountB, &goalA, &goalB);
    printf("%d", bfs());
    return 0;
}