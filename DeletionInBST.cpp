#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base Case: Tree is empty
        if(root == NULL){
            return NULL;
        }

        // Case 1: If the root itself is the node to be deleted
        if(root->val == key) {
            return helper(root); // Call helper to delete and return new root of subtree
        }

        // Keep a dummy pointer to return final root
        TreeNode *dummy = root;

        // Start traversing the tree to find the node to delete
        while(root != NULL){
            // Go to left subtree if key is smaller
            if(root->val > key){
                // If left child is the target node
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left); // Replace left child with modified subtree
                    break;
                }
                else{
                    root = root->left; // Keep moving left
                }
            }
            // Go to right subtree if key is larger
            else{
                // If right child is the target node
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right); // Replace right child with modified subtree
                    break;
                }
                else{
                    root = root->right; // Keep moving right
                }
            }
        }
        return dummy; // Return original root of the tree
    }

    // This helper deletes the node and returns the new subtree root
    TreeNode* helper(TreeNode* root){
        // Case 1: Node has no left child → return right child
        // e.g., delete 5 from [5, NULL, 7] → returns 7
        if(root->left == NULL){
            return root->right;
        }
        // Case 2: Node has no right child → return left child
        // e.g., delete 5 from [5, 3, NULL] → returns 3
        else if(root->right == NULL){
            return root->left;
        }

        // Case 3: Node has two children
        // Strategy: Attach right subtree to rightmost node of left subtree
        TreeNode* rightChild = root->right; // Store right subtree
        TreeNode* lastRight = findLastRight(root->left); // Find rightmost node in left subtree

        lastRight->right = rightChild; // Attach right subtree there

        // Return the modified left subtree as new subtree root
        return root->left;

        /* Example:
           Deleting 5 from:
                5
               / \
              3   7
               \
                4

           → Attach 7 to rightmost node of 3-subtree (which is 4)
           → Return new root (3)
        */
    }

    // Utility: Find rightmost node of a subtree
    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL) return root; // Base case

        return findLastRight(root->right); // Keep moving right
    }
};
