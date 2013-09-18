/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Restore IP Addresses
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
    void r_inorderTraversal(TreeNode *root, vector<int> & inOrder){
        if(root == NULL) return;
        r_inorderTraversal(root -> left, inOrder);
        inOrder.push_back(root -> val);
        r_inorderTraversal(root -> right, inOrder);
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> retVal;
        r_inorderTraversal(root, retVal);
        return retVal;
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
	Solution s;
	cout << s.generateTrees(0).size() << endl;
	cout << s.generateTrees(1).size() << endl;
	cout << s.generateTrees(2).size() << endl;
	cout << s.generateTrees(3).size() << endl;
	cout << s.generateTrees(4).size() << endl;
	cout << s.generateTrees(5).size() << endl;
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





