/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Binary Tree Level Order Traversal II
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
		if(root == NULL) return result;
        list<vector<int> > stackResult;
		list<TreeNode *> queue[2];
		queue[0].push_back(root);
		int flag = 0;
		
		while(queue[flag].size() != 0){
			vector<int> tmp2;
			while(queue[flag].size() != 0){
				TreeNode * ptr = queue[flag].front();
				queue[flag].pop_front();
				tmp2.push_back(ptr -> val);
				if(ptr -> left) queue[(flag + 1)%2].push_back(ptr -> left);
				if(ptr -> right) queue[(flag + 1)%2].push_back(ptr -> right);
			}
			stackResult.push_back(tmp2);
			flag = (flag + 1)%2;
		}
		while(stackResult.size() != 0){
			result.push_back(stackResult.back());
			stackResult.pop_back();
		}
		return result;
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
	TreeNode* root = new TreeNode(3);
	root -> left = new TreeNode(9);
	root -> right = new TreeNode(20);
	root -> right -> left = new TreeNode(15);
	root -> right -> right = new TreeNode(7);
	
	Solution s;
	s.levelOrderBottom(root);
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





