#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct pNode {
	char data;
	int parent;

}PTNode;

//���ṹ
typedef struct pTree {
	PTNode ND[200];
	int n;	//�����
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

//˫�׹�ϵ
bool CreateTreeFromFile(char fileName[], pTree &T) {
	FILE* pFile;     //����˳�����ļ�ָ��
	char str[1000] = {0};  //��Ŷ���һ���ı����ַ���
	int i = 0, j = 0;
	pFile = fopen(fileName, "r");
	if (!pFile) {
		printf("�ļ���ʧ�ܣ�\n");
		return false;
	}
	
	int nNum = 0;
	int ni = 0;
	//��ȡ����б��������������	
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
		cout << "�ļ�Ϊ�գ�\n";
		fclose(pFile);
		return false;
	}
	
	//���ж�ȡ���Ӷ�
	int iP;  //����������±�
	int iC;  //�ӽ�������±�

	char Nf, Ns; //���ӽ��Ե��������
	while (fgets(str, 1000, pFile) != NULL) {
		ni = 0;
		if(str[ni] == 0){
			fclose(pFile); //�ر��ļ�
			return false;
		}
		Nf = str[ni];  //�������ĸ

		ni += 2;
		if(str[ni] == 0){
			printf("��ȡ��֧���ݴ���\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		Ns = str[ni];  //�ӽ����ĸ

		//�ڽ���������ҵ�������±�		
		for (iP = 0; iP < nNum; iP++) {
			if (T.ND[iP].data == Nf)
				break;
		}
		//�ҵ��ӽ���±�		
		for (iC = 0; iC < nNum; iC++) {
			if (T.ND[iC].data == Ns)
				break;
		}

		T.ND[iC].parent = iP;	//���ָ���ϵ
	}

	T.n = nNum;  //�������Ľ����Ϊ��ȡ���ĸ���

	fclose(pFile); //�ر��ļ�
	return true;
}

//ȡ�ø��±����firstChild
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

//ȡ�ø��±����nextSibling
int findNS(pTree &T, int v) {
	int i;
	for (i = v + 1; i < T.n; i++) {
		if (T.ND[v].parent == T.ND[i].parent)
			return i;
	}
	return -1;
}

//�Ը��±��㽨����������ϵ
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

//�����걸�Ķ�����
bool Tree::createTree() {
	pTree Ttst;
	char filename[100];
	cout << "�����ļ���:";
	cin >> filename;
	cin.get();
	if (CreateTreeFromFile(filename, Ttst)) {
		cout << "�����ɹ���" << endl;
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


//ɭ�ֵ��������
void Tree::pre(csnode *T) {
	if (T) {
		cout << T -> data << " ";
		pre(T -> firstChild);
		pre(T -> nextSibling);
	}
}

//ɭ�ֵĺ���������൱�ڶ����������������
void Tree::post(csnode *T) {
	if (T) {
		post(T -> firstChild);
		cout << T -> data << " ";
		post(T -> nextSibling);
	}
}

//ɭ�ֵĲ�α���
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

//��ɭ�ָ߶�
int Tree::ForeH(csnode *T) {
	if (T==NULL) {	//������
		return 0;
	}
	return MX(ForeH(T -> firstChild) + 1, ForeH(T -> nextSibling));
}

//��ɭ��Ҷ����
int Tree::NLeaf(csnode *T) {
	if (T == NULL) {	//������
		return 0;
	}

	if (T && T -> firstChild == NULL) {		//Ҷ��
		return 1 + NLeaf(T -> nextSibling);
	}

	if (T) {	//����
		return NLeaf(T -> firstChild) + NLeaf(T -> nextSibling);
	}
}

//��ɭ�ֵĶ�
void Tree::FDeg(csnode *T, int i, int &res) {
	if (T) {
		res = MX(res, i);
		FDeg(T -> firstChild, 1, res);
		FDeg(T -> nextSibling, i + 1, res);
	}
}

//����������ֵ�����κš�
void Tree::nnlevel(csnode *T, int i) {
	if (T) {
		printf("(%c, %d)", T -> data, i);
		nnlevel(T -> firstChild, i + 1);
		nnlevel(T -> nextSibling, i);
	}
}

//���������ʾ����
void Tree::toList(csnode *T, int k) {
	if (T) {
		if (k == 1) { //��TΪfirstChild��ɭ�ָ����ʱ
			cout << '(' << T -> data;
		}
		if (k == 2) {//��TΪnextSiblingʱ
			cout << ',' << T -> data;
		}
		toList(T -> firstChild, 1);
		if (T -> nextSibling == NULL) { //��TΪ�Ը����Ϊ�������������һ������ʱ
			cout << ")";
		}
		toList(T -> nextSibling, 2);
	}
}