#include <sstream>
#include <string>
#include <iostream>


using namespace std;

int change(string str)
{
    int result=0;
    for(int i=0;i<str.length();++i)
    {
        result=result*26+str[i]-'a';
    }
    return result;

}

int main()
{

    string line;
    while(getline(cin,line))
    {
        cout<<change(line)<<endl;

    }


    return 0;
}
