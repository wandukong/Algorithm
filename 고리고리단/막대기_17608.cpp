#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int n, ans = 1;
stack<int> st;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        st.push(a);
    }

    int temp = st.top();
    st.pop();

    while (!st.empty())
    {
        if (temp < st.top())
        {
            temp = st.top();
            ans++;
        }
        st.pop();
    }
    printf("%d\n", ans);

    return 0;
}