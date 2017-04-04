#include<iostream>
#include <string>


using namespace std;

bool check(string str,int begin,int end)
{
    for(int i=begin;i<=end;++i)
    {
        int count_2=0;
        for(int j=begin;j<=end;++j)
        {
            if(str[i]==str[j])
                count_2++;
        }
        if(count_2 %2!=0)
            return false;
    }
    return true;
}

int main()
{
    string str;
    cin>>str;
    int count_s=0;
    for(int i=0;i<str.length()-1;++i)
    {
        for(int j=i+1;j<str.length();++j)
        {
            if(check(str,i,j))
                count_s++;
        }
    }
    cout<<count_s<<endl;
    return 0;
}
