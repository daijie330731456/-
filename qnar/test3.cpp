#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> result_visit;
int min_l=1000;

//计算两个单词有多少个不一样字母
int check(string str1,string str2)
{
    int count;
    if(str1.length()!=str2.length())
        return -1;
    for(int i=0;i<str1.length();++i)
        if(str1[i]!=str2[i])
            count++;
    return count;
}

void find_path(vector<string> visit,string now_point,string dst,int** path,int n)
{
    if(now_point==dst)
    {
        int l=len(visit);
        //cout<<l;
        if(min_l>l)
        {
           result_visit.assign(visit.begin(),visit.end());
           min_l=l;
           //cout<<"min_l"<<min_l;
        }
        return;
    }
    for(int i=1;i<=6;++i)
    {
        if()
        {
            visit.push_back(i);
            find_path(visit,i,dst);
            visit.pop_back();
        }
    }
}

int main()
{
    string line;
    getline(cin,line);//读第一行
    string begin=line;
    getline(cin,line);//读第二行
    string dst=line;
    vector<string> s;
    getline(cin,line);//读第三行
    istringstream istr(line);

    istr>>word;
    string head="";
    while(head!=word)
    {
        s.push_back(word);
        head=word;
        istr>>word;
    }
    int n=s.size();
    int path[n][n];
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(check(s.at(i),s.at(j))==1)
            {
                path[i][j]=1;
                path[j][i]=1;
            }
        }
    }

    vector<string> visit;
    for(int i=0;i<n;++i)
    {
        if(check(begin,s.at(i)==1))
        {
            visit.push_back(s.at(i));
            find_path(visit,s.at(i),dst,path,n);
        }
    }

    return 0;
}
