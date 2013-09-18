/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  populating next right node pointer
 *
 *        Version:  1.0
 *        Created:  2013年09月11日 13时41分01秒
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


struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    void r_connect(TreeLinkNode *root){
	  if(root == NULL) return;
	  if(root -> left != NULL){
	    root -> left -> next = root -> right;
		if(root -> next != NULL)
			root -> right -> next = root -> next -> left;
		else
		    root -> right -> next = NULL;
        r_connect(root -> left);
        r_connect(root -> right);
	  }
	}


public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		// r_connect(root);

	  if(root == NULL) return;
	  if(root -> left != NULL){
	    root -> left -> next = root -> right;
		if(root -> next != NULL)
			root -> right -> next = root -> next -> left;
		else
		    root -> right -> next = NULL;
        connect(root -> left);
        connect(root -> right);
	  }
	}
};


void output(TreeLinkNode *root){
  if(root == NULL) return;
  cout << root -> val << ", ";
  if(root -> next == NULL) cout << "NULL" << endl;
  else cout << root -> next -> val << endl;
  output(root -> left);
  output(root -> right);
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
        TreeLinkNode* root = new TreeLinkNode(1);
        root -> left = new TreeLinkNode(2);
        root -> right = new TreeLinkNode(3);
        root -> left -> left = new TreeLinkNode(4);
        root -> left -> right = new TreeLinkNode(5);
        root -> right -> left = new TreeLinkNode(6);
        root -> right -> right = new TreeLinkNode(7);

        output(root);
        Solution s;
        s.connect(root);
        output(root);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
