/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Recover Binary Search Tree
 *
 *        Version:  1.0
 *        Created:  09/29/2013 12:27:20 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
public class Solution {
    public void recoverTree(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        TreeNode* prev = NULL;
        TreeNode* n1 = NULL;
        TreeNode* n2 = NULL;
        findTwoNodes(root, n1, n2, prev);
        if(n1 != NULL && n2 != NULL){
          int tmp = n1 -> val;
          n1 -> val = n2 -> val;
          n2 -> val = tmp;
        }
    }
    void findTwoNodes(TreeNode* root, TreeNode* & n1, TreeNode* & n2, TreeNode* & prev){
      if(root == NULL) return;
      findTwoNodes(root -> left, n1, n2, prev);
      if(prev != NULL && prev -> val > root -> val){
        n2 = root;
        if(n1 == NULL){
          n1 = prev;
        }
      }
      prev = root;
      findTwoNodes(root -> right, n1, n2, prev);
    }
}
