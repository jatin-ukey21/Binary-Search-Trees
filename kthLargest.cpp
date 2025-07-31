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
    void reverseinorder(TreeNode* root,int& cnt,int k,int &kthLargest){
        if(!root || cnt >= k) return; //imp
        
        reverseinorder(root->right,cnt,k,kthLargest);

        cnt++;
        if(cnt == k){
            kthLargest = root->val;
            return;
        }

        reverseinorder(root->left,cnt,k,kthLargest);

    }
    int kthLargest(TreeNode *root, int k) {
        // Your code here
        int cnt = 0;
        int kthLarges;
        reverseinorder(root,cnt,k,kthLarges);

        return kthLarges;
    }
};