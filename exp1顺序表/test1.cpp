#include "seqList.h"

int main(void){
	struct List A, C;
	int m;
	cout << "����˳�����:" << endl;
	cin >> m;
	A.n = m;
	cout << "����˳���: " << endl;
	for(int i = 0; i < A.n; i++){
		cin >> A.a[i];
	}
	int i, x, c;
	cout << "1.�������	2.ɾ��	3.˳�����	4.��ż����	5.����Ԫ��	6.ɾ���ظ�" << endl;
	cout << "7.�ϲ��ɼ���	8.����	9.����		10.�		11.�ж��Ӽ�	12.��λ��" << endl;
	cin >> c;
	if(c == 1){
		cout << "�������λ�úͲ���ֵ:" << endl;
		cin >> i >> x;
		insert(A, i, x);
	}else if(c == 2){
		cout << "����ɾ��λ��:" << endl;
		cin >> i;
		del(A, i);
	}else if(c == 3){
		cout << "�������Ԫ��:" << endl;
		cin >> x;
		seq_insert(A, x);
	}else if(c == 4){
		separate(A);
	}else if(c == 5 || c == 8){
		cout << "����ڶ���˳�����:" << endl;
		cin >> m;
		struct List B;
		B.n = m;
		cout << "����Ԫ��: ";
		for(int i = 0; i < m; i++){
			cin >> B.a[i];
		}
		publ(A, B, C);
		cout << "����Ԫ��:" << endl;
	}else if(c == 6){
		int move = pdel(A);
		cout << "�ƶ�����: " << move << endl;
	}else if(c == 7 || c == 9){
		cout << "����ڶ���˳�����:" << endl;
		cin >> m;
		struct List B;
		B.n = m;
		cout << "����Ԫ��: ";
		for(int i = 0; i < m; i++){
			cin >> B.a[i];
		}
		merge(A, B);
		cout << "�ϲ�����:" << endl;
	}else if(c == 10){
		cout << "����ڶ���˳�����:" << endl;
		cin >> m;
		struct List B;
		B.n = m;
		cout << "����Ԫ��: ";
		for(int i = 0; i < m; i++){
			cin >> B.a[i];
		}
		diff(A, B, C);
		cout << "���:" << endl;
	}else if(c == 11){
		cout << "����ڶ���˳�����:" << endl;
		cin >> m;
		struct List B;
		B.n = m;
		cout << "����Ԫ��: ";
		for(int i = 0; i < m; i++){
			cin >> B.a[i];
		}
		bool p = isSon(A, B);
		if(p){
			cout << "���Ӽ�" << endl;
		}else{
			cout << "�����Ӽ�" << endl;
		}
	}else if(c == 12){
		cout << "����ڶ���˳�����:" << endl;
		cin >> m;
		struct List B;
		B.n = m;
		cout << "����Ԫ��: ";
		for(int i = 0; i < m; i++){
			cin >> B.a[i];
		}
		int res = midN(A, B);
		cout << "��λ����: " << res << endl;
	}

	if(c >= 7 && c <= 10){
		for(int i = 0; i < A.n; i++){
			cout << A.a[i] << " ";
		}
	}else if(c == 6){
		cout << "ȥ�غ�:" << endl;
		for(int i = 0; i < A.n; i++){
			cout << A.a[i] << " ";
		}
	}else if(c == 5 || c == 10){
		for(int i = 0; i < C.n; i++){
			cout << C.a[i] << " ";
		}
	}
}
