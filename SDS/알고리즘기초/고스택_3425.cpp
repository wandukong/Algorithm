#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int N;

int main()
{
    while (true)
    {
        vector<string> command;
        vector<long long> pushingNumber;
        while (true)
        {
            string s;
            cin >> s;
            if (s == "QUIT")
                return 0;
            else if (s == "END")
                break;
            else if (s == "NUM")
            {
                string temp;
                cin >> temp;
                pushingNumber.push_back(stoi(temp));
            }
            command.push_back(s);
        }
        scanf("%d", &N);
        while (N--)
        {
            int a;
            scanf("%d", &a);
            stack<long long> st;
            st.push(a);
            bool chk = true;
            int idx = 0;
            for (int t = 0; t < command.size(); t++)
            {
                string exe = command[t];
                if (exe[0] == 'N')
                    st.push(pushingNumber[idx++]);
                else if (st.empty())
                {
                    chk = false;
                    break;
                }
                else if (exe == "POP")
                    st.pop();
                else if (exe == "INV")
                {
                    int num = st.top();
                    st.pop();
                    st.push(num * -1);
                }
                else if (exe == "DUP")
                    st.push(st.top());
                else if (st.size() < 2)
                {
                    chk = false;
                    break;
                }
                else
                {
                    long long num = st.top();
                    st.pop();
                    long long num2 = st.top();
                    st.pop();

                    if (exe == "SWP")
                    {
                        st.push(num);
                        st.push(num2);
                    }
                    else if (exe == "ADD")
                    {
                        if (abs(num2 + num) > 1000000000)
                        {
                            chk = false;
                            break;
                        }
                        st.push(num + num2);
                    }
                    else if (exe == "SUB")
                    {
                        if (abs(num2 - num) > 1000000000)
                        {
                            chk = false;
                            break;
                        }
                        st.push(num2 - num);
                    }
                    else if (exe == "MUL")
                    {
                        if (abs(num2 * num) > 1000000000)
                        {
                            chk = false;
                            break;
                        }
                        st.push(num2 * num);
                    }
                    else if (exe == "DIV")
                    {
                        if (num == 0)
                        {
                            chk = false;
                            break;
                        }
                        bool chk2 = false;
                        long long number;
                        if (num < 0)
                            chk2 = !chk2;
                        if (num2 < 0)
                            chk2 = !chk2;
                        if (chk2)
                            number = (abs(num2) / abs(num)) * -1;
                        else
                            number = abs(num2) / abs(num);
                        if (abs(number) > 1000000000)
                        {
                            chk = false;
                            break;
                        }
                        st.push(number);
                    }
                    else if (exe == "MOD")
                    {
                        if (num == 0)
                        {
                            chk = false;
                            break;
                        }
                        bool chk2 = false;
                        long long number;
                        if (num2 < 0)
                            chk2 = true;
                        if (chk2)
                            number = (abs(num2) % abs(num)) * -1;
                        else
                            number = abs(num2) % abs(num);
                        if (abs(number) > 1000000000)
                        {
                            chk = false;
                            break;
                        }
                        st.push(number);
                    }
                }
            }
            if (!chk)
                printf("ERROR\n");
            else if (st.size() == 1)
                printf("%lld\n", st.top());
            else
                printf("ERROR\n");
        }
        printf("\n");
    }
}