#include <iostream>
#include <algorithm>

using namespace std;

int H, W, N, arr[1001][1001];

int main()
{
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            scanf("%d ", &arr[i][j]);

    return 0;
}