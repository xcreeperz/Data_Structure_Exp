#include "BiTree.h"


int main(void){
    
    Node* A;
    Node* B;

    int n = 0;

    char x, ca, cb;

    Node* res;

    char seq[30] = {0};

    char fName[60];
    char strLine[100][3];
    int nArrlen = 0, nRow = 0;

    cout << "输入文件名创建二叉树: " << endl;
    cin >> fName;
    if(!FileToArray(fName, strLine, nArrlen)){
        cout << "读取文件失败" << endl;
        return 1;
    }

    if(!CreateBiTree(A, NULL, strLine, nArrlen, nRow)){
        cout << "创建二叉树失败" << endl;
        return 1;
    }
    cout << "创建成功！" << endl;
    // cout << A << endl;
    // cout << A -> val << endl;

while(true){
    int c;
    cout << endl << "1. 中序输出值和层次    2. 求叶子和 1 度结点数  3. 求父结点|兄弟结点|子结点" << endl;
    cout << "4. 求元素的层次        5. 顺序树转二叉链表     6. 叶子到根的路径" << endl;
    cout << "7. 遍历打印二叉树      8. 复制二叉树           9. 交换左右孩子     10.求共同祖先" << endl;
    cout << "11. 退出程序" << endl;
    cout << "输入操作数: ";
    cin >> c;
    //system("cls");
    if(c == 11){
        break;
    }

    switch(c){
        case 1:
            cout << "中序遍历结果(层次从 1 开始): " << endl;
            Mid(A, 0);
            break;

        case 2:
            TDeg(A, n);
            cout << "叶子结点: " << leaf(A) << endl << "1 度结点: " << n << endl;
            break;
            
        case 3:
            cout << "输入元素 x: ";
            cin >> x;
            family(A, x);
            break;

        case 4:
            cout << "输入元素 x: ";
            cin >> x;
            depth(A, x, 1);
            break;

        case 5:
            cout << "按下标顺序输入数组(以0开头): " << endl;
            cin >> seq;
            B = new Node;
            Seq_to_Link(seq, B, 1);
            cout << "转换后的中序遍历结果(层次从 1 开始): " << endl;
            Mid(B, 0);
            break;

        case 6:
            cout << "所有叶子到根的路径: " << endl;
            path(A, A);
            break;

        case 7:
            cout << "按层次输出为: " << endl;
            tprint(A);
            break;

        case 8:
            copy(A, B);
            cout << "复制后的T1: " << endl;
            Mid(B, 0);
            break;

        case 9:
            tran(A);
            cout << "变换后按层次输出: " << endl;
            tprint(A);
            break;

        case 10:
            cout << "输入两个元素: " << endl;
            cin >> ca >> cb;
            Node* fa = find(A, ca);
            Node* fb = find(A, cb);
            res = ancestor(fa, fb);
            cout << "共同祖先元素为: " << res -> val << endl;
            break;
    }
}
    return 0;
}