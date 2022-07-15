#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

// 1.随机插入
void insert(Node *h, int i, int x)
{
    if (h->val < i)
    {
        cout << "error";
    }
    else
    {
        if (h->val == i)
        {
            Node *s = h->next;
            while (s->next != NULL)
            {
                s = s->next;
            }
            Node *n = new Node;
            n->next = NULL;
            n->val = x;
            s->next = n;
            h->val++;
        }
        else
        {
            int cnt = 0;
            Node *s = h;
            while (cnt < i)
            {
                s = s->next;
                cnt++;
            }
            Node *n = new Node;
            n->val = x;
            n->next = s->next;
            s->next = n;
            h->val++;
        }
        cout << "插入后: " << endl;
        while (h->next != NULL)
        {
            h = h->next;
            cout << h->val << " ";
        }
    }
}

// 2.随机删除
void del(Node *h, int i)
{
    if (h->val <= i)
    {
        cout << "error";
    }
    else
    {
        int cnt = 0;
        Node *s = h;
        while (cnt < i)
        {
            s = s->next;
            cnt++;
        }
        Node *d = s->next;
        s->next = d->next;
        delete d;
        h->val--;

        cout << "删除后: " << endl;
        while (h->next != NULL)
        {
            h = h->next;
            cout << h->val << " ";
        }
    }
}

// 3.有序插入
void seq_insert(Node *h, int x)
{
    Node *s = h;
    Node *p;
    bool find = false;
    do
    {
        p = s;
        s = s->next;
        if (s->val >= x)
        {
            find = true;
        }
    } while (s->val < x && s->next != NULL);

    if (find)
    {
        Node *n = new Node;
        n->val = x;
        n->next = s;
        p->next = n;
        h->val++;
    }
    else
    {
        Node *n = new Node;
        n->val = x;
        n->next = NULL;
        s->next = n;
        h->val++;
    }
    cout << "插入后: " << endl;
    while (h->next != NULL)
    {
        h = h->next;
        cout << h->val << " ";
    }
}

// 4.奇偶分列
void separate(Node *h)
{
    if (h->val > 0)
    {
        Node *odd = new Node;
        odd->next = NULL;
        Node *even = new Node;
        even->next = NULL;
        Node *s = h->next;
        while (s != NULL)
        {
            if (s->val % 2)
            {
                Node *n = new Node;
                n->val = s->val;
                n->next = odd->next;
                odd->next = n;
            }
            else
            {
                Node *n = new Node;
                n->val = s->val;
                n->next = even->next;
                even->next = n;
            }
            s = s->next;
        }
        cout << "奇数列: ";
        while (odd->next != NULL)
        {
            odd = odd->next;
            cout << odd->val << " ";
        }
        cout << endl
             << "偶数列: ";
        while (even->next != NULL)
        {
            even = even->next;
            cout << even->val << " ";
        }
    }
}

// 5 & 8.求公共元素（未测试）
void publ(Node *h1, Node *h2, Node *h3)
{
    if (h1->val == 0 || h2->val == 0)
    {
        cout << "无公共元素" << endl;
    }
    else
    {
        h1 = h1->next;
        h2 = h2->next;
        while (h1->next != NULL && h2->next != NULL)
        {
            if (h1->val < h2->val)
            {
                h1 = h1->next;
            }
            if (h1->val > h2->val)
            {
                h2 = h2->next;
            }
            if (h1->val == h2->val)
            {
                Node *n = new Node;
                n->val = h1->val;
                n->next = h3->next;
                h3->next = n;
                if (h1->next != NULL && h2->next != NULL)
                {
                    h1 = h1->next;
                    h2 = h2->next;
                }
            }
        }
        cout << "公共元素: " << endl;
        while (h3->next != NULL)
        {
            h3 = h3->next;
            cout << h3->val << " ";
        }
    }
}

// 6.去重（时间性能最好，意思是不要空间了吗）
void delp(Node *h)
{
    Node *p;
    Node *del;
    p = h->next;
    while (p->next != NULL)
    {
        if (p->val == p->next->val)
        {
            del = p->next;
            p->next = p->next->next;
            delete del;
        }
        else
        {
            p = p->next;
        }
    }
    cout << "去重后: " << endl;
    while (h->next != NULL)
    {
        h = h->next;
        cout << h->val << " ";
    }
}

// 7 & 9.合并集合（未测试）
void merge(Node *h1, Node *h2)
{
    if (h1->val == 0)
    {
        h1->next = h2->next;
        delete h2;
    }
    else if (h2->val == 0)
    {
        delete h2;
    }
    else
    {
        Node *p1 = h1->next;
        Node *p2 = h2->next;
        Node *mark;
        do
        {
            if (p1->val > p2->val)
            {
                mark = p2;
                p2 = p2->next;
                mark->next = h1->next;
                h1->next = mark;
            }
            else if (p1->val < p2->val)
            {
                p1 = p1->next;
            }
            else if (p1->val == p2->val)
            {
                if (p1->next != NULL && p2->next != NULL)
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }
        } while (p1 != NULL && p2 != NULL);
    }

    cout << "合并后: " << endl;
    while (h1->next != NULL)
    {
        h1 = h1->next;
        cout << h1->val << " ";
    }
}

// 10.差集
void diff(Node *h1, Node *h2)
{
    if (h1->val == 0)
    {
        cout << "A为空集" << endl;
        return;
    }
    if (h2->val == 0)
    {
        cout << "B为空集" << endl;
    }
    else
    {
        Node *p1 = h1, *c1 = p1->next;
        Node *c2 = h2->next;
        while (c1 != NULL && c2 != NULL)
        {
            if (c1->val < c2->val)
            {
                c1 = c1->next;
                p1 = p1->next;
            }
            else if (c1->val > c2->val)
            {
                c2 = c2->next;
            }
            else if (c1->val == c2->val)
            {
                p1->next = c1->next;
                c1 = c1->next;
                c2 = c2->next;
            }
        }
    }
    cout << "差集结果: " << endl;
    while (h1->next != NULL)
    {
        h1 = h1->next;
        cout << h1->val << " ";
    }
}

// 11.判断子集
bool isSon(Node *h1, Node *h2)
{
    if (h1->val > h2->val)
    {
        return false;
    }
    bool flag = false;
    Node *p1 = h1->next;
    Node *p2 = h2->next;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->val > p2->val)
        {
            p2 = p2->next;
            flag = false;
        }
        else if (p1->val < p2->val)
        {
            return false;
        }
        else if (p1->val == p2->val)
        {
            flag = true;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return flag;
}

// 12.找倒数第k个（我寻思一开始头结点存个数据不就解决了）
int find(Node *h, int k)
{
    int n = h->val;
    if (k > n)
    {
        cout << "error" << endl;
        return 0;
    }
    else
    {
        int cnt = 0;
        int i = n - k;
        Node *s = h->next;
        while (cnt < i)
        {
            s = s->next;
            cnt++;
        }
        cout << "倒数第" << k << "个数是: " << s->val << endl;
        return 1;
    }
}