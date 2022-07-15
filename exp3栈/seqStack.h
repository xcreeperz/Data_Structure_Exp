#ifndef S
#define S

#include <iostream>
using namespace std;

#endif

template <typename T>
class sStack{
private:
    T val[100];
    int top;
public:
    sStack(){
        top = 0;
    }
    void push(T c){
        val[top++] = c;
    }
    T pop(){
        return val[--top];
    }
    bool empty(){
        return (top == 0);
    }
    int get_top(){
        return top;
    }
    T get(int n){
        return val[n];
    }
    T topn(){
        if(!empty()){
            return get(get_top() - 1);
        }
    }
};

// 1. 进制转换
void trans(int num, int base){
    sStack<char> s;
    char c;
    while (num > 0){
        int i = num % base;
        if (i < 10){
            c = '0' + i;
        }
        else{
            c = 'A' + i - 10;
        }
        s.push(c);
        num /= base;
    }

    cout << "转换后: " << endl;
    while (!s.empty()){
        cout << s.pop();
    }
}

// 2. 括号匹配
void match(char c[]){
    int i = 0;
    sStack<char> s;

    while (c[i] != '\0'){
        if (c[i] == '(' || c[i] == ')' || c[i] == '[' || c[i] == ']' || c[i] == '{' || c[i] == '}'){
            s.push(c[i]);
        }
        int n = s.get_top();
        if (n >= 2){
            int check = s.get(n - 1) - s.get(n - 2);
            if (check == 1 || check == 2){
                s.pop();
                s.pop();
            }
        }
        i++;
    }
    if (s.empty()){
        cout << "匹配";
    }else{
        cout << "不匹配";
    }
}

// 3. 所有序列

sStack<int> s2;
int out[100];
int outnum = 0;
int in = 1;

// n 是处理序列总数，outnum当前已出栈个数，out出栈序列待遍历输出，in是处理序列当前所在位置。s2记录栈当前位置
void dfs(int n){
    if (outnum == n){
        for (int i = 0; i < outnum; i++){
            cout << out[i] << " ";
        }
        cout << endl;
        return;
    }
    if (!s2.empty()){
        out[outnum++] = s2.pop();
        dfs(n);
        s2.push(out[--outnum]);
    }
    if (in <= n){
        s2.push(in);
        in++;
        dfs(n);
        in--;
        s2.pop();
    }
}

// 4. 合法输出

bool legal(int n[]){
    sStack<int> s;
    int in = 1, out;
    for (int i = 0; n[i] != -1; i++){
        out = n[i];
        while (in <= out){
            s.push(in);
            in++;
        }
        if (out == s.topn()){
            s.pop();
        }
        else{
            return false;
        }
    }
    return true;
}

//5. 计算式
void calc(char expr[]){
    sStack<int> nums;
    sStack<char> signs;
    bool isNum = false;
    int i = 0;
    int tmpn;
    char tmpc;
    while(expr[i] != '\0'){
        if(expr[i] >= '0' && expr[i] <= '9'){
            if(isNum){
                tmpn = nums.pop();
                nums.push(tmpn * 10 + expr[i] - '0');   //已有数字就加一位
            }else{
                nums.push(expr[i] - '0');   //上一个是符号就重新压入数字
            }
            isNum = true;
            i++;
        }else{
            isNum = false;
            if(signs.empty()){
                signs.push(expr[i]);
                i++;
                continue;
            }
            char tmpc = signs.topn();    //获取当前栈顶的符号
            if(expr[i] == '('){
                signs.push(expr[i++]);
                continue;               //上括号有最高的入栈优先级，和最低的出栈优先级，上括号入栈后不进行操作，直接读取下一个字符
            }
            //其他情况取栈顶符号讨论
            if(tmpc == '('){
                if(expr[i] == ')'){     
                    signs.pop();        //检测到前面是上括号时，除了下括号都不能出栈，必须入栈
                    i++;
                }else{
                    signs.push(expr[i++]);
                }
            } else if(tmpc == '+' || tmpc == '-'){      //排除了所有栈顶是括号的情况
                if(expr[i] == '+' || expr[i] == '-' || expr[i] == ')' || expr[i] == '#'){
                    switch(tmpc){
                        case '+':
                            tmpn = nums.pop();
                            nums.push(nums.pop() + tmpn);
                            signs.pop();
                            break;
                        case '-':
                            tmpn = nums.pop();
                            nums.push(nums.pop() - tmpn);
                            signs.pop();
                            break;
                    }
                    signs.push(expr[i++]);
                } else if(expr[i] == '*' || expr[i] == '/'){
                    signs.push(expr[i++]);
                }
                
            } else if(tmpc == '*' || tmpc == '/'){
                tmpn = nums.pop();
                if(tmpc == '*'){
                    nums.push(nums.pop() * tmpn);
                } else{
                    nums.push(nums.pop() / tmpn);
                }
                signs.pop();
            
            } else if(tmpc == ')'){
                signs.pop();
                signs.pop();
            } else{
                signs.pop();
            }
        }
    }
    cout << "结果是: " << nums.pop() << endl;
}