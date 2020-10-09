#include <algorithm>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

int tc;

int main()
{

    scanf("%d", &tc);
    while (tc--)
    {
        int chk = false; // stack�� ����ִµ� pop�� �Ϸ��� �ϴ� ���
        stack<char> st;
        char str[55];
        scanf("%s", str);
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '(')
                st.push(str[i]);
            else if (str[i] == ')' && !st.empty()) // stack�� '(' �� ���� �־ ')'�� ���� �̷�� pop ������ ���.
                st.pop();
            else if (str[i] == ')' && st.empty()) // stack�� '(' �� �������� �ʾ� pop�� �Ұ����� ���.
            {
                chk = true;
                break;
            }
        }
        if (chk)
            printf("NO\n");
        else if (st.empty())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}