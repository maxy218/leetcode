/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Flatten Binary Tree to Linked List
 *
 *        Version:  1.0
 *        Created:  09/11/2013 08:13:39 PM
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
    TreeNode * r_flatten(TreeNode *root){
      if(root == NULL) return NULL;
      if(root -> left == NULL && root -> right == NULL) return root;
      if(root -> left == NULL) return r_flatten(root -> right);
      if(root -> right == NULL) { root -> right = root -> left; return r_flatten(root -> right);}
      TreeNode* tmp = root -> right;
      root -> right = root -> left;
      TreeNode* tmp2 = r_flatten(root -> right);
      tmp2 -> right = tmp;
      return r_flatten(tmp);
    }
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      r_flatten(root);
    }
};

void output(TreeNode *root){
  while(root != NULL){
    cout << root -> val << ", ";
    root = root -> right;
  }
  cout << endl;
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

  TreeNode* root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(5);
  root -> left -> left = new TreeNode(3);
  root -> left -> right = new TreeNode(4);
  root -> right-> right = new TreeNode(6);

  Solution s;
  s.flatten(root);
  output(root);

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
