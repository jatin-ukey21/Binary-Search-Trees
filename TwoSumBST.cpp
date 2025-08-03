#include<bits/stdc++.h>
using namespace std;

//Structure of a Node in the BST

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
//REMEMBER INORDER TRAVERSAL (TWO SUM USES SORTING ORDER)
// BSTIterator class supports in-order (ascending) and reverse in-order (descending) traversal
class BSTIterator {
private:
    //reverse = true -> used for 'before' operation
    //reverse = false -> used for 'next'(normal BST iterator) operation
    bool reverse;                  // true for reverse-inorder (right to left), false for inorder (left to right)
    stack<TreeNode*> st;          // stack to simulate recursion in traversal

public:
    // Constructor takes the root of BST and traversal direction
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);            // initialize the stack with the first node in the given traversal order
    }

    // Checks if there is a next element in the traversal
    bool hasNext() {
        return !st.empty();
    }

    // Returns the next element in the traversal (smallest or largest depending on 'reverse')
    //this will be used as both next and before operation based on reverse
    int next() {
        TreeNode* node = st.top();
        st.pop();

        // Based on traversal direction, move to the next subtree
        if (!reverse)
            pushAll(node->right); // for normal in-order, go to right child
        else
            pushAll(node->left);  // for reverse in-order, go to left child

        return node->val;
    }

    // Helper function to push all nodes along the path to the next node in traversal order
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            // Go in the appropriate direction based on traversal mode
            if (reverse)
                node = node->right;   // reverse: right to left
            else
                node = node->left;    // normal: left to right
        }
    }
};

// Main solution class to solve the "Two Sum in BST" problem
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        // Edge case: if tree is empty, no pairs exist
        if (!root) return false;

        // Create two iterators: one for ascending order, one for descending order
        BSTIterator l(root, false); // In-order iterator (smallest to largest)
        BSTIterator r(root, true);  // Reverse in-order iterator (largest to smallest)

        // Initialize two pointers from both ends
        int i = l.next(); // smallest value
        int j = r.next(); // largest value

        // Continue until the two pointers meet or cross
        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;         // Found two elements that sum to target
            else if (sum < k) i = l.next();    // Move forward in in-order (increase sum)
            else j = r.next();                 // Move backward in reverse in-order (decrease sum) ,actually r.before();
        }

        // No pair found
        return false;
    }
};
