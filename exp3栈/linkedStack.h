#ifndef L
#define L

#include <iostream>
using namespace std;

#endif

template<typename T>
struct Node{
    T val;
    Node* next;
    int tn;
};

template<typename T>
class lStack{
    private:
        Node<T> *top;
        int tn;
    public:
        lStack(){
            top = NULL;
            tn = 0;
        }
        void push(T x){
            Node<T> *n = new Node<T>;
            n -> val = x;
            n -> next = top;
            top = n;
            tn++;
        }
        T pop(){
            if(!empty()){
                T v = top -> val;
                Node<T> *u = top;
                top = top -> next;
                delete u;
                tn--;
                return v;
            }
        }
        bool empty(){
            return (tn == 0);
        }
        T get_top(){
            return top -> val;
        }
        T get_ntop(){
            return top -> next -> val;
        }
        int get_tn(){
            return tn;
        }
};

//1. 进制转换
void ltrans(int num, int base){
    lStack<char> l;
    char c;
    while(num > 0){
        int i = num % base;
        if(i < 10){
            c = '0' + i;
        }else{
            c = 'A' + i - 10;
        }
        l.push(c);
        num /= base;
    }

    cout << "转换后: "<< endl;
    while(!l.empty()){
        cout << l.pop();
    }
}

bool lmatch(char c[]){
    int i = 0;
    lStack<char> l;

    while(c[i] != '\0'){
        if(c[i] == '(' || c[i] == ')' || c[i] == '[' || c[i] == ']' || c[i] == '{' || c[i] == '}'){
            l.push(c[i]);
        }
        int n = l.get_tn();
        if(n >= 2){
            int check = l.get_top() - l.get_ntop();
            if(check == 1 || check == 2){
                l.pop();
                l.pop();
            }
        }
        i++;
    }
    if(l.empty()){
        cout << "匹配";
    }else{
        cout << "不匹配";
    }
}

lStack<int> l2;
int lout[100];
int loutnum = 0;
int lin = 1;
void ldfs(int n){
    if(loutnum == n){
        for(int i = 0; i < loutnum; i++){
            cout << lout[i] << " ";
        }
        cout << endl;
        return;
    }
    if(!l2.empty()){
        lout[loutnum++] = l2.pop();
        ldfs(n);
        l2.push(lout[--loutnum]);
    }
    if(lin <= n){
        l2.push(lin);
        lin++;
        ldfs(n);
        lin--;
        l2.pop();
    }
}