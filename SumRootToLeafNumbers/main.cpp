/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  sum root to leaf numbers
 *
 *        Version:  1.0
 *        Created:  2013年09月10日 19时48分21秒
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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
    void r_sumNumbers(TreeNode * root, int father, list<int>& leafNums){
      if(root == NULL) return;

      father = father*10 + root -> val;
      if(root -> left == NULL && root -> right == NULL){
        leafNums.push_back(father);
        return;
      }

      r_sumNumbers(root -> left, father, leafNums);
      r_sumNumbers(root -> right, father, leafNums);
    }

public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        list<int> leafNums;
        r_sumNumbers(root, 0, leafNums);
        list<int>::iterator it = leafNums.begin();
        int sum = 0;
        for(; it != leafNums.end(); ++it){
          sum += *it;
        }
        return sum;
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
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        Solution s;
        cout << s.sumNumbers(root) << endl;

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
