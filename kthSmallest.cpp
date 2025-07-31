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
class Solution {
public:
    //inorder
    void inorder(TreeNode* root,int& cnt,int k,int &kthSmallest){
        if(!root || cnt >= k) return; //imp
        
        inorder(root->left,cnt,k,kthSmallest);

        cnt++;
        if(cnt == k){
            kthSmallest = root->val;
            return;
        }

        inorder(root->right,cnt,k,kthSmallest);

    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int kthSmallest;
        inorder(root,cnt,k,kthSmallest);

        return kthSmallest;
    }
};