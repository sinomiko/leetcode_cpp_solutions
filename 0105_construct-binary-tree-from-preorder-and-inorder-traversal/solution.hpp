#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP


Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

RESULT:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#if 0

/**
 * Memory limit exceed
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if(inorder.empty() || postorder.empty())
            return NULL;

        int val = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(val);

        int idx = 0;
        for(int i=0; i<inorder.size(); ++i) {
            if(inorder[i] == val) {
                idx = i;
                break;
            }
        }

        vector<int> inorder_left(inorder.begin(), inorder.begin()+idx);
        vector<int> inorder_right(inorder.begin()+idx+1, inorder.end());

        vector<int> postorder_left(postorder.begin(), postorder.begin()+idx);
        vector<int> postorder_right(postorder.begin()+idx, postorder.end()-1);

        root->left = subBuildTree(inorder_left, postorder_left);
        root->right = subBuildTree(inorder_right, postorder_right);

        return root;
    }

    TreeNode* subBuildTree(vector<int> inorder, vector<int> postorder){
        if(inorder.empty() || postorder.empty())
            return NULL;

        int val = postorder[postorder.size()-1];
        TreeNode* node = new TreeNode(val);

        int idx = 0;
        for(int i=0; i<inorder.size(); ++i) {
            if(inorder[i] == val) {
                idx = i;
                break;
            }
        }

        vector<int> inorder_left(inorder.begin(), inorder.begin()+idx);
        vector<int> inorder_right(inorder.begin()+idx+1, inorder.end());

        vector<int> postorder_left(postorder.begin(), postorder.begin()+idx);
        vector<int> postorder_right(postorder.begin()+idx, postorder.end()-1);

        node->left = subBuildTree(inorder_left, postorder_left);
        node->right = subBuildTree(inorder_right, postorder_right);

        return node;
    }
};

#endif



#endif