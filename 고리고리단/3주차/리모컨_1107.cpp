#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int num, n, ans;
vector<int> exc; // 고장난 버튼

int main()
{
    scanf("%d", &num);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        exc.push_back(a);
    }

    ans = abs(num - 100); // 가장 많은 버튼을 눌러야 할때 : + 혹은 - 버트만 사용 가능한 경우
    for (int i = 0; i <= 500000 * 2; i++)
    {
        bool chk = false;
        string cur = to_string(i);
        for (int j = 0; j < cur.size(); j++)
        {
            if (find(exc.begin(), exc.end(), (int)cur[j] - 48) - exc.begin() != exc.size()) // 숫자 중에 고장난 버튼이 있는 경우
            {
                chk = true;
                break;
            }
        }
        if (!chk)
        {
            string pushNumber = to_string(i);
            ans = ans > pushNumber.size() + abs(num - i) ? pushNumber.size() + abs(num - i) : ans;
        }
    }
    if (num == 100)
        ans = 0;
    printf("%d\n", ans);

    return 0;
}