#include <iostream>
#include <string.h>

using namespace std;

struct Node{
    char val;
    Node *lc, *rc, *parent;
};

bool FileToArray(char fileName[], char strLine[100][3], int & nArrLen){       // fileName[]����ļ���
	// strLine[][3]��Ž��Ķ�ά���飬��Ӧ�����ļ���3��
	// nArrLen���ض�����������
	FILE* pFile;
	char str[1000];
	pFile = fopen(fileName, "r");
	if(!pFile){
		cout << "�����������ļ���ʧ�ܣ�" << endl;
		return false;
	}
	if(fgets(str, 1000, pFile) != NULL){
		if(strcmp(str, "BinaryTree\n") != 0){
			cout << "�򿪵��ļ���ʽ����" << endl;
			fclose(pFile);
			return false;
		}
	}

	nArrLen = 0;
	while(fscanf(pFile, "%c  %c  %c\n", &strLine[nArrLen][0], &strLine[nArrLen][1], &strLine[nArrLen][2]) != EOF)	
	{
		//cout << strLine[nArrLen][0] << ' ' << strLine[nArrLen][1] << ' ' << strLine[nArrLen][1]<<endl;
		nArrLen++;
	}	//����������
	fclose(pFile);
	//cout << "�ļ���ȡ���" << endl;
	return true;
}

bool CreateBiTree(Node*& pBT, Node* par, char strLine[100][3], int nLen, int &nRow){
	    //nLen--������
	    //nRow--���鵱ǰ�к�
	if((nRow >= nLen) || (nLen == 0))
		return false;

	//cout << "����: " << pBT << " ";
	pBT = new Node;  //���������
	pBT -> val = strLine[nRow][0];
	//cout << "��ֵ: " << pBT -> val << " ";
	pBT -> lc = NULL;
	pBT -> rc = NULL;
	//cout << pBT -> val << endl;
	pBT -> parent = par;
	//cout << "��: " << par << endl;
	int nRowNext = nRow;         //�������εݹ���к�	
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

//Ѱ��ֵΪ x �Ľ��
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

//1.����������ֵ�Ͳ����
void Mid(Node* T, int i){
    if(T){
        Mid(T -> lc, i + 1);
        cout << "--> ֵ: " << T -> val << "(���: " << i + 1 << ") ";
        Mid(T -> rc, i + 1);
    }
}

//2. ��Ҷ������ 1 ����
int leaf(Node *T) {
	if (T) {
		if (T->lc == NULL && T->rc == NULL) {
			return 1;//��ǰ����޺��ӣ��򷵻�1
		}
		return leaf(T -> lc) + leaf(T -> rc);
	}
	return 0;	//���ڲ����ڵĽ�㣬����0
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

//3. �󸸽�㣬�ֵܽ�㣬�ӽ��
void family(Node* T, char e){
    Node* dd = find(T, e);
    Node* pp;

    if(dd -> parent){
        pp = dd -> parent;
        cout << "�����: " << pp -> val << endl;
    }else{
        cout << "����㲻����" << endl;
    }

    if(pp){
        if (pp -> lc == dd && pp -> rc) {
				cout << "���ֵܽ��: " << pp -> rc -> val  << endl;
		}else if(pp -> rc == dd && pp -> lc){
				cout << "���ֵܽ��: " << pp -> lc -> val  << endl;
		}else{
				cout << "���ֵܽ��" << endl;
		}
    }

    if(dd -> lc){
        cout << "���ӽ��: " << dd -> lc -> val << endl;
    }else{
        cout << "������" << endl;
    }
    if(dd -> rc){
        cout << "�Һ��ӽ��: " << dd -> rc -> val << endl;
    }else{
        cout << "���Һ���" << endl;
    }

}

//4. �����в��
//bool found = false;
void depth(Node* T, char e, int i){
	if(T){
    	if(T -> val == e){
			cout << "���Ϊ: " << i << endl;
			//found = true;
		}else{
			depth(T -> lc, e, i + 1);
			depth(T -> rc, e, i + 1);
		}
	}
}

//5. ˳����תΪ����
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

//6. Ҷ�ӵ�����·��
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

//7. ������ӡ
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

//8. ����
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

//9. �任���Һ���
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

//10. ��ͬ����
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