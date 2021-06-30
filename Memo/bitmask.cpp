#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int items_flag = 0;

    int opt0 = 1 << 0;
    int opt1 = 1 << 1;
    int opt2 = 1 << 2;
    int opt3 = 1 << 3;

    int items_flag = 0;

    // ��Ʈ �ѱ� : | , +
    items_flag |= opt0;
    printf("opt0 ȹ�� => ��� : %s\n", bitset<8>(items_flag).to_string().c_str());
    items_flag |= opt3;
    printf("opt3 ȹ�� => ��� : %s\n", bitset<8>(items_flag).to_string().c_str());

    // ��Ʈ ���� : & ~
    items_flag &= ~opt3;
    printf("opt3 ���� => ��� : %s\n", bitset<8>(items_flag).to_string().c_str());

    // ��Ʈ �����ִ��� Ȯ��
    if (items_flag & opt0)
        cout << "opt1 ���� ����" << endl;
    else
        cout << "opt1 ���� ���� ����" << endl;

    if (items_flag & opt3)
        cout << "opt1 ���� ����" << endl;
    else
        cout << "opt1 ���� ���� ����" << endl;

    // obtain item2, item3
    items_flag |= (opt2 | opt3);
    printf("opt2, opt3 ȹ��  => ��� : %s\n", bitset<8>(items_flag).to_string().c_str());

    // xor ������ : ��Ʈ ���(1->0, 0->1)
    items_flag ^= opt0;
    items_flag ^= opt1;
    printf("opt0, opt1 ��Ʈ ��� => ��� : %s\n", bitset<8>(items_flag).to_string().c_str());

    return 0;
}