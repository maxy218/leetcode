/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Minimum Depth of Binary Tree
 *
 *        Version:  1.0
 *        Created:  09/11/2013 11:03:26 PM
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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) return 1;
        int dLeft = 1 + minDepth(root -> left);
        int dRight = 1 + minDepth(root -> right);
        if(dLeft == 1) return dRight;
        if(dRight == 1) return dLeft;
        return dLeft < dRight ? dLeft : dRight;
    }
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
  TreeNode* root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(3);
  root -> right -> left = new TreeNode(4);

  Solution s;
  cout << s.minDepth(root) << endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
