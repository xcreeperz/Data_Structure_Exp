#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct pNode {
	char data;
	int parent;

}PTNode;

//树结构
typedef struct pTree {
	PTNode ND[200];
	int n;	//结点数
}pTree;

typedef struct CSNode {
	char data;
	struct CSNode *firstChild, *nextSibling;
}csnode;

class Tree {
	private:
		csnode *root;
	public:
		bool createTree();
		csnode*& treeRoot() { return root; }
		void pre(csnode *T);
		void post(csnode *T);
		void level(csnode *T);
		int ForeH(csnode *T);
		int NLeaf(csnode *T);
		void FDeg(csnode *T,int i,int &re);
		void nnlevel(csnode *T,int i);
		void toList(csnode *T,int k);
};

//双亲关系
bool CreateTreeFromFile(char fileName[], pTree &T) {
	FILE* pFile;     //定义顺序表的文件指针
	char str[1000] = {0};  //存放读出一行文本的字符串
	int i = 0, j = 0;
	pFile = fopen(fileName, "r");
	if (!pFile) {
		printf("文件打开失败！\n");
		return false;
	}
	
	int nNum = 0;
	int ni = 0;
	//读取结点列表，存入树结点数组	
	if (fgets(str, 1000, pFile) != NULL) {
		while(str[ni] != 0){
			T.ND[nNum].data = str[ni];
		 	T.ND[nNum].parent = -1;
			ni += 2;
			nNum++;
		}
		cout << "ok" << endl;
	}
	else {
		cout << "文件为空！\n";
		fclose(pFile);
		return false;
	}
	
	//逐行读取父子对
	int iP;  //父结点数组下标
	int iC;  //子结点数组下标

	char Nf, Ns; //父子结点对的两个结点
	while (fgets(str, 1000, pFile) != NULL) {
		ni = 0;
		if(str[ni] == 0){
			fclose(pFile); //关闭文件
			return false;
		}
		Nf = str[ni];  //父结点字母

		ni += 2;
		if(str[ni] == 0){
			printf("读取分支数据错误！\n");
			fclose(pFile); //关闭文件
			return false;
		}
		Ns = str[ni];  //子结点字母

		//在结点数组中找到父结点下标		
		for (iP = 0; iP < nNum; iP++) {
			if (T.ND[iP].data == Nf)
				break;
		}
		//找到子结点下标		
		for (iC = 0; iC < nNum; iC++) {
			if (T.ND[iC].data == Ns)
				break;
		}

		T.ND[iC].parent = iP;	//标记指向关系
	}

	T.n = nNum;  //更新树的结点数为读取到的个数

	fclose(pFile); //关闭文件
	return true;
}

//取得该下标结点的firstChild
int findFC(pTree &T, int v) {
	int w;
	if (v == -1) {
		return -1;
	}
	for (w = 0; w < T.n; w++) {
		if (T.ND[w].parent == v) {
			return w;
		}
	}
	return -1;
}

//取得该下标结点的nextSibling
int findNS(pTree &T, int v) {
	int i;
	for (i = v + 1; i < T.n; i++) {
		if (T.ND[v].parent == T.ND[i].parent)
			return i;
	}
	return -1;
}

//对该下标结点建立二叉树关系
void createBi(csnode *&T, pTree &T1, int v) {
	int w;
	T = new csnode;
	T -> data = T1.ND[v].data;
	T -> firstChild = NULL;
	T -> nextSibling = NULL;

	w = findFC(T1, v);
	if (w != -1) {
		createBi(T -> firstChild, T1, w);
	}
	w = findNS(T1, v);
	if (w != -1) {
		createBi(T->nextSibling, T1, w);
	}
}

//建立完备的二叉树
bool Tree::createTree() {
	pTree Ttst;
	char filename[100];
	cout << "输入文件名:";
	cin >> filename;
	cin.get();
	if (CreateTreeFromFile(filename, Ttst)) {
		cout << "创建成功！" << endl;
	}else{
		return 0;
	}
	int rt;
	for (rt = 0; rt < Ttst.n; rt++) {
		if (Ttst.ND[rt].parent == -1)
			break;
	}
	if (rt < Ttst.n) {
		createBi(root, Ttst, rt);
	}
	return 1;
}


//森林的先序遍历
void Tree::pre(csnode *T) {
	if (T) {
		cout << T -> data << " ";
		pre(T -> firstChild);
		pre(T -> nextSibling);
	}
}

//森林的后序遍历（相当于二叉树的中序遍历）
void Tree::post(csnode *T) {
	if (T) {
		post(T -> firstChild);
		cout << T -> data << " ";
		post(T -> nextSibling);
	}
}

//森林的层次遍历
void Tree::level(csnode *T) {
	csnode* CQ[50];
	int hq = 0, tq = 0;
	CQ[tq++] = T;
	csnode *s = T -> nextSibling;
	while (s) {
		CQ[tq++] = s;
		s = s -> nextSibling;
	}
	while (hq < tq) {
		csnode *u = CQ[hq++];
		cout << u -> data << " ";
		s = u -> firstChild;
		while (s) {
			CQ[tq++] = s;
			s = s -> nextSibling;
		}
	}
}

int MX(int a, int b){
	if(a >= b){
		return a;
	}else{
		return b;
	}
}

//求森林高度
int Tree::ForeH(csnode *T) {
	if (T==NULL) {	//不存在
		return 0;
	}
	return MX(ForeH(T -> firstChild) + 1, ForeH(T -> nextSibling));
}

//求森林叶子数
int Tree::NLeaf(csnode *T) {
	if (T == NULL) {	//不存在
		return 0;
	}

	if (T && T -> firstChild == NULL) {		//叶子
		return 1 + NLeaf(T -> nextSibling);
	}

	if (T) {	//其他
		return NLeaf(T -> firstChild) + NLeaf(T -> nextSibling);
	}
}

//求森林的度
void Tree::FDeg(csnode *T, int i, int &res) {
	if (T) {
		res = MX(res, i);
		FDeg(T -> firstChild, 1, res);
		FDeg(T -> nextSibling, i + 1, res);
	}
}

//先序输出结点值及其层次号。
void Tree::nnlevel(csnode *T, int i) {
	if (T) {
		printf("(%c, %d)", T -> data, i);
		nnlevel(T -> firstChild, i + 1);
		nnlevel(T -> nextSibling, i);
	}
}

//输出广义表表示的树
void Tree::toList(csnode *T, int k) {
	if (T) {
		if (k == 1) { //当T为firstChild或森林根结点时
			cout << '(' << T -> data;
		}
		if (k == 2) {//当T为nextSibling时
			cout << ',' << T -> data;
		}
		toList(T -> firstChild, 1);
		if (T -> nextSibling == NULL) { //当T为以父结点为根的子树的最后一个孩子时
			cout << ")";
		}
		toList(T -> nextSibling, 2);
	}
}