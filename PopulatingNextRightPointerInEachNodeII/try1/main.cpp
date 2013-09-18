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
#include	<utility>
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

        pair<int, TreeLinkNode*>  curPtr = pair<int, TreeLinkNode*>(0, root);
        pair<int, TreeLinkNode*>  prePtr = pair<int, TreeLinkNode*>(0, root);
        list<pair<int, TreeLinkNode*> > queue;
        if(root -> left) queue.push_back(pair<int, TreeLinkNode*>(1, root -> left));
        if(root -> right) queue.push_back(pair<int, TreeLinkNode*>(1, root -> right));
        
        while(queue.size() > 0){
          prePtr = curPtr;
          curPtr = queue.front();
          queue.pop_front();
          if(curPtr.first > prePtr.first) prePtr.second -> next = NULL;
          else prePtr.second -> next = curPtr.second;
          if(curPtr.second -> left) queue.push_back(pair<int, TreeLinkNode*>(curPtr.first + 1, curPtr.second -> left));
          if(curPtr.second -> right) queue.push_back(pair<int, TreeLinkNode*>(curPtr.first + 1, curPtr.second -> right));
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
