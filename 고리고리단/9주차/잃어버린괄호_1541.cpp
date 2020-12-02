#include <algorithm>
#include <iostream>

using namespace std;

string s, temp;
bool chk = false;
int ans;

int main()
{
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-')
        {
            if (!chk)
                ans += stoi(temp);
            else
                ans -= stoi(temp);

            if (s[i] == '-')
                chk = true;

            temp = "";
        }
        else
            temp += s[i];
    }
    if (!chk)
        ans += stoi(temp);
    else
        ans -= stoi(temp);

    printf("%d\n", ans);
    return 0;
}