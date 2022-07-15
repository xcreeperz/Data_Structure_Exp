#include <iostream>

using namespace std;

const int N = 1000;
//�ṹ�屣�������˳�����
struct List{
	int a[1000];
	int n;
};

//���뺯��
void insert(List& l, int i, int x){
	//����˳������������
	if(i >= l.n || i < 0){
		cout << "error" << endl;
	}
	//ָ��λ�ú��Ԫ��ȫ������һλ
	else{
		for(int j = l.n; j > i; j--){
			l.a[j] = l.a[j - 1];
		}
		l.a[i] = x;
		l.n++;
		cout << "�����: ";
		for(int i = 0; i < l.n; i++){
			cout << l.a[i] << " ";
		}
	}
	
}

//ɾ������
void del(List& l, int i){
	//����˳������������
	if(i >= l.n || i < 0){
		cout << "error";
	}
	//ָ��λ�ú��Ԫ��ȫ��ǰ��һλ
	else{
		while(i < l.n - 1){
			l.a[i] = l.a[i + 1];
			i++;
		}
		l.n--;
		cout << "ɾ����: ";
		for(int i = 0; i < l.n; i++){
			cout << l.a[i] << " ";
		}
	}
}

//˳�����
void seq_insert(List& l, int x){
	int i = 0, j = l.n - 1;
	//������󣬲���ĩβ
	if(x > l.a[l.n - 1]){
		l.n++;
		l.a[l.n - 1] = x;
	}else{
		//С����С��������λ
		if(x < l.a[0]) i = 0;
		else{
			//�м䣬�ö��ֲ��Ҳ���λ��
			do{
				int mid = i + j >> 1;
				if(l.a[mid] > x) j = mid;
				else i = mid + 1;
			}while(i < j);
		}
		for(int k = l.n; k > i; k--){
			l.a[k] = l.a[k - 1];
		}
		l.a[i] = x;
		l.n++;
	}
	cout << "�����: ";
	for(int i = 0; i < l.n; i++){
		cout << l.a[i] << " ";
	}
	
}

//��ż����
void separate(List& l){
	int odd[200], even[200], oddcnt = 0, evencnt = 0;
	cout << "ԭ�б�:" << endl;
	//�����ԭ�б�߷ּ�
	for(int i = 0; i < l.n; i++){
		if(l.a[i] % 2) odd[oddcnt++] = l.a[i];
		else even[evencnt++] = l.a[i]; 
		cout << l.a[i] << " ";
	}
	cout << endl << "�����б�:" << endl;
	for(int i = 0; i < oddcnt; i++){
		cout << odd[i] << " ";
	}
	cout << endl << "ż���б�:" << endl;
	for(int i = 0; i < evencnt; i++){
		cout << even[i] << " ";
	}
}

//����Ԫ��
void publ(List& l1, List& l2, List& l3){
	int i = 0, j = 0, cnt = 0;
	//�пռ��򷵻�
	if(l1.n == 0 || l2.n == 0) return;
	//�ı�С���ƶ��ıߣ���Ⱦͼ�¼
	while(i < l1.n, j < l2.n){
		if(l1.a[i] < l2.a[j]) i++;
		if(l1.a[i] > l2.a[j]) j++;
		if(l1.a[i] == l2.a[j]){
			l3.a[cnt++] = l1.a[i++];
			j++;
		}
	}
	l3.n = cnt;
}

//ȥ��
int pdel(List& l){
	int i = 0, j = 1, cnt = 0;
	//�������ظ���ʼ�ƶ�Ԫ��
	bool flag = false;
	//˫ָ���㷨����ͬ������������ͬ���ƶ�
	while(i < l.n && j < l.n){
		if(l.a[i] == l.a[j]){
			j++;
			flag = true;
		}else{
			if(i + 1 == j){
				i++;
				j++;
			}else{
				l.a[++i] = l.a[j];
				j++;
			}
			if(flag) cnt++;
		}
	}
	l.n = i + 1;
	return cnt;
}

//����
void merge(List& l1, List& l2){
	//˫ָ���㷨
	int i = 0, j = 0;
	while(j < l2.n){
		//L1��С��L2��������ָ�����
		if(l1.a[i] < l2.a[j]) i++;
		//L1������L2��L2����ӵ�L1ĩβ��ָ�����
		if(l1.a[i] > l2.a[j]){
			l1.a[l1.n++] = l2.a[j++];
		}
		//��ȣ�ָ��ͬʱ����
		if(l1.a[i] == l2.a[j]){
			i++;
			j++;
		}
	}
}

//�
void diff(List &l1, List &l2, List &l3){
	int i = 0, j = 0, n3 = 0;
	//˫ָ���㷨
	while(i < l1.n && j < l2.n){
		//L1Ԫ��С��L2��L1��ӵ�L3
		if(l1.a[i] < l2.a[j]){
			l3.a[n3++] = l1.a[i++];
		}
		//L1Ԫ�ش���L2��������L2Ԫ�رز�����L1
		if(l1.a[i] > l2.a[j]){
			j++;
		}
		//L1����L2����������L1��ȥ��
		if(l1.a[i] == l2.a[j]){
			i++;
			j++;
		}
	}
	//L1�л���ʣ�࣬����L3
	while(i < l1.n){
		l3.a[n3++] = l1.a[i++];
	}

}

//�ж�L1��L2���Ӽ�
bool isSon(List &l1, List &l2){
	//�Ӽ������ܸ���
	if(l1.n > l2.n) return false;
	int i = 0, j = 0;
	bool flag = true;
	while(i < l1.n && j < l2.n){
		//L1��ǰԪ�ش���L2����ʱ��false��L2����
		if(l1.a[i] > l2.a[j]){
			j++;
			flag = false;
		}
		//��ƥ��Ԫ�أ���ʱ��true
		else if(l1.a[i] == l2.a[j]){
			i++;
			j++;
			flag = true;
		}
		//L1��ǰԪ��С��L2��˵��L2�������û�����Ԫ�أ�ֱ�ӷ���false
		else if(l1.a[i] < l2.a[j]){
			return false;
		}
	}
	//���ѭ���������������һ���ж�
	return flag;
}

//��λ��
int midN(List &l1, List &l2){
	int len = l1.n + l2.n;
	//int L = len + 1 >> 1;
	//��̬���飬��ʡ�ռ�
	int* l3 = new int[len];
	int n3 = 0;
	int i = 0, j = 0;
	while(i < l1.n && j < l2.n){
		//�鲢�����㷨�õ�L3
		if(l1.a[i] < l2.a[j]) l3[n3++] = l1.a[i++];
		if(l1.a[i] > l2.a[j]) l3[n3++] = l2.a[j++];
		if(l1.a[i] == l2.a[j]){
			l3[n3++] = l1.a[i++];
			j++;
		}
	}
	//ȡL3�м��Ԫ�أ�����ȡ��
	return l3[n3 + 1 >> 1];
}