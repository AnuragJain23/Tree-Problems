#include <bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  node*left;
  node*right;
  
  node(int d)
  {
      data=d;
      left=NULL;
      right=NULL;
  }
};
node*buildtree()
 {
  int data;
  cin>>data;
  if(data==-1)
  {
      return NULL;
  }
  node*root =new node(data);
  root->left=buildtree();
  root->right=buildtree();
  return root;
 }
 void printpreorder(node*root)
 {
     if(root==NULL)
     return;
     cout<<root->data<<" ";
     printpreorder(root->left);
     printpreorder(root->right);
 }
 void bfs(node*root)
 {
     queue<node*> q;
     q.push(root);
     q.push(NULL);
     while(!q.empty())
     {
         node*f=q.front();
         if(f==NULL)
         {
             cout<<endl;
             q.pop();
             if(!q.empty())
             {
                 q.push(NULL);
             }
         }
         else
         {
         cout<<f->data<<",";
         q.pop();
         if(f->left)
          {
             q.push(f->left);
          }
         if(f->right)
          {
             q.push(f->right);
          }
         }
     }
 }
 int restoresum(node*root)
 {
     if(root==NULL)
     return 0;
     if(root->left==NULL && root->right==NULL)
     return root->data;
     int leftsum=restoresum(root->left);
     int rightsum=restoresum(root->right);
     int temp=root->data;
     root->data=leftsum+rightsum;
     return temp+root->data;
 }
 node* buildtreefarray(int *a,int s,int e)
 {
     if(s>e)
     return NULL;
     int mid=(s+e)/2;
     node*root=new node(a[mid]);
     root->left=buildtreefarray(a,s,mid-1);
     root->right=buildtreefarray(a,mid+1,e);
     return root;
 }
 node*insertinbst(node*root,int data)
 {
     if(root==NULL)
     {
         return new node(data);
     }
     if(data<=root->data)
     root->left=insertinbst(root->left,data);
     else
     root->right=insertinbst(root->right,data);
 }
 node*build()
 {
    int d;
    cin>>d;
    node*root=NULL;
    while(d!=-1)
    {
        root=insertinbst(root,d);
        cin>>d;
    }
    return root;
 }
 void inorder(node*root)
 {
     if(root==NULL)
      return;
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
}
bool search(node*root,int d)
{
    if(root==NULL)
    return false;
    if(root->data==d)
    return true;
    else if(d<root->data)
    search(root->left,d);
    else if(d>root->data)
    search(root->right,d);
}
node*deleteinbst(node*root,int data)
{
    if(root==NULL)
    return NULL;
    else if(data<root->data)
    {
       root->left=deleteinbst(root->left,data);
       return root;
    }
    else if(data==root->data)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        
        
        if(root->left!=NULL&&root->right==NULL)
        {
            node*temp=root->left;
            delete root;
            return temp;
        }
         if(root->left==NULL&&root->right!=NULL)
        {
            node*temp=root->right;
            delete root;
            return temp;
        }
        node*replace=root->right;
        while(replace->left!=NULL)
        {
            replace=replace->left;
        }
        root->data=replace->data;
        root->right=deleteinbst(root->right,replace->data);
        return root;
    }
    else
    {
        root->right=deleteinbst(root->right,data);
        return root;
    }
    
}
 int main()
 {
     node*root=build();
     bfs(root);
     cout<<endl;
    // inorder(root);
    // cout<<endl;
     int s;
     cin>>s;
     deleteinbst(root,s);
     bfs(root);
 }
