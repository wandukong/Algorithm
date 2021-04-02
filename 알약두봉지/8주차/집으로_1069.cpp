#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

double X, Y, D, T, d, ans;
int main()
{
    scanf("%lf %lf %lf %lf", &X, &Y, &D, &T);
    d = sqrt(pow(X, 2) + pow(Y, 2));
    if (d < D)
        ans = min(d, min(2 * T, T + D - d));
    else
    {

        int jump = d / D;
        ans = min(d, min((jump + 1) * T, jump * T + d - jump * D));
    }
    printf("%.10lf", ans);
    return 0;
}