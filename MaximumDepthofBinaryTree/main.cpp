/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Maximum Depth of Binary Tree
 *
 *        Version:  1.0
 *        Created:  09/12/2013 12:05:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<iostream>
#include	<list>
#include	<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return 0;
		int lDepth = maxDepth(root -> left);
		int rDepth = maxDepth(root -> right);
		return lDepth > rDepth ? 1 + lDepth : 1 + rDepth;
    }
};

void TraverseTree(TreeNode* root){
  if(root == NULL) return;
  cout << root -> val << endl;
  TraverseTree(root -> left);
  TraverseTree(root -> right);
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	TreeNode* root = new TreeNode(3);
	root -> left = new TreeNode(9);
	root -> right = new TreeNode(20);
	root -> right -> left = new TreeNode(15);
	root -> right -> right = new TreeNode(7);
	
	Solution s;
	cout << s.maxDepth(root) << endl;
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





