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
    bool r_inOrder(TreeNode *root, int & lastNum){
      if(root == NULL) return true;
      bool ifLeftValid = r_inOrder(root -> left, lastNum);
      if(!ifLeftValid) return false;
      if(root -> val <= lastNum) return false;
      lastNum = root -> val;
      return r_inOrder(root -> right, lastNum);
    }
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lastNum = 0x80000000;
        return r_inOrder(root, lastNum);
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
  root -> left = new TreeNode(3);
  root -> right = new TreeNode(7);
  root -> left -> left = new TreeNode(1);
  root -> left -> right = new TreeNode(4);
  root -> right -> left = new TreeNode(6);
  root -> right -> right = new TreeNode(8);

  Solution s;
  cout << s.isValidBST(root) << endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
