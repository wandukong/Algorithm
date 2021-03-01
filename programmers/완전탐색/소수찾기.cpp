#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool prime[10000001];
bool check[7];
int ans;
string str;
string numbers;

void search(int location, string curStr)
{
    if (location == str.size())
        return;

    for (int i = 0; i < str.size(); i++)
    {
        if (!check[i])
        {
            check[i] = true;
            curStr += str[i];
            if (prime[stoi(curStr)])
            {
                ans++;
                prime[stoi(curStr)] = false;
            }
            if (curStr[0] != '0')
                search(location + 1, curStr);
            check[i] = false;
            curStr = curStr.substr(0, location).c_str();
        }
    }
}

int main()
{
    cin >> numbers;
    int answer = 0;
    str = numbers;

    for (int i = 2; i < 10000001; i++)
        prime[i] = true;

    for (int i = 2; i * i <= 10000001; i++)
    {
        if (prime[i])
            for (int j = i * i; j <= 10000001; j += i)
                prime[j] = false;
    }
    search(0, "");
    printf("%d\n", ans);
    return 0;
}