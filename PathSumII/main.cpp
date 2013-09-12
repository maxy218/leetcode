/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Path Sum
 *
 *        Version:  1.0
 *        Created:  09/11/2013 10:12:14 PM
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
#include	<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    void r_pathSum(TreeNode *root, int sum, vector<int> & path, vector<vector<int> > & paths){
      if(root == NULL) return;
      if(root -> left == NULL && root -> right == NULL){
        if(root -> val != sum) return;
        path.push_back(root -> val);
        paths.push_back(path);
        path.pop_back();
      }
      path.push_back(root -> val);
      if(root -> left != NULL) r_pathSum(root -> left, sum - root->val, path, paths);
      if(root -> right != NULL) r_pathSum(root -> right, sum - root->val, path, paths);
      path.pop_back();
    }

public:
    vector<vector<int> > pathSum(TreeNode *root, int sum){
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > paths;
        vector<int> path;
        if(root == NULL) return paths;
        r_pathSum(root, sum, path, paths);
        return paths;
    }
};

void output(const vector<vector<int> > & paths){
  int len1 = paths.size();
  if(len1 == 0) return;

  for(int i = 0; i < len1; ++i){
    int len2 = paths[i].size();
    for(int j = 0; j < len2; ++j){
      cout << paths[i][j] << ", ";
    }
    cout << endl;
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

  TreeNode* root = new TreeNode(5);
  root -> left = new TreeNode(4);
  root -> right = new TreeNode(8);
  root -> left -> left = new TreeNode(11);
  root -> right -> left = new TreeNode(13);
  root -> right -> right = new TreeNode(4);
  root -> left -> left -> left = new TreeNode(7);
  root -> left -> left -> right = new TreeNode(2);
  root -> right -> right -> left = new TreeNode(5);
  root -> right -> right -> right = new TreeNode(1);

  Solution s;
  vector<vector<int> > paths = s.pathSum(root, 22);
  output(paths);

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
