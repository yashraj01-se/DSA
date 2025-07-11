#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int maxi=0;
struct Node{
    int data;
    Node*left;
    Node*right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
bool is_identical(Node*root1,Node*root2){
    if(root1==nullptr && root2==nullptr)return true;
    if(root1==nullptr || root2==nullptr)return false;
    if(root1->data==root2->data)return(is_identical(root1->left,root2->left) && is_identical(root1->right,root2->right));
    return false;
}
int main(){
   struct Node*root1=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);
    root1->left->right=new Node(4);

    struct Node*root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->right=new Node(4);

    bool answer=is_identical(root1,root2);
    if(answer){
        cout<<"Identical";
    }
    else{
        cout<<"NON-identical";
    }


}