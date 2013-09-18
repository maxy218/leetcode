/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  binary tree maximum path sum
 *
 *        Version:  1.0
 *        Created:  2013年09月11日 11时17分49秒
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
    int r_maxPathSum(TreeNode* root, int& maxSum){
      if(root == NULL) return 0;
      int leftMaxSumSubPath = r_maxPathSum(root -> left, maxSum);
      int rightMaxSumSubPath = r_maxPathSum(root -> right, maxSum);
      leftMaxSumSubPath = leftMaxSumSubPath > 0 ? leftMaxSumSubPath : 0;
      rightMaxSumSubPath = rightMaxSumSubPath > 0 ? rightMaxSumSubPath : 0;
      int tmpSum = leftMaxSumSubPath + rightMaxSumSubPath + root -> val;
      if(tmpSum > maxSum) maxSum = tmpSum;
      return leftMaxSumSubPath > rightMaxSumSubPath ? leftMaxSumSubPath + root -> val : rightMaxSumSubPath + root -> val;
    }

public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxSum = 0x80000000;
        r_maxPathSum(root, maxSum);
        return maxSum;
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
        root -> left = new TreeNode(2);
        root -> right = new TreeNode(3);

        Solution s;
        cout << s.maxPathSum(root) << endl;

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
