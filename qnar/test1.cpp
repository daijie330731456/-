#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
};

int find_index(int* a,int c,int n)
{
    for(int i=0;i<n;++i)
    {
        if(a[i]==c)
            return i;
    }
    return -1;
}

TreeNode* build_one(int* pre_begin,int* pre_end,int* mid_begin,int* mid_end)
{
    int root_value=pre_begin[0];
    TreeNode* root=new TreeNode();
    root->value=root_value;
    root->left=root->right=NULL;
    if(pre_begin==pre_end)
    {
        return root;
    }

    int index=find_index(mid_begin,pre_begin[0],mid_end-mid_begin+1);
    if(index>0)
    {
        root->left=build_one(pre_begin+1,pre_begin+index,mid_begin,mid_begin+index-1);
        root->right=build_one(pre_begin+index+1,pre_end,mid_begin+index+1,mid_end);
    }
    return root;
}

TreeNode* build(int* pre,int* mid,int n)
{
    if(pre == NULL||mid == NULL)
        return NULL;
    return build_one(pre,pre+n-1,mid,mid+n-1);
}

//层次遍历一棵树
void print(TreeNode* T,int n)
{
    queue<TreeNode*> result;
    if(T!=NULL)
        result.push(T);
    //while(!result.empty())
    for(int i=0;i<n;++i)
    {
        TreeNode* p=result.front();
        cout<<p->value<<" ";
        result.pop();
        if(T->left!=NULL)
            result.push(p->left);
        if(T->right!=NULL)
            result.push(p->right);
    }
}


int main()
{
    int n;
    cin>>n;
    int A[n];
    int B[n];
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

    TreeNode* T=build(A,B,n);

    //cout<<T->value<<T->left->value<<T->right->value<<endl;
    print(T,n);

    return 0;
}
