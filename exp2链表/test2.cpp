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

    cout << "1.�������	2.ɾ��	    3.˳�����	4.��ż����	5.����Ԫ��	6.ɾ���ظ�" << endl;
	cout << "7.�ϲ��ɼ���	8.����	    9.����	10.�		11.�ж��Ӽ�	12.�ҵ�����k��" << endl;
    cout << "����������: ";
	cin >> c;

        cout << "����������: ";
        cin >> A -> val;
        if(A -> val > 0){
            cout << "��������(�±��0��ʼ):" << endl;
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
        cout << "����ڶ���������: ";
        cin >> B -> val;
        if(B -> val > 0){
            cout << "��������:" << endl;
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

        //�������
        case 1:
            cout << "�������λ��: ";
            cin >> i;
            cout << "�������Ԫ��: ";
            cin >> x;
            insert(A, i, x);    break;

        //���ɾ��
        case 2:
            cout << "����ɾ��λ��: ";
            cin >> i;
            del(A, i);          break;

        //˳�����
        case 3:
            cout << "�������Ԫ��: ";
            cin >> x;
            seq_insert(A, x);   break;

        //��ż����
        case 4:
            separate(A);        break;

        //����Ԫ��
        case 5:
            publ(A, B, C);      break;

        //ȥ��
        case 6:
            delp(A);            break;

        //�ϲ�����
        case 7:
            merge(A, B);        break;

        //����
        case 8:
            publ(A, B, C);      break;

        //����
        case 9:
            merge(A, B);        break;

        //�
        case 10:
            diff(A, B);         break;

        //�ж��Ӽ�
        case 11:
            res_11 = isSon(A, B);
            if(res_11) cout << "A �� B ���Ӽ�" << endl;
            else cout << "A ���� B ���Ӽ�" << endl;
            break;

        //�������
        case 12:
            cout << "������ҵĵ������ k(��1��ʼ): ";
            cin >> k;
            res_12 = find(A, k);
            if(res_12 == 0) cout << "���Ҵ���" << endl;
            else cout << "���ҳɹ�" << endl;
            break;
    }

    return 0;
}