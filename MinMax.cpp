#include<bits/stdc++.h>
using namespace std;


 class Node
 {
 public:
     int data;
     Node *left;
     Node *right;
     Node() : data(0), left(nullptr), right(nullptr){};
     Node(int x) : data(x), left(nullptr), right(nullptr) {}
     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 };
 
int minVal(Node* root){
	// Write your code here.
	while(root != nullptr && root->left != nullptr){
		root = root->left;
	}	
	return (root == nullptr) ? -1 : root->data;
}

int maxVal(Node* root){
    // Write your code here.
    while(root != nullptr && root->right != nullptr){
        root = root->right;
    }	
    return (root == nullptr) ? -1 : root->data;
}