#include <iostream>
#include <string>

using namespace std;

void draw(int maxK,int num)
{
    cout << '+';
    int len = 2*maxK-1;
    for(int i=0;i<len;i++)
        cout << '-';
    cout << '+' << endl; //��һ��
    for(int i=2;i<=num;i++)
    {
        for(int j=0;j<i-2;j++)
            cout << ' ';
        cout << '|' << '+';
        len = 2*maxK-2*i+1;
        for(int j=0;j<len;j++)
            cout << '-';
        cout << '+' << '|' << endl;
    } //��2��n��
    for(int i=0;i<num-1;i++)
        cout << ' ';
    cout << '|';
    len = 2*maxK-2*num+1;
    for(int i=0;i<len;i++)
        cout << ' ';
    cout << '|' << endl; //��n+1��
    cout << endl; //����
    for(int i=0;i<num-1;i++)
        cout << ' ';
    cout << '|';
    len = 2*maxK-2*num+1;
    for(int i=0;i<len;i++)
        cout << ' ';
    cout << '|' << endl; //��n+1�жԳ�
    for(int i=1;i<num;i++)
    {
        len = num-i-1;
        for(int j=0;j<len;j++)
            cout << ' ';
        cout << '|' << '+';
        for(int j=0;j<2*i-1;j++)
            cout << '-';
        cout << '+' << '|' << endl;
    } //�Գ�
    cout << '+';
    len = 2*maxK-1;
    for(int i=0;i<len;i++)
        cout << '-';
    cout << '+' << endl; //���һ��
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

