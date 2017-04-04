#include <iostream>
#include <string>

using namespace std;

int reverseAdd(int a,int b)
{
    if(a<1||a>70000||b<1||b>70000)
        return -1;
    int a_reverse=0,b_reverse=0;
    while(a!=0)
    {
        a_reverse=a_reverse*10+a%10;
        a=a/10;
    }
    while(b!=0)
    {
        b_reverse=b_reverse*10+b%10;
        b=b/10;
    }
    return a_reverse+b_reverse;
}

int main()
{
    int a=0,b=0;
    string str;
    cin>>str;
    int i;
    for(i=0;str[i]!=',';++i)
    {
        a=a*10+str[i]-'0';

    }
    i++;
    for(;i<str.length();++i)
    {
        b=b*10+str[i]-'0';

    }
    //cout<<a<<b<<endl;
    //int result=reverseAdd(123,456);
    cout<<reverseAdd(a,b);

    return 0;
}
