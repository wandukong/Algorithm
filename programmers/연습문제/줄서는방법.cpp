// https : //programmers.co.kr/learn/courses/30/lessons/12936

#include <string>
#include <vector>

using namespace std;
vector<int> number;

long long fact(int num)
{
    long long result = 1;
    for (int i = 1; i <= num; i++)
        result *= i;
    return result;
}

vector<int> solution(int n, long long k)
{
    vector<int> answer;
    for (int i = 1; i <= n; i++)
        number.push_back(i);
    k -= 1;
    while (n > 0)
    {
        long long slice = fact(n - 1);
        int idx = k / slice;
        answer.push_back(number[idx]);
        number.erase(number.begin() + idx);
        k %= slice;
        n--;
    }
    return answer;
}

void print(int n, int k, vector<int> answer)
{
    vector<int> test = solution(n, k);

    bool chk = true;
    for (int i = 0; i < answer.size(); i++)
        if (test[i] != answer[i])
            chk = false;

    if (chk)
        printf("정답\n");
    else
        printf("오답\n");
}

int main()
{
    print(3, 5, {3, 1, 2});
    return 0;
}