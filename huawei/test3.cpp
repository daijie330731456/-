#include<iostream>
#include<vector>
using namespace std;

vector<int> result_visit;
int min_l=1000;
int path[6][6]={
    {0,2,10,5,3,1000},
    {1000,0,12,1000,1000,10},
    {1000,1000,0,1000,7,1000},
    {2,1000,1000,0,2,1000},
    {4,1000,1000,1,0,1000},
    {3,1000,1,1000,2,0}
    };

//计算长度
int len(vector<int> visit)
{
    int len=0;

    //cout<<visit.size();
    //cout<<visit.at(0)<<visit.at(1);
    for(int i=0;i<visit.size()-1;++i)
        len+=path[visit.at(i)-1][visit.at(i+1)-1];
    return len;
}

//判断vector中是否有i
bool check(vector<int> visit,int& i)
{
    for(auto it=visit.begin();it!= visit.end();++it)
    {
        if((*it)==i)
            return true;
    }
    return false;

}

void find_path(vector<int> visit,int now_point,int dst)
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
        if(path[now_point-1][i-1]!=1000 && i!=now_point && i!=5 && !check(visit,i))
        {
            visit.push_back(i);
            find_path(visit,i,dst);
            visit.pop_back();
        }
    }
}

int main()
{

    cout<<"输入出差城市x(x可为1、2、3、4、6)"<<endl;
    int dst_city;
    cin>>dst_city;
    cout<<"输入大雾城市y(y可为0、1、2、3、4、5、6)"<<endl;
    int fog_city;
    cin>>fog_city;
    if(fog_city!=0)
    {
        for(int i=0;i<6;++i)
            path[fog_city-1][i]=1000;
        for(int i=0;i<6;++i)
            path[i][fog_city-1]=1000;
    }
    vector<int> visit;
    visit.push_back(5);
    find_path(visit,5,dst_city);

    if(min_l>=1000)
    {
        min_l=1000;
        visit.clear();
    }
    cout<<min_l<<endl;
    cout<<'[';
    int i;
    //cout<<visit.size();
    for(i=0;i<result_visit.size()-1;i++)
        cout<<result_visit.at(i)<<',';
    cout<<result_visit[i]<<']';
    return 0;
}
