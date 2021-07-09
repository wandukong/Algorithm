#include <iostream>
#include <algorithm>
#define MOD 100000
using namespace std;

int w, h, dp[101][101][2][2]; // [xÁÂÇ¥][yÁÂÇ¥][²ª±â°¡´É¿©ºÎ][¹æÇâ]

int main()
{
    scanf("%d%d", &w, &h);
    for (int i = 2; i <= w; i++)
        dp[1][i][0][1] = 1;
    for (int i = 2; i <= h; i++)
        dp[i][1][0][0] = 1;
    for (int i = 2; i <= h; i++)
        for (int j = 2; j <= w; j++)
        {
            dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][1][0]) % MOD; //  ²ª³¢°¡´É ¡è = ²ª±â°¡´É ¡è + ²ª±âºÒ°¡´É ¡è
            dp[i][j][0][1] = (dp[i][j - 1][0][1] + dp[i][j - 1][1][1]) % MOD; //  ²ª±â°¡´É ¡æ = ²ª±â°¡´É ¡æ + ²ª±âºÒ°¡´É ¡æ
            dp[i][j][1][0] = dp[i - 1][j][0][1] % MOD;                        //  ²ª³¢ºÒ°¡´É(ÀÌ¹Ì²ªÀ½) ¡è = ²ª±â°¡´É ¡æ
            dp[i][j][1][1] = dp[i][j - 1][0][0] % MOD;                        //  ²ª³¢ºÒ°¡´É(ÀÌ¹Ì²ªÀ½) ¡æ = ²ª±â°¡´É ¡è
        }
    printf("%d", (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % MOD);
    return 0;
}