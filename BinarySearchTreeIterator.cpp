#include<bits/stdc++.h>
using namespace std;

/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;  // Stack to simulate in-order traversal

public:
    // Constructor: initialize the iterator with the root of the BST
    BSTIterator(TreeNode* root) {
        // Push all left nodes starting from root into the stack
        // So the smallest element is on top of the stack
        pushAll(root);
    }

    // Returns the next smallest number in BST
    int next() {
        // Top of the stack is the current smallest
        TreeNode* node = st.top();
        st.pop();

        // If the node has a right subtree, we push all its left descendants
        // Because in-order traversal is: left → root → right
        pushAll(node->right);

        return node->val;
    }

    // Returns true if there are more elements in the in-order traversal
    bool hasNext() {
        return !st.empty();  // Stack non-empty means more nodes left
    }

private:
    // Helper function to push all left children of a node into the stack
    // So we always have the next smallest element at the top of the stack
    void pushAll(TreeNode* node) {
        // Travel as left as possible and push all nodes into the stack
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */