#include<bits/stdc++.h>
using namespace std;

 struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  

int findCeil(Node* root, int input) {
    // Your code here
    int ceil = -1;
    while(root){
        if(root->data == input){
            ceil = root->data;
            return ceil;
        }
        //If key is greater than current node,
        //Go right → because all left values will be even smaller → not helpful.
        else if(root->data < input){
            root = root->right;
        }
        //If key < root value → this root might be the ceil.
        //But there might be a smaller valid ceil in the left subtree → so store current node and go left.
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    
    return ceil;
}