/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Unique Binary Search Trees II
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
	vector<TreeNode *> r_generateTrees(int l, int r) {
		vector<TreeNode *> vec;
		if(l > r){
			vec.push_back(NULL);
			return vec;
		}
		if(l == r){
			vec.push_back(new TreeNode(l));
			return vec;
		}
		for(int  i = l; i <= r; ++i){ // i: the root vale
			vector<TreeNode *> lSubTree = r_generateTrees(l, i - 1);
			vector<TreeNode *> rSubTree = r_generateTrees(i + 1, r);
			int lNum = lSubTree.size();
			int rNum = rSubTree.size();
			for(int j = 0; j < lNum; ++j){
				for(int k = 0; k < rNum; ++k){
					TreeNode * tmpRoot = new TreeNode(i);
					tmpRoot -> left = lSubTree[j];
					tmpRoot -> right = rSubTree[k];
					vec.push_back(tmpRoot);
				}
			}
		}
	}
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return r_generateTrees(1,n);
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





