#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
 void parent(Node * root,unordered_map<Node*,Node*>&parentmaker){
        if(root==nullptr)return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* curr=q.front();
                q.pop();
                if(curr->left){
                    parentmaker[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    parentmaker[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }
    }
Node* inorder(Node* root,int start){
        if(root==nullptr)return nullptr;

        Node* leftresult=inorder(root->left,start);
        if(leftresult)return leftresult;

        if(root->data==start)return root;

        Node* rightresult=inorder(root->right,start);
        if(rightresult)return rightresult;

        return nullptr;
    }

int main()
{
    Node *target;
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

     if(root==nullptr)return 0;
        unordered_map<Node*,bool>visited;
        queue<Node*>q;
        unordered_map<Node*,Node*>parentmaker;
        parent(root,parentmaker);
        int start=5;

        Node * starting_node=inorder(root,start);

        q.push(starting_node);
        visited[starting_node]=true;
        int min=0;
        while(!q.empty()){
            bool spread=false;
              int size=q.size();
              for(int i=0;i<size;i++){
                Node* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                    spread=true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                    spread=true;
                }
                if(parentmaker[curr] && !visited[parentmaker[curr]]){
                    q.push(parentmaker[curr]);
                    visited[parentmaker[curr]]=true;
                    spread=true;
                }
                
              }
              if(spread){
                min++;
              }
        }
        cout<<"Minutes to Burn entire Tree: "<<min<<" min"<<endl;

}

