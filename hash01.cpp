#include <iostream>
using namespace std;


const int n = 5;

struct phtu
{
    int khoa;
    struct phtu *next;
};

typedef struct phtu phantu;

phantu *t[n];

int h(int x)
{
    return x%n;
}


void print()
{
    int i;
    phantu *p;
    for(i = 0; i < n; i++)
    {
        p = t[i];
        cout <<"lop thu  " << i << " : " ;
        if( p == NULL)
        {
            cout <<"NULL";
        }
        else {
        while(p!=NULL)
        {
            cout << p->khoa << " - ";
            p = p->next;
             
        }


        }

        cout << endl;
    }
}



int findx(int x)
{
    int i ;
    phantu *p;
    int ok= 0;;
    if(t[h(x)]== NULL)
    {
        ok = 0;
    }
    else
    {
        p = t[h(x)];
        while(p!=NULL && !ok)
        {
            if(p->khoa == x)
            {
                ok = 1;
            }
            else
            {
                p = p->next;
            }
        }
    }
    return ok;
}



int insert(int x)
{
    int i ;
    phantu *p;
    if(findx(x))
    {
        cout <<x <<" da co trong dic " << endl;
        return 0;
    }
    else {
    i = h(x);
    p = new phantu;
    p->khoa = x;
    p->next = t[i];
    t[i] = p;
    }
}


void xoa(int x)
{
    int i, thay =0 ;
    phantu *p, *q;
    if(!findx(x))
    {
        cout <<x <<" khong ton tai trong tu dien ma xoa " << endl;
    }
    else {
    i = h(x);
    q = t[i];
    p =new phantu;
    if(q->khoa == x) 
    {
        //p = new phantu;
        p = t[i];
        t[i] = t[i]->next;
        delete p;

    }
    else
     {
    q = t[i];
    p = q->next;
    thay = 0;
    while(p!=NULL && !thay )
    {
        if(p->khoa ==x)
        {
            cout << " khoa : " << p->khoa << endl;
            q->next = p->next;
            thay = 1;
            delete p;
        }
        else {
        q = p; p = p->next;
        }

    }

    }
}
}


int main()
{
    int i, chon , x;
    for(i = 0; i< n; i++)
    {
        t[i] = NULL;
    }

    do {
    cout <<" chon 1.chen 2.xoa 3.tim 4.in 5.thoat" ; 
    cin >> chon ;
    switch(chon)
    {
        case 1 : cout <<" moi nhap gia tri can chen : " ;
        cin >> x; insert(x) ; break;
        case 2 : cout <<"moi ban nhap gia tri  can xoa : ";
        cin >> x; xoa(x) ; break;
        case 3 : cout <<"moi ban nhap gia tri can tim : ";
        cin >> x; if(findx(x)) cout << " da tim thay "; else cout <<" not found " << endl;
        break;
        case 4 : print(); break;        
    }
    }while (chon <= 4 && chon >= 1);
}
