#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree),
construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, 
and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Helper function to construct BST from preorder using bounds
    TreeNode* build(int& i, vector<int>& preorder, int upperBound) {
        // Base case: If index is out of bounds or current value exceeds the allowed upper bound
        if (i == preorder.size() || preorder[i] > upperBound)
            return NULL;

        // Create root node with current value and move to next index
        TreeNode* root = new TreeNode(preorder[i++]);

        // Recursively build left subtree with new upper bound as current root's value
        root->left = build(i, preorder, root->val);

        // Recursively build right subtree with same upper bound as parent
        root->right = build(i, preorder, upperBound);

        return root;
    }

    // Main function to build BST from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(i, preorder, INT_MAX);
    }
};
