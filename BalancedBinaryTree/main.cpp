/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Balanced Binary Tree
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    bool r_isBalanced(TreeNode *root, int& height){
      if(root == NULL) { height = 0; return true;}
      int h1, h2;
      if(!r_isBalanced(root -> left, h1)) return false;
      if(!r_isBalanced(root -> right, h2)) return false;
      if(h1 > h2 + 1 || h2 > h1 + 1) return false;
      height = h1 > h2 ? h1 + 1 : h2 + 1;
      return true;
    }

public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height = 0;
        return r_isBalanced(root, height);
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
	return EXIT_SUCCESS;

}				/* ----------  end of function main  ---------- */
