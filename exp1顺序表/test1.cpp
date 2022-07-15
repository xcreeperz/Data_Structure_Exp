#include "seqList.h"

int main(void){
	struct List A, C;
	int m;
	cout << "输入顺序表长度:" << endl;
	cin >> m;
	A.n = m;
	cout << "输入顺序表: " << endl;
	for(int i = 0; i < A.n; i++){
		cin >> A.a[i];
	}
	int i, x, c;
	cout << "1.随机插入	2.删除	3.顺序插入	4.奇偶分列	5.公共元素	6.删除重复" << endl;
	cout << "7.合并成集合	8.交集	9.并集		10.差集		11.判断子集	12.中位数" << endl;
	cin >> c;
	if(c == 1){
		cout << "输入插入位置和插入值:" << endl;
		cin >> i >> x;
		insert(A, i, x);
	}else if(c == 2){
		cout << "输入删除位置:" << endl;
		cin >> i;
		del(A, i);
	}else if(c == 3){
		cout << "输入插入元素:" << endl;
		cin >> x;
		seq_insert(A, x);
	}else if(c == 4){
		separate(A);
	}else if(c == 5 || c == 8){
		cout << "输入第二个顺序表长度:" << endl;
		cin >> m;
		struct List B;
		B.n = m;
		cout << "输入元素: ";
		for(int i = 0; i < m; i++){
			cin >> B.a[i];
		}
		publ(A, B, C);
		cout << "交集元素:" << endl;
	}else if(c == 6){
		int move = pdel(A);
		cout << "移动次数: " << move << endl;
	}else if(c == 7 || c == 9){
		cout << "输入第二个顺序表长度:" << endl;
		cin >> m;
		struct List B;
		B.n = m;
		cout << "输入元素: ";
		for(int i = 0; i < m; i++){
			cin >> B.a[i];
		}
		merge(A, B);
		cout << "合并集合:" << endl;
	}else if(c == 10){
		cout << "输入第二个顺序表长度:" << endl;
		cin >> m;
		struct List B;
		B.n = m;
		cout << "输入元素: ";
		for(int i = 0; i < m; i++){
			cin >> B.a[i];
		}
		diff(A, B, C);
		cout << "差集是:" << endl;
	}else if(c == 11){
		cout << "输入第二个顺序表长度:" << endl;
		cin >> m;
		struct List B;
		B.n = m;
		cout << "输入元素: ";
		for(int i = 0; i < m; i++){
			cin >> B.a[i];
		}
		bool p = isSon(A, B);
		if(p){
			cout << "是子集" << endl;
		}else{
			cout << "不是子集" << endl;
		}
	}else if(c == 12){
		cout << "输入第二个顺序表长度:" << endl;
		cin >> m;
		struct List B;
		B.n = m;
		cout << "输入元素: ";
		for(int i = 0; i < m; i++){
			cin >> B.a[i];
		}
		int res = midN(A, B);
		cout << "中位数是: " << res << endl;
	}

	if(c >= 7 && c <= 10){
		for(int i = 0; i < A.n; i++){
			cout << A.a[i] << " ";
		}
	}else if(c == 6){
		cout << "去重后:" << endl;
		for(int i = 0; i < A.n; i++){
			cout << A.a[i] << " ";
		}
	}else if(c == 5 || c == 10){
		for(int i = 0; i < C.n; i++){
			cout << C.a[i] << " ";
		}
	}
}
