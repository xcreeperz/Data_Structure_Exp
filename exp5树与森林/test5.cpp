#include"treeChildSibling.h"

Tree T;

int main() {
	cout << "����ɭ��: " << endl;
	bool tr = T.createTree();
	if(tr == false){
		return 0;
	}

	system("CLS");

	int c;
	int Res = 0;

	while (true) {
		cout << "1. ���򡢺��򡢲�α���	2. ɭ�ָ߶�		3. Ҷ����" << endl;
		cout << "4. ɭ�ֵĶ�		5. ������ֵ�Ͳ�κ�	6. ������ʾ" << endl;
		cout << "7. �˳�" << endl;

		cin >> c;
		switch (c) {
			case 1:
				cout << "����: ";
				T.pre(T.treeRoot());
				cout << endl;
				cout << "����: ";
				T.post(T.treeRoot());
				cout << endl;
				cout << "���: ";
				T.level(T.treeRoot());
				cout << endl;
				break;

			case 2:
				cout << "ɭ�ֵĸ߶�: ";
				cout << T.ForeH(T.treeRoot()) << endl;
				break;
			
			case 3:
				cout << "ɭ��Ҷ����: ";
				cout << T.NLeaf(T.treeRoot()) << endl;
				break;

			case 4:
				cout << "ɭ�ֵĶ�: ";
				T.FDeg(T.treeRoot(), 0, Res);
				cout << Res << endl ;
				break;

			case 5:
				{
					cout << "����������ֵ�����κ�: ";
					T.nnlevel(T.treeRoot(), 1);
					cout << endl;
					break;
				}


			case 6:
				cout << "������ʾ����: ";
				T.toList(T.treeRoot(), 1);
				cout << endl;
				break;
			
			case 7:
				return 0;
		}
	}
	return 0;
}