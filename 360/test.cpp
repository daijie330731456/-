#include <iostream>
//#include <stdio.h>
#include<iomanip>
#include <sstream>
#include <string>

using namespace std;

int main ()
{
    int n;
    cin>>n;
    double x[n];
    double p[n];
    string nums;
    int i=0;
    while(i<=n)
    {
        getline(cin,nums);
        istringstream istr(nums);
        if(i!=0)
        {
            istr>>x[i-1];
            istr>>p[i-1];
        }
        ++i;
    }
    double result=0.000;
    //cout<<n<<x[0]<<p[0]<<x[1]<<p[1];
    for(int i=0;i<n;++i)
    {
        result+=(x[i]*p[i]/100);
        //cout<<result;
    }
    cout.setf(ios::fixed);
    cout<<setprecision(3);
    cout<<result<<endl;
}
