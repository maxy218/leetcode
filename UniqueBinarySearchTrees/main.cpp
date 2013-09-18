/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Unique Binary Search Trees
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
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0 || n == 1) return 1;
		int num = 0;
		for(int i = 0; i < n; ++i){ // i < n: if there're n nodes: n = 1-root-node + (n - 1)-leaf-nodes
			num += numTrees(i) * numTrees(n - i - 1);
		}
		return num;
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
	cout << s.numTrees(0) << endl;
	cout << s.numTrees(1) << endl;
	cout << s.numTrees(2) << endl;
	cout << s.numTrees(3) << endl;
	cout << s.numTrees(4) << endl;
	cout << s.numTrees(5) << endl;
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





