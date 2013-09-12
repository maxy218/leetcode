/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Convert Sorted Array to Binary Search Tree
 *
 *        Version:  1.0
 *        Created:  09/12/2013 12:24:24 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<vector>
#include	<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* r_sortedArrayToBST(vector<int> &num, int l, int r){
      if(l > r) return NULL;
      int m = l + (r-l)/2;
      TreeNode* root = new TreeNode(num[m]);
      root -> left = r_sortedArrayToBST(num, l, m - 1);
      root -> right = r_sortedArrayToBST(num, m + 1, r);
      return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() == 0) return NULL;
        return r_sortedArrayToBST(num, 0, num.size() - 1);
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
  int a[] = {2,4,5,6,9,10};
  vector<int> vec(a, a+6);
  Solution s;
  TreeNode* root = s.sortedArrayToBST(vec);
 
  TraverseTree(root);


  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
