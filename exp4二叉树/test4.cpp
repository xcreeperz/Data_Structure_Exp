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

    cout << "�����ļ�������������: " << endl;
    cin >> fName;
    if(!FileToArray(fName, strLine, nArrlen)){
        cout << "��ȡ�ļ�ʧ��" << endl;
        return 1;
    }

    if(!CreateBiTree(A, NULL, strLine, nArrlen, nRow)){
        cout << "����������ʧ��" << endl;
        return 1;
    }
    cout << "�����ɹ���" << endl;
    // cout << A << endl;
    // cout << A -> val << endl;

while(true){
    int c;
    cout << endl << "1. �������ֵ�Ͳ��    2. ��Ҷ�Ӻ� 1 �Ƚ����  3. �󸸽��|�ֵܽ��|�ӽ��" << endl;
    cout << "4. ��Ԫ�صĲ��        5. ˳����ת��������     6. Ҷ�ӵ�����·��" << endl;
    cout << "7. ������ӡ������      8. ���ƶ�����           9. �������Һ���     10.��ͬ����" << endl;
    cout << "11. �˳�����" << endl;
    cout << "���������: ";
    cin >> c;
    //system("cls");
    if(c == 11){
        break;
    }

    switch(c){
        case 1:
            cout << "����������(��δ� 1 ��ʼ): " << endl;
            Mid(A, 0);
            break;

        case 2:
            TDeg(A, n);
            cout << "Ҷ�ӽ��: " << leaf(A) << endl << "1 �Ƚ��: " << n << endl;
            break;
            
        case 3:
            cout << "����Ԫ�� x: ";
            cin >> x;
            family(A, x);
            break;

        case 4:
            cout << "����Ԫ�� x: ";
            cin >> x;
            depth(A, x, 1);
            break;

        case 5:
            cout << "���±�˳����������(��0��ͷ): " << endl;
            cin >> seq;
            B = new Node;
            Seq_to_Link(seq, B, 1);
            cout << "ת���������������(��δ� 1 ��ʼ): " << endl;
            Mid(B, 0);
            break;

        case 6:
            cout << "����Ҷ�ӵ�����·��: " << endl;
            path(A, A);
            break;

        case 7:
            cout << "��������Ϊ: " << endl;
            tprint(A);
            break;

        case 8:
            copy(A, B);
            cout << "���ƺ��T1: " << endl;
            Mid(B, 0);
            break;

        case 9:
            tran(A);
            cout << "�任�󰴲�����: " << endl;
            tprint(A);
            break;

        case 10:
            cout << "��������Ԫ��: " << endl;
            cin >> ca >> cb;
            Node* fa = find(A, ca);
            Node* fb = find(A, cb);
            res = ancestor(fa, fb);
            cout << "��ͬ����Ԫ��Ϊ: " << res -> val << endl;
            break;
    }
}
    return 0;
}