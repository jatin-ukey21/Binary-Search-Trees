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
    // Helper function to validate BST by checking allowed value range
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        // Base case: Empty tree is a valid BST
        if (root == NULL) return true;

        // The current node's value must be strictly within min and max range
        if (root->val >= maxVal || root->val <= minVal) return false;

        // Recursively check:
        // Left subtree must be in range (minVal, root->val)
        // Right subtree must be in range (root->val, maxVal)
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }

    // Main function that starts recursion with full valid range
    bool isValidBST(TreeNode* root) {
        // Use long min/max to handle edge cases where node values are INT_MIN or INT_MAX
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};
