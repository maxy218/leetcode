/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Path Sum
 *
 *        Version:  1.0
 *        Created:  09/11/2013 10:12:14 PM
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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return false;
        if(root -> left == NULL && root -> right == NULL) return root -> val == sum;

        bool ifLeft = false;
        bool ifRight = false;
        if(root -> left != NULL) ifLeft = hasPathSum(root -> left, sum - root -> val);
        if(root -> right != NULL) ifRight = hasPathSum(root -> right,  sum - root -> val);
        return ifLeft || ifRight;
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

  TreeNode* root = new TreeNode(5);
  root -> left = new TreeNode(4);
  root -> right = new TreeNode(8);
  root -> left -> left = new TreeNode(11);
  root -> right -> left = new TreeNode(13);
  root -> right -> right = new TreeNode(4);
  root -> left -> left -> left = new TreeNode(7);
  root -> left -> left -> right = new TreeNode(2);
  root -> right -> right -> right = new TreeNode(1);

  Solution s;
  cout << s.hasPathSum(root, 22) << endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
