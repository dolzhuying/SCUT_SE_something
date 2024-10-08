#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int data;
    treenode* left;
    treenode* right;

    treenode():data(0),left(nullptr),right(nullptr){}
    treenode(int val):data(val),left(nullptr),right(nullptr){}
};

void add(treenode*&root,int data){ //BST添加节点
    if(!root){
        root=new treenode(data);
        return;
    }
    else {
        if(data<root->data){
            add(root->left,data);
        }
        else if(data>root->data){
            add(root->right,data);
        }
    }
}
bool search(treenode*&root,int data){ //查找key节点
    if(!root)return false;
    else{
        if(data<root->data)return search(root->left,data);
        else if(data>root->data)return search(root->right,data);
        else return true;
    }
}
treenode* findmin(treenode*&root){
    if(!root)return nullptr;
    while(root->left)root=root->left;
    return root;
}
treenode* findmax(treenode*&root){
    if(!root)return nullptr;
    while(root->right)root=root->right;
    return root;
}
treenode*deletenode(treenode*&root,int data){ //删除key节点
    if(!root)return nullptr;
    else if(data<root->data) root->left=deletenode(root->left,data);
    else if(data>root->data) root->right=deletenode(root->right,data);
    else{
        if(!root->left&&!root->right){
            delete root;
            root=nullptr;
        }
        else if(!root->left){
            treenode*node=root;
            root=root->right;
            delete node;
            node=nullptr;
        }
        else if(!root->right){
            treenode*node=root;
            root=root->left;
            delete node;
            node=nullptr;
        }
        else {
            treenode*node=findmin(root->right);
            root->data=node->data;
            root->right=deletenode(root->right,node->data);
        }
    }
    return root;
}

void preorder(treenode*&root){ //前序
    if(!root)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(treenode*&root){ //中序
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(treenode*&root){ //后序
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(treenode*&root){ //层次遍历
    if(!root)return;
    queue<treenode*>q;
    q.push(root);
    while(!q.empty()){
        treenode*node=q.front();
        q.pop();
        cout<<node->data<<' ';
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
    }
    
}

int main(){
    treenode*root=nullptr;
    add(root,3);
    add(root,6);
    add(root,2);
    add(root,5);
    inorder(root);
    add(root,7);
    cout<<'\n';
    deletenode(root,6);
    levelorder(root);

}




