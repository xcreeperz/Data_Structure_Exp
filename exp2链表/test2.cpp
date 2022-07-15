#include "linkedList.h"

int main(void){
    Node* A = new Node;
    A -> next = NULL;
    Node* B = new Node;
    B -> next = NULL;
    Node* C = new Node;
    C -> next = NULL;
    Node* N;

    int c, i, x, k, res_12;
    bool res_11;

    cout << "1.随机插入	2.删除	    3.顺序插入	4.奇偶分列	5.公共元素	6.删除重复" << endl;
	cout << "7.合并成集合	8.交集	    9.并集	10.差集		11.判断子集	12.找倒数第k个" << endl;
    cout << "输入操作序号: ";
	cin >> c;

        cout << "输入链表长度: ";
        cin >> A -> val;
        if(A -> val > 0){
            cout << "输入链表(下标从0开始):" << endl;
            Node* PA = A;
            for(int i = 0; i < A -> val; i++){
                N = new Node;
                N -> next = NULL;
                cin >> N -> val;
                PA -> next = N;
                PA = N;
            }
        }
        

    if(c == 5 || c == 7 || c == 8 || c == 9 || c == 10 || c == 11){
        cout << "输入第二个链表长度: ";
        cin >> B -> val;
        if(B -> val > 0){
            cout << "输入链表:" << endl;
            Node* PB = B;
            for(int i = 0; i < B -> val; i++){
                N = new Node;
                N -> next = NULL;
                cin >> N -> val;
                PB -> next = N;
                PB = N;
            }
        }
        
    }

    switch(c){

        //随机插入
        case 1:
            cout << "输入插入位置: ";
            cin >> i;
            cout << "输入插入元素: ";
            cin >> x;
            insert(A, i, x);    break;

        //随机删除
        case 2:
            cout << "输入删除位置: ";
            cin >> i;
            del(A, i);          break;

        //顺序插入
        case 3:
            cout << "输入插入元素: ";
            cin >> x;
            seq_insert(A, x);   break;

        //奇偶分列
        case 4:
            separate(A);        break;

        //公共元素
        case 5:
            publ(A, B, C);      break;

        //去重
        case 6:
            delp(A);            break;

        //合并集合
        case 7:
            merge(A, B);        break;

        //交集
        case 8:
            publ(A, B, C);      break;

        //并集
        case 9:
            merge(A, B);        break;

        //差集
        case 10:
            diff(A, B);         break;

        //判断子集
        case 11:
            res_11 = isSon(A, B);
            if(res_11) cout << "A 是 B 的子集" << endl;
            else cout << "A 不是 B 的子集" << endl;
            break;

        //倒序查找
        case 12:
            cout << "输入查找的倒数序号 k(从1开始): ";
            cin >> k;
            res_12 = find(A, k);
            if(res_12 == 0) cout << "查找错误" << endl;
            else cout << "查找成功" << endl;
            break;
    }

    return 0;
}