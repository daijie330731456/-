#include <iostream>
#include <string>

using namespace std;

void draw(int maxK,int num)
{
    cout << '+';
    int len = 2*maxK-1;
    for(int i=0;i<len;i++)
        cout << '-';
    cout << '+' << endl; //第一行
    for(int i=2;i<=num;i++)
    {
        for(int j=0;j<i-2;j++)
            cout << ' ';
        cout << '|' << '+';
        len = 2*maxK-2*i+1;
        for(int j=0;j<len;j++)
            cout << '-';
        cout << '+' << '|' << endl;
    } //第2至n行
    for(int i=0;i<num-1;i++)
        cout << ' ';
    cout << '|';
    len = 2*maxK-2*num+1;
    for(int i=0;i<len;i++)
        cout << ' ';
    cout << '|' << endl; //第n+1行
    cout << endl; //空行
    for(int i=0;i<num-1;i++)
        cout << ' ';
    cout << '|';
    len = 2*maxK-2*num+1;
    for(int i=0;i<len;i++)
        cout << ' ';
    cout << '|' << endl; //与n+1行对称
    for(int i=1;i<num;i++)
    {
        len = num-i-1;
        for(int j=0;j<len;j++)
            cout << ' ';
        cout << '|' << '+';
        for(int j=0;j<2*i-1;j++)
            cout << '-';
        cout << '+' << '|' << endl;
    } //对称
    cout << '+';
    len = 2*maxK-1;
    for(int i=0;i<len;i++)
        cout << '-';
    cout << '+' << endl; //最后一行
}

int main()
{
    string str;
    cin >> str;
    int n,m;
    n=0;
    m=0;
    //cin >> n >> m;
    //draw(n,m);
    int i=0;
    while(str[i]=='[')
    {
        while(str[i]=='[')
        {
            m++;
            i++;
        }
        if(n==0) n=m;
        draw(n,m);
        while(str[i]==']')
            i++;
        m=0;
    }
    return 0;
}

