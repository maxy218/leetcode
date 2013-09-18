/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Construct Binary Tree from Inorder and Postorder Traversal
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
#include	<set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

	TreeNode* r_buildTree(vector<int> &inorder, vector<int> &postorder, int s1, int e1, int s2, int e2){
		if(s1 > e1) return NULL;
		if(s1 == e1) return new TreeNode(inorder[s1]);
		int rootVal = postorder[e2];
		int rootIdxInder = s1;
		for(; rootIdxInder <= e1 && inorder[rootIdxInder] != rootVal; ++rootIdxInder){}
		TreeNode* root = new TreeNode(rootVal);
		
		root -> left = r_buildTree(inorder, postorder, s1, rootIdxInder - 1, s2, s2 + rootIdxInder - 1 - s1);
		root -> right = r_buildTree(inorder, postorder, rootIdxInder + 1, e1, rootIdxInder - s1 + s2, e2 - 1);
		return root;
	}

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.size() != postorder.size()) return NULL;
		if(inorder.size() == 0) return NULL;
		return r_buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
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
	int inOrderArray[] = {1,3,4,5,7,8};
	int postOrderArray[] = {1,4,3,8,7,5};
	vector<int> inOrder(inOrderArray, inOrderArray + 6);
	vector<int> postOrder(postOrderArray, postOrderArray + 6);
	// cout << inOrder[inOrder.size() - 1] << endl;
	// cout << postOrder[postOrder.size() - 1] << endl;
	
	Solution s;
	TraverseTree(s.buildTree(inOrder, postOrder));
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





