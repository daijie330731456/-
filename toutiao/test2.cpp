#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool find(string word,string str2)
{
    if(word[0]>'A'&&word[0]<'Z')
    {
        word[0]=word[0]-'A'+'a';
    }
    if(str2.find(word)!=std::string::npos)
        return true;
    return false;
}

//查找str1在str2中的次数
int find_count(string str1,string str2)
{
    string word;
    int count=0;
    istringstream istr(str1);
    istr>>word;
    string head="";
    while(head!=word)
    {
        //cout<<"word:"<<word;
        if(find(word,str2))
            count++;
        head=word;
        istr>>word;
    }
    return count;
}

int main ()
{
    int M,N;
    cin>>N;
    cin>>M;
    vector<string> str1,str2;
    string line;
    int i=0;
    getline(cin,line);
    while(i<N)
    {
        getline(cin,line);
        str1.push_back(line);
        ++i;
    }
    i=0;
    while(i<M)
    {
        getline(cin,line);
        str2.push_back(line);
        ++i;
    }
    for(int i=0;i<M;i++)
    {
        int count_2=0;
        int result;
        for(int j=0;j<N;j++)
        {
            int count_3;
            if((count_3=find_count(str2.at(i),str1.at(j)))>count_2)
            {
                count_2=count_3;
                result=j;
            }
        }
        cout<<str1.at(result)<<endl;
    }

    return 0;
}
