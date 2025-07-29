#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

//APPROACH 1: POINTER ITERATION
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
    TreeNode* searchBST(TreeNode* root, int val) {
        //pointer approach
        while(root!=NULL && root->val != val){
            root = val < root->val ? root->left : root->right;
        }

        return root;
    }
};

//APPROACH 2: RECURSION

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //recursive approach
        if(root == NULL) return NULL;
        if(root->val == val) return root;

        if(val < root->val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }
};

