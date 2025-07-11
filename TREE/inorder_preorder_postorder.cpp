#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void allgen(Node *root,vector<int>&pre,vector<int>&in,vector<int>&pos){
     stack<pair<Node*,int>>st;
     if(root==NULL)return;
     st.push({root,1});
     while(!st.empty()){
         auto it=st.top();
         st.pop();
         if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
         }
         else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
         }
        else if(it.second==3){
            pos.push_back(it.first->data);
         }
     }
}


int main(){
    struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->right=new Node(4);
    root->left->left=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    vector<int>pre,in,pos;
    allgen(root,pre,in,pos);
    cout<<"Preorder:"<<endl;
    for(auto it:pre){
       cout<<it<<" ";
    }cout<<endl;
    cout<<"Inorder:"<<endl;
    for(auto i:in){
       cout<<i<<" ";
    }cout<<endl;
    cout<<"Postorder:"<<endl;
    for(auto iq:pos){
       cout<<iq<<" ";
    }cout<<endl;

}