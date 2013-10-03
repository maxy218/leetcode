/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Merge k Sorted Lists
 *
 *        Version:  1.0
 *        Created:  10/03/2013 10:16:43 AM
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
#include	<utility>
#include	<vector>
#include	<algorithm>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    static int compare(const ListNode* op1 , const ListNode* op2){
      return op1 -> val > op2 -> val;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(lists.size() == 1)
          return lists[0];

        vector<ListNode*> heap;
        for(int i = 0; i < lists.size(); ++i){
          if(lists[i])
            heap.push_back(lists[i]);
        }
        if(heap.size() == 0)
          return NULL;
        if(heap.size() == 1)
          return heap[0];
        
        make_heap(heap.begin(), heap.end(), Solution::compare);
        
        ListNode* head = new ListNode(-1); // null head. should be deleted before return
        ListNode* cur = head;
        while(heap.size() > 0){
          cur -> next = heap.front();
          cur = cur -> next;
          pop_heap(heap.begin(), heap.end(), Solution::compare);
          heap.pop_back();
          if(cur -> next != NULL){
            heap.push_back(cur -> next);
            push_heap(heap.begin(), heap.end(), Solution::compare);
          }
        }
        ListNode* tmp = head;
        head = head -> next;
        delete tmp;
        return head;
    }
};

void output(ListNode* head){
  while(head != NULL){
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
        Solution s;
        ListNode* head1 = new ListNode(3);
        head1 -> next = new ListNode(5);
        head1 -> next -> next = new ListNode(7);
        ListNode* head2 = new ListNode(2);
        head2 -> next = new ListNode(4);
        head2 -> next -> next = new ListNode(9);
        ListNode* head3 = new ListNode(1);
        head3 -> next = new ListNode(8);
        head3 -> next -> next = new ListNode(10);
        ListNode* head4 = new ListNode(4);
        head4 -> next = new ListNode(6);
        head4 -> next -> next = new ListNode(11);

        vector<ListNode*> lists;
 //       lists.push_back(head1);
        lists.push_back(NULL);
        lists.push_back(head2);
        lists.push_back(head3);
        lists.push_back(head4);


//        lists.push_back(NULL);
//        lists.push_back(NULL);
        ListNode* head = s.mergeKLists(lists);
        output(head);
 
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
