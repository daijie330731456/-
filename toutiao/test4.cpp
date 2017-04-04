#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int count1(int x,int y,int* A,int* B,int n)
{
    int result=0;
    for(int i=0;i<n;++i)
    {
        if(A[i]>=x&&B[i]>=y)
            ++result;

    }

    return result;
}

int main()
{
    int n,q;
    cin>>n;
    cin>>q;
    int A[n];
    int B[n];
    int select1[q];
    int select2[q];
    string line;
    getline(cin,line);//读第一行
    getline(cin,line);//读第二行
    istringstream istr2(line);
    for(int i=0;i<n;++i)
    {
        istr2>>A[i];
    }
    getline(cin,line);//读第三行
    istringstream istr3(line);
    for(int i=0;i<n;++i)
    {
        istr3>>B[i];
    }
    for(int i=0;i<q;++i)
    {
        getline(cin,line);//读第三行
        istringstream istr(line);
        istr>>select1[i];
        istr>>select2[i];
    }

    for(int i=0;i<q;++i)
    {
       cout<<count1(select1[i],select2[i],A,B,n)<<endl;
    }

    return 0;
}
