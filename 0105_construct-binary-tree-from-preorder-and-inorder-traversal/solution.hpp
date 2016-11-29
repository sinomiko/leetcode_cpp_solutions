#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

/**
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *
 * RESULT: Accepted
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.empty() || inorder.empty())
            return NULL;

        int val = preorder[0];
        TreeNode* root = new TreeNode(val);

        int idx = findIdx(inorder, 0, val);

        root->left = subBuildTree(preorder, inorder, 1, idx+1, 0, idx);
        root->right = subBuildTree(preorder, inorder, idx+1, inorder.size(), idx+1, inorder.size());

        return root;
    }

    TreeNode* subBuildTree(const vector<int>& preorder, const vector<int>& inorder,
                           int pre_start, int pre_end/*not inc*/,
                           int in_start, int in_end/*not inc*/){
        if(in_start >= in_end || pre_start >= pre_end)
            return NULL;

        int val = preorder[pre_start];
        TreeNode* node = new TreeNode(val);

        int idx = findIdx(inorder, in_start, val);

        node->left = subBuildTree(preorder, inorder, pre_start+1, pre_start+idx+1,
                                  in_start, in_start+idx);
        node->right = subBuildTree(preorder, inorder, pre_start+idx+1, pre_end,
                                   in_start+idx+1, in_end);

        return node;
    }

    int findIdx(const vector<int> vec, int offset, int val) {
        for (int i=0; i<vec.size(); ++i)
            if (vec[i] == val)
                return (i-offset);

        return -1;
    }
};

#endif