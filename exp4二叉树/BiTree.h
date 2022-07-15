#include <iostream>
#include <string.h>

using namespace std;

struct Node{
    char val;
    Node *lc, *rc, *parent;
};

bool FileToArray(char fileName[], char strLine[100][3], int & nArrLen){       // fileName[]存放文件名
	// strLine[][3]存放结点的二维数组，对应数据文件的3列
	// nArrLen返回二叉树结点个数
	FILE* pFile;
	char str[1000];
	pFile = fopen(fileName, "r");
	if(!pFile){
		cout << "二叉树数据文件打开失败！" << endl;
		return false;
	}
	if(fgets(str, 1000, pFile) != NULL){
		if(strcmp(str, "BinaryTree\n") != 0){
			cout << "打开的文件格式错误！" << endl;
			fclose(pFile);
			return false;
		}
	}

	nArrLen = 0;
	while(fscanf(pFile, "%c  %c  %c\n", &strLine[nArrLen][0], &strLine[nArrLen][1], &strLine[nArrLen][2]) != EOF)	
	{
		//cout << strLine[nArrLen][0] << ' ' << strLine[nArrLen][1] << ' ' << strLine[nArrLen][1]<<endl;
		nArrLen++;
	}	//读入结点数据
	fclose(pFile);
	//cout << "文件读取完毕" << endl;
	return true;
}

bool CreateBiTree(Node*& pBT, Node* par, char strLine[100][3], int nLen, int &nRow){
	    //nLen--结点个数
	    //nRow--数组当前行号
	if((nRow >= nLen) || (nLen == 0))
		return false;

	//cout << "本体: " << pBT << " ";
	pBT = new Node;  //建立根结点
	pBT -> val = strLine[nRow][0];
	//cout << "数值: " << pBT -> val << " ";
	pBT -> lc = NULL;
	pBT -> rc = NULL;
	//cout << pBT -> val << endl;
	pBT -> parent = par;
	//cout << "父: " << par << endl;
	int nRowNext = nRow;         //保留本次递归的行号	
	if(strLine[nRowNext][1] == '1')  {
		nRow++;
		pBT -> lc = new Node;
		CreateBiTree(pBT -> lc, pBT, strLine, nLen, nRow);
	}
	if(strLine[nRowNext][2] == '1')  {
		nRow++;
		pBT -> rc = new Node;
		CreateBiTree(pBT -> rc, pBT, strLine, nLen, nRow);
	}
	return true;
}

//寻找值为 x 的结点
Node* find(Node* T, char x){
    if(T){
        if(T -> val == x){
			//cout << "found" << endl;
            return T;
        }
		Node* Tr;
		if(Tr = find(T -> lc, x)) return Tr;
		if(Tr = find(T -> rc, x)) return Tr;
    }
    return NULL;
}

//1.中序输出结点值和层次数
void Mid(Node* T, int i){
    if(T){
        Mid(T -> lc, i + 1);
        cout << "--> 值: " << T -> val << "(层次: " << i + 1 << ") ";
        Mid(T -> rc, i + 1);
    }
}

//2. 求叶子数和 1 度数
int leaf(Node *T) {
	if (T) {
		if (T->lc == NULL && T->rc == NULL) {
			return 1;//当前结点无孩子，则返回1
		}
		return leaf(T -> lc) + leaf(T -> rc);
	}
	return 0;	//对于不存在的结点，返回0
}
void TDeg(Node *T,int &i) {
	if(T){
		if((T -> lc && !T -> rc) || (!T -> lc && T -> rc)){
			i++;
		}
	}
	if (T) {
		TDeg(T->lc, i);
		TDeg(T->rc, i);
	}
}

//3. 求父结点，兄弟结点，子结点
void family(Node* T, char e){
    Node* dd = find(T, e);
    Node* pp;

    if(dd -> parent){
        pp = dd -> parent;
        cout << "父结点: " << pp -> val << endl;
    }else{
        cout << "父结点不存在" << endl;
    }

    if(pp){
        if (pp -> lc == dd && pp -> rc) {
				cout << "右兄弟结点: " << pp -> rc -> val  << endl;
		}else if(pp -> rc == dd && pp -> lc){
				cout << "左兄弟结点: " << pp -> lc -> val  << endl;
		}else{
				cout << "无兄弟结点" << endl;
		}
    }

    if(dd -> lc){
        cout << "左孩子结点: " << dd -> lc -> val << endl;
    }else{
        cout << "无左孩子" << endl;
    }
    if(dd -> rc){
        cout << "右孩子结点: " << dd -> rc -> val << endl;
    }else{
        cout << "无右孩子" << endl;
    }

}

//4. 求树中层次
//bool found = false;
void depth(Node* T, char e, int i){
	if(T){
    	if(T -> val == e){
			cout << "层次为: " << i << endl;
			//found = true;
		}else{
			depth(T -> lc, e, i + 1);
			depth(T -> rc, e, i + 1);
		}
	}
}

//5. 顺序树转为链树
Node* Seq_to_Link(char OT[], Node* NT, int i){
	if(i > 1){
		NT = new Node;
	}
	NT -> val = OT[i];
	if(OT[2 * i] != 0){
		NT -> lc = Seq_to_Link(OT, NT -> lc, 2 * i);
	}else{
		NT -> lc = NULL;
	}
	if(OT[2 * i + 1] != 0){
		NT -> rc = Seq_to_Link(OT, NT -> rc, 2 * i + 1);
	}else{
		NT -> rc = NULL;
	}
	return NT;
}

//6. 叶子到根的路径
void path(Node* root, Node* T){
	if(T){
		if(!T -> lc && !T -> rc){
			Node* l = T;
			while(l != root){
				cout << l -> val << " -> ";
				l = l -> parent;
			}
			cout << root -> val << endl;
		}
		path(root, T -> lc);
		path(root, T -> rc);
	}
}

//7. 遍历打印
void tprint(Node* T){
	Node* queue[20];
	int h = 0, t = 0;
	queue[t++] = T;
	while(h < t){
		Node* n = queue[h++];
		cout << n -> val << " ";

		if(n -> lc) queue[t++] = n -> lc;
		if(n -> rc) queue[t++] = n -> rc;
	}
}

//8. 复制
void copy(Node* T, Node*& T1){
	if(T){
		T1 = new Node;
		T1 -> val = T -> val;
		T1 -> lc = NULL;
		T1 -> rc = NULL;

		copy(T -> lc, T1 -> lc);
		copy(T -> rc, T1 -> rc);
	}
}

//9. 变换左右孩子
void tran(Node* T){
	if(T -> lc || T -> rc){
		Node* tmp = T -> lc;
		T -> lc = T -> rc;
		T -> rc = tmp;
		if(T -> lc){
			tran(T -> lc);
		}
		if(T -> rc){
			tran(T -> rc);
		}
	}
}

//10. 求共同祖先
Node* ancestor(Node* A, Node* B){
    Node* stackA[20];
	int topA = -1;
	Node* stackB[20];
	int topB = -1;
	while(A -> parent){
		stackA[++topA] = A;
		A = A -> parent;
	}
	while(B -> parent){
		stackB[++topB] = B;
		B = B -> parent;
	}
	while(stackA[topA] == stackB[topB]){
		topA--;
		topB--;
	}
	return stackA[topA] -> parent;
}