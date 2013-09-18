/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Convert Sorted List to Binary Search Tree
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
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

	TreeNode * r_sortedListToBST(ListNode *head, ListNode * stopPoint){
		if(head == NULL || head == stopPoint) return NULL;
		ListNode *ptr1 = head;
		ListNode *ptr2 = head;
		while(ptr2 != stopPoint && ptr2 -> next != stopPoint){
			ptr1 = ptr1 -> next;
			ptr2 = ptr2 -> next -> next;
		}
		TreeNode* root = new TreeNode(ptr1 -> val);
		root -> left = r_sortedListToBST(head, ptr1);
		root -> right = r_sortedListToBST(ptr1 -> next, stopPoint);
		return root;
	}

public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return NULL;
		if(head -> next == NULL) return new TreeNode(head -> val);
		return r_sortedListToBST(head, NULL);
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
	ListNode* head = new ListNode(1);
	head -> next = new ListNode(3);
	head -> next -> next = new ListNode(5);
	head -> next -> next -> next = new ListNode(7);
	Solution s;
	TreeNode* root = s.sortedListToBST(head);
	cout << endl;
	TraverseTree(root);
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
