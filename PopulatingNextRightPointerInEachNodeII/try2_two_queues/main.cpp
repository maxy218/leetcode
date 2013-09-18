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
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return;
        
        list<TreeLinkNode*> queue[2];
        TreeLinkNode * curPtr = root;
        int flag = 0;
        if(root -> left) queue[0].push_back(root -> left);
        if(root -> right) queue[0].push_back(root -> right);
        root -> next = NULL;
        while(queue[0].size() > 0 || queue[1].size() > 0){
          while(queue[flag].size() > 0) {
            curPtr = queue[flag].front();
            queue[flag].pop_front();
            curPtr -> next = queue[flag].front();
            if(curPtr -> left) queue[(flag + 1)%2].push_back(curPtr -> left);
            if(curPtr -> right) queue[(flag + 1)%2].push_back(curPtr -> right);
          }
          curPtr -> next = NULL;
          flag = (flag + 1)%2;
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
        root -> right -> right = new TreeLinkNode(7);

        output(root);
        Solution s;
        s.connect(root);
        output(root);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
