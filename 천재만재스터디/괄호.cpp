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
        int chk = false; // stack이 비어있는데 pop을 하려고 하는 경우
        stack<char> st;
        char str[55];
        scanf("%s", str);
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '(')
                st.push(str[i]);
            else if (str[i] == ')' && !st.empty()) // stack에 '(' 가 남아 있어서 ')'와 쌍을 이루어 pop 가능한 경우.
                st.pop();
            else if (str[i] == ')' && st.empty()) // stack에 '(' 가 남아있지 않아 pop이 불가능한 경우.
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