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
    cout << "选择: 1. 顺序栈; 2. 链栈" << endl;
    cin >> selstack;
    cout << "1. 进制转换    2. 括号匹配     3. 出栈序列     4. 判断合法     5. 求解表达式" << endl;
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
        cout << "输入十进制数: ";
        cin >> num;
        cout << "输入转换进制: ";
        cin >> sys;
        trans(num, sys);
        break;

    case 2:
        cout << "输入表达式: " << endl;
        cin >> expr;
        match(expr);
        break;

    case 3:
        cout << "输入序列长度n: " << endl;
        cin >> n;
        cout << "所有合法的输出序列如下: " << endl;
        dfs(n);
        break;

    case 4:
        cout << "输入1-n的序列，以-1结束: " << endl;
        for (int i = 0;; i++){
            cin >> in[i];
            if (in[i] == -1)
                break;
        }
        res = legal(in);
        if (res){
            cout << "合法" << endl;
        }else{
            cout << "非法" << endl;
        }
        break;

    case 5:
        cout << "输入计算式，以##包围: " << endl;
        cin >> expr;
        calc(expr);
        break;

    case 6:
        cout << "输入十进制数: ";
        cin >> num;
        cout << "输入转换进制: ";
        cin >> sys;
        ltrans(num, sys);
        break;

    case 7:
        cout << "输入表达式: " << endl;
        cin >> expr;
        lmatch(expr);
        break;

    case 8:
        cout << "输入序列长度n: " << endl;
        cin >> n;
        cout << "所有合法的输出序列如下: " << endl;
        ldfs(n);
        break;
    }

    return 0;
}