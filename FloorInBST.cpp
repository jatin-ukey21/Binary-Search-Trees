#include<bits/stdc++.h>
using namespace std;

 struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  


// Function to find the floor of a given value in a BST.
// Floor = greatest value in BST ≤ x
class Solution
{
public:
    int floor(Node *root, int x)
    {
        int floor = -1;
        while (root)
        {
            // Exact match found → best possible floor
            if (root->data == x)
            {
                floor = root->data;
                return floor;
            }
            // If current node's value < x,
            // this node could be a candidate for floor.
            // Go right to try finding a closer (larger) floor value
            else if (root->data < x)
            {
                floor = root->data;
                root = root->right;
            }
            // If current node's value > x,
            // floor must lie in the left subtree
            else
            {
                root = root->left;
            }
        }

        return floor;
    }
};
