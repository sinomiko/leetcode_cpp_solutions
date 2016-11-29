#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

/**
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if(inorder.empty() || postorder.empty())
            return NULL;

        int val = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(val);

        int idx = findIdx(inorder, 0, val);

        root->left = subBuildTree(inorder, postorder, 0, idx, 0, idx);
        root->right = subBuildTree(inorder, postorder, idx+1, inorder.size(), idx, postorder.size()-1);

        return root;
    }

    TreeNode* subBuildTree(const vector<int>& inorder, const vector<int>& postorder,
                           int in_start, int in_end/*not inc*/,
                           int post_start, int post_end/*not inc*/){
        if(in_start >= in_end || post_start >= post_end)
            return NULL;

        int val = postorder[post_end-1];
        TreeNode* node = new TreeNode(val);

        int idx = findIdx(inorder, in_start, val);

        node->left = subBuildTree(inorder, postorder, in_start, in_start+idx,
                                  post_start, post_start+idx);
        node->right = subBuildTree(inorder, postorder, in_start+idx+1, in_end,
                                   post_start+idx, post_end-1);

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