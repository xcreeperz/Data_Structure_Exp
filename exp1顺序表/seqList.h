#include <iostream>

using namespace std;

const int N = 1000;
//结构体保存数组和顺序表长度
struct List{
	int a[1000];
	int n;
};

//插入函数
void insert(List& l, int i, int x){
	//超出顺序表长度输出错误
	if(i >= l.n || i < 0){
		cout << "error" << endl;
	}
	//指定位置后的元素全部后移一位
	else{
		for(int j = l.n; j > i; j--){
			l.a[j] = l.a[j - 1];
		}
		l.a[i] = x;
		l.n++;
		cout << "插入后: ";
		for(int i = 0; i < l.n; i++){
			cout << l.a[i] << " ";
		}
	}
	
}

//删除函数
void del(List& l, int i){
	//超出顺序表长度输出错误
	if(i >= l.n || i < 0){
		cout << "error";
	}
	//指定位置后的元素全部前移一位
	else{
		while(i < l.n - 1){
			l.a[i] = l.a[i + 1];
			i++;
		}
		l.n--;
		cout << "删除后: ";
		for(int i = 0; i < l.n; i++){
			cout << l.a[i] << " ";
		}
	}
}

//顺序插入
void seq_insert(List& l, int x){
	int i = 0, j = l.n - 1;
	//大于最大，插入末尾
	if(x > l.a[l.n - 1]){
		l.n++;
		l.a[l.n - 1] = x;
	}else{
		//小于最小，插入首位
		if(x < l.a[0]) i = 0;
		else{
			//中间，用二分查找插入位置
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
	cout << "插入后: ";
	for(int i = 0; i < l.n; i++){
		cout << l.a[i] << " ";
	}
	
}

//奇偶分列
void separate(List& l){
	int odd[200], even[200], oddcnt = 0, evencnt = 0;
	cout << "原列表:" << endl;
	//边输出原列表边分拣
	for(int i = 0; i < l.n; i++){
		if(l.a[i] % 2) odd[oddcnt++] = l.a[i];
		else even[evencnt++] = l.a[i]; 
		cout << l.a[i] << " ";
	}
	cout << endl << "奇数列表:" << endl;
	for(int i = 0; i < oddcnt; i++){
		cout << odd[i] << " ";
	}
	cout << endl << "偶数列表:" << endl;
	for(int i = 0; i < evencnt; i++){
		cout << even[i] << " ";
	}
}

//公共元素
void publ(List& l1, List& l2, List& l3){
	int i = 0, j = 0, cnt = 0;
	//有空集则返回
	if(l1.n == 0 || l2.n == 0) return;
	//哪边小就移动哪边，相等就记录
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

//去重
int pdel(List& l){
	int i = 0, j = 1, cnt = 0;
	//从遇到重复开始移动元素
	bool flag = false;
	//双指针算法，相同就跳过，不相同就移动
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

//并集
void merge(List& l1, List& l2){
	//双指针算法
	int i = 0, j = 0;
	while(j < l2.n){
		//L1数小于L2，跳过，指针后移
		if(l1.a[i] < l2.a[j]) i++;
		//L1数大于L2，L2数添加到L1末尾，指针后移
		if(l1.a[i] > l2.a[j]){
			l1.a[l1.n++] = l2.a[j++];
		}
		//相等，指针同时后移
		if(l1.a[i] == l2.a[j]){
			i++;
			j++;
		}
	}
}

//差集
void diff(List &l1, List &l2, List &l3){
	int i = 0, j = 0, n3 = 0;
	//双指针算法
	while(i < l1.n && j < l2.n){
		//L1元素小于L2，L1添加到L3
		if(l1.a[i] < l2.a[j]){
			l3.a[n3++] = l1.a[i++];
		}
		//L1元素大于L2，跳过，L2元素必不属于L1
		if(l1.a[i] > l2.a[j]){
			j++;
		}
		//L1等于L2，跳过，从L1中去除
		if(l1.a[i] == l2.a[j]){
			i++;
			j++;
		}
	}
	//L1中还有剩余，加入L3
	while(i < l1.n){
		l3.a[n3++] = l1.a[i++];
	}

}

//判断L1是L2的子集
bool isSon(List &l1, List &l2){
	//子集不可能更大
	if(l1.n > l2.n) return false;
	int i = 0, j = 0;
	bool flag = true;
	while(i < l1.n && j < l2.n){
		//L1当前元素大于L2，暂时判false，L2右移
		if(l1.a[i] > l2.a[j]){
			j++;
			flag = false;
		}
		//有匹配元素，暂时判true
		else if(l1.a[i] == l2.a[j]){
			i++;
			j++;
			flag = true;
		}
		//L1当前元素小于L2，说明L2升序遍历没有这个元素，直接返回false
		else if(l1.a[i] < l2.a[j]){
			return false;
		}
	}
	//如果循环结束，返回最后一次判断
	return flag;
}

//中位数
int midN(List &l1, List &l2){
	int len = l1.n + l2.n;
	//int L = len + 1 >> 1;
	//动态数组，节省空间
	int* l3 = new int[len];
	int n3 = 0;
	int i = 0, j = 0;
	while(i < l1.n && j < l2.n){
		//归并排序算法得到L3
		if(l1.a[i] < l2.a[j]) l3[n3++] = l1.a[i++];
		if(l1.a[i] > l2.a[j]) l3[n3++] = l2.a[j++];
		if(l1.a[i] == l2.a[j]){
			l3[n3++] = l1.a[i++];
			j++;
		}
	}
	//取L3中间的元素，向上取整
	return l3[n3 + 1 >> 1];
}