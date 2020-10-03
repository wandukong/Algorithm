#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

long long answer = 0;

vector<char> oper;
vector<long long> num;

vector<char> order{'*', '+', '-'};

void solution(string expression)
{
    string temp = "";
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            num.push_back(stoi(temp));
            temp = "";
            oper.push_back(expression[i]);
        }
        else
            temp += expression[i];
    }
    num.push_back(stoi(temp));

    do
    {
        vector<long long> temp_num = num;
        vector<char> temp_oper = oper;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < temp_oper.size(); j++)
            {
                if (order[i] == temp_oper[j])
                {
                    long long temp = 0;
                    if (temp_oper[j] == '*')
                        temp = temp_num[j] * temp_num[j + 1];
                    else if (temp_oper[j] == '+')
                        temp = temp_num[j] + temp_num[j + 1];
                    else if (temp_oper[j] == '-')
                        temp = temp_num[j] - temp_num[j + 1];

                    temp_num.erase(temp_num.begin() + j, temp_num.begin() + j + 2);    // 피연산자 2개 제거
                    temp_num.insert(temp_num.begin() + j, temp);                       // 피연산하여 생긴 값 삽입
                    temp_oper.erase(temp_oper.begin() + j, temp_oper.begin() + j + 1); // 사용한 연산자 제거
                    j = -1;                                                            // 붙어있는 같은 연산자가 있을 수 있기 때문에 다시 처음부터 돌림.
                }
            }
        }
        if (answer < abs(temp_num[0]))
            answer = abs(temp_num[0]);
    } while (next_permutation(order.begin(), order.end()));
}

int main()
{
    string expression = "100-200*300-500+20";
    solution(expression);
    printf("%lld\n", answer);

    return 0;
}