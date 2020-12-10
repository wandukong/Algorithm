#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, ans, con;
    scanf("%d", &a);

    ans = a / 5;
    con = a % 5;
    if (ans > 0)
    {
        while (ans > 0)
        {
            if (con % 3 == 0)
            {
                ans += con / 3;
                break;
            }
            else
            {
                ans--;
                con += 5;
            }
        }
    }
    if (ans == 0)
    {
        if (a % 3 == 0)
        {
            ans = a / 3;
            printf("%d\n", ans);
            return 0;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    else
        printf("%d\n", ans);
}