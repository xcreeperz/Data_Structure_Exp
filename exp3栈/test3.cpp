#include "seqStack.h"
#include "linkedStack.h"

int main(void)
{
    int selstack, selfunc;
    int num, sys;
    int n;
    char expr[20];
    int in[20];
    bool res;
    cout << "ѡ��: 1. ˳��ջ; 2. ��ջ" << endl;
    cin >> selstack;
    cout << "1. ����ת��    2. ����ƥ��     3. ��ջ����     4. �жϺϷ�     5. �����ʽ" << endl;
    switch (selstack){
    case 1:
        cin >> selfunc;
        system("cls");
        break;

    case 2:
        cin >> selfunc;
        selfunc += 5;
        system("cls");
        break;
    }

    switch (selfunc){
    case 1:
        cout << "����ʮ������: ";
        cin >> num;
        cout << "����ת������: ";
        cin >> sys;
        trans(num, sys);
        break;

    case 2:
        cout << "������ʽ: " << endl;
        cin >> expr;
        match(expr);
        break;

    case 3:
        cout << "�������г���n: " << endl;
        cin >> n;
        cout << "���кϷ��������������: " << endl;
        dfs(n);
        break;

    case 4:
        cout << "����1-n�����У���-1����: " << endl;
        for (int i = 0;; i++){
            cin >> in[i];
            if (in[i] == -1)
                break;
        }
        res = legal(in);
        if (res){
            cout << "�Ϸ�" << endl;
        }else{
            cout << "�Ƿ�" << endl;
        }
        break;

    case 5:
        cout << "�������ʽ����##��Χ: " << endl;
        cin >> expr;
        calc(expr);
        break;

    case 6:
        cout << "����ʮ������: ";
        cin >> num;
        cout << "����ת������: ";
        cin >> sys;
        ltrans(num, sys);
        break;

    case 7:
        cout << "������ʽ: " << endl;
        cin >> expr;
        lmatch(expr);
        break;

    case 8:
        cout << "�������г���n: " << endl;
        cin >> n;
        cout << "���кϷ��������������: " << endl;
        ldfs(n);
        break;
    }

    return 0;
}