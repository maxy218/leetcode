/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Swap Nodes in Pairs
 *
 *        Version:  1.0
 *        Created:  10/03/2013 08:37:50 PM
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

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL || head->next == NULL)
          return head;
        ListNode* cur = head;
        ListNode* next = head -> next -> next;
        head = head -> next;
        while(next != NULL && next -> next != NULL){
          cur -> next -> next = cur;
          cur -> next = next -> next;
          cur = next;
          next = cur -> next -> next;
        }
        cur -> next -> next = cur;
        cur -> next = next;
        return head;
    }
};

void output(ListNode* head){
  while(head){
    cout << head -> val << ", ";
    head = head -> next;
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
  ListNode* head = new ListNode(1);
  head -> next = new ListNode(2);
  head -> next -> next = new ListNode(3);
//  head -> next -> next -> next = new ListNode(4);
  Solution s;
  output(s.swapPairs(head));

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
