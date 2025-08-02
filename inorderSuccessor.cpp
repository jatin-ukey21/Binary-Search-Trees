#include<bits/stdc++.h>
using namespace std;

//Structure of a Node in the BST

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
public:
    // Function to find the inorder successor of node x in BST rooted at 'root'
    int inOrderSuccessor(Node* root, Node* x) {
        Node* successor = NULL;

        // Start traversing the BST from the root
        while (root != NULL) {
            // If x->data is greater than or equal to root's data,
            // successor must be in the right subtree
            if (x->data >= root->data) {
                root = root->right;
            }
            // If x->data is less than root's data,
            // this node could be a potential successor
            // but we still check the left subtree for a closer one
            else {
                successor = root;      // store current node as potential successor
                root = root->left;     // go left to look for smaller successor
            }
        }

        // If successor was found, return its data; otherwise return -1
        return successor ? successor->data : -1;
    }
};

/*
🧠 Example Walkthrough
Let's build this BST:
          20
         /  \
       10    30
             /
           25
Say: x = 20
->Step-by-step Execution:
successor = NULL Start at root: root = 20
x->data == root->data → go to root->right → move to 30 At root = 30:
30 > 20 → it's a potential successor Set successor = 30 Move to root->left → now root = 25
At root = 25:
25 > 20 → it's a better successor Set successor = 25 Move to root->left → now root = NULL
Traversal ends.

✅ successor = 25 is the inorder successor of 20

->Another Example: x = 30
Start at root: root = 20

30 > 20 → go right

root = 30

30 == 30 → go right → root = NULL

❌ No node > 30 → return -1
*/
