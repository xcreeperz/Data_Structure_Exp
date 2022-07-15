#include"treeChildSibling.h"

Tree T;

int main() {
	cout << "创建森林: " << endl;
	bool tr = T.createTree();
	if(tr == false){
		return 0;
	}

	system("CLS");

	int c;
	int Res = 0;

	while (true) {
		cout << "1. 先序、后序、层次遍历	2. 森林高度		3. 叶子数" << endl;
		cout << "4. 森林的度		5. 先序结点值和层次号	6. 广义表表示" << endl;
		cout << "7. 退出" << endl;

		cin >> c;
		switch (c) {
			case 1:
				cout << "先序: ";
				T.pre(T.treeRoot());
				cout << endl;
				cout << "后序: ";
				T.post(T.treeRoot());
				cout << endl;
				cout << "层次: ";
				T.level(T.treeRoot());
				cout << endl;
				break;

			case 2:
				cout << "森林的高度: ";
				cout << T.ForeH(T.treeRoot()) << endl;
				break;
			
			case 3:
				cout << "森林叶子数: ";
				cout << T.NLeaf(T.treeRoot()) << endl;
				break;

			case 4:
				cout << "森林的度: ";
				T.FDeg(T.treeRoot(), 0, Res);
				cout << Res << endl ;
				break;

			case 5:
				{
					cout << "先序输出结点值及其层次号: ";
					T.nnlevel(T.treeRoot(), 1);
					cout << endl;
					break;
				}


			case 6:
				cout << "广义表表示的树: ";
				T.toList(T.treeRoot(), 1);
				cout << endl;
				break;
			
			case 7:
				return 0;
		}
	}
	return 0;
}