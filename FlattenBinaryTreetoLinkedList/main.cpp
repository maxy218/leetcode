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
    void r_flatten(TreeNode *root){
      if(root == NULL) return;
      if(root -> left != NULL){
        r_flatten(root -> left);
        TreeNode* leftTail = root -> left;
        while(leftTail -> right != NULL){
          leftTail = leftTail -> right;
        }
        leftTail -> right = root -> right;
        leftTail -> left = NULL;
        root -> right = root -> left;
        root -> left = NULL;
      }
      if(root -> right != NULL){
        r_flatten(root -> right);
      }
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
