#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
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
    //TC: O(log N)
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        TreeNode* cur = root;
        while(true){
            if(cur->val <= val){
                if(cur->right != nullptr) {
                    cur = cur->right;
                }
                else{
                    cur -> right = new TreeNode(val);
                    break;
                }
            }
            else{
                // If the value to insert is less than current node's value, go left
                if(cur->left != nullptr) {
                    cur = cur->left;
                }
                else{
                    cur -> left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};