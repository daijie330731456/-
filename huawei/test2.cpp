#include <iostream>
#include <string>

using namespace std;

void change(int*& arra,char c)
{
    int temp;
    if(c=='L')
    {
        temp=arra[4];
        arra[4]=arra[1];
        arra[1]=arra[5];
        arra[5]=arra[0];
        arra[0]=temp;
    }
    if(c=='R')
    {
        temp=arra[4];
        arra[4]=arra[0];
        arra[0]=arra[5];
        arra[5]=arra[1];
        arra[1]=temp;
    }
    if(c=='F')
    {
        temp=arra[4];
        arra[4]=arra[3];
        arra[3]=arra[5];
        arra[5]=arra[2];
        arra[2]=temp;
    }
    if(c=='B')
    {
        temp=arra[4];
        arra[4]=arra[2];
        arra[2]=arra[5];
        arra[5]=arra[3];
        arra[3]=temp;
    }
    if(c=='A')
    {
        temp=arra[0];
        arra[0]=arra[3];
        arra[3]=arra[1];
        arra[1]=arra[2];
        arra[2]=temp;
    }
    if(c=='C')
    {
        temp=arra[0];
        arra[0]=arra[2];
        arra[2]=arra[1];
        arra[1]=arra[3];
        arra[3]=temp;
    }


}

int main()
{
    int arra[6]={1,2,3,4,5,6};
    int *p=arra;
    string str;
    cin>>str;
    for(int i=0;i<str.length();++i)
    {
       change(p,str[i]);
    }
    for(int i=0;i<6;++i)
    {
        cout<<arra[i];
    }
    cout<<endl;
    return 0;
}
