/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Symmetric Tree
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
  bool r_isTreeIdentity(TreeNode *rt1, TreeNode *rt2){
    // rt1 & rt2 will not be NULL
    if(rt1 == NULL && rt2 == NULL) return true;
    if(rt1 == NULL || rt2 == NULL) return false;
    if(rt1 -> val != rt2 -> val) return false;
    return r_isTreeIdentity(rt1 -> left, rt2 -> right) && r_isTreeIdentity(rt1 -> right, rt2 -> left);
  }
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	  if(root == NULL) return true;
	  return r_isTreeIdentity(root -> left, root -> right);
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

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





