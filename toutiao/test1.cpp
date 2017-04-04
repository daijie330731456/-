#include <sstream>
#include <string>
#include <iostream>

using namespace std;
//全局变量记录结果
int index1=0,index2=0;
int length=0;

int main ()
{
    int n;
    cin>>n;
    int arra[n];
    int i=0;
    while(i<n)
    {
        cin>>arra[i];
        i++;
    }

    cout<<arra[0]<<arra[1]<<arra[2]<<endl;
    i=0;
    int begin=0,end=0;
    while(i<n-1)
    {
        begin=i;
        while(arra[i+1]>arra[i])
            i++;
        //if(i<=begin)
            //break;
        int middle=i;
        while(arra[i+1]<arra[i]&&i<n-1)
            i++;
        //if(i<=middle)
            //break;
        end=i;
        if((middle-begin)>0&&(end-middle)>0&&(end-begin)>length)
        {
            index1=begin;
            index2=end;
            length=end-begin;
        }
    }
    if(index2-index1<2)
        cout<<-1<<" "<<-1;
    else
        cout<<index1<<" "<<index2;
    return 0;
}
