/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Partition List
 *
 *        Version:  1.0
 *        Created:  09/29/2013 01:19:19 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include  <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head || !head -> next) return head;

        ListNode* cur = head;
        //make sure that the first element is < x.
        if(head -> val >= x){
          while(cur -> next != NULL && cur -> next -> val >= x){
            cur = cur -> next;
          }
          if(cur -> next == NULL)
            return head;
          ListNode* tmp = cur -> next;
          cur -> next = cur -> next -> next;
          tmp -> next = head;
          head = tmp;
        }

        ListNode* l = head;
        ListNode* r = head;
        // initialize the l and r.
        while(l -> next != NULL && l -> next -> val < x){
          l = l -> next;
        }
        if(l -> next == NULL) // there's no elements >= x
          return head;
        r = l -> next;
        while(r -> next != NULL && r -> next -> val >= x){
          r = r -> next;
        }
        if(r -> next == NULL) // there's no elements < x in the right half
          return head;
        while(r -> next != NULL){
          if(r -> next -> val < x){
            ListNode* tmp = r -> next;
            r -> next = r -> next -> next;
            tmp -> next = l -> next;
            l -> next = tmp;
            l = tmp;
          }
          else{
            r = r -> next;
          }
        }
        return head;
    }


    ListNode *partition_v2(ListNode *head, int x) {// doesn't ok: "You should preserve the original relative order of the nodes in each of the two partitions."
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* l = head;
        ListNode* r = head;
        while(r != NULL){
          if(r -> val < x){
            int tmp = l -> val;
            l -> val = r -> val;
            r -> val = tmp;
            l = l -> next;
          }
          r = r -> next;
        }
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

int main(){
/*  ListNode* head = new ListNode(1);
  head -> next = new ListNode(4);
  head -> next -> next = new ListNode(3);
  head -> next -> next -> next = new ListNode(2);
  head -> next -> next -> next -> next = new ListNode(5);
  head -> next -> next -> next -> next -> next = new ListNode(2);
*/


  ListNode* head = new ListNode(1);
  head -> next = new ListNode(1);
//  head -> next -> next = new ListNode(1);


  output(head);

  Solution s;
  ListNode* newHead = s.partition(head, 2);
  output(newHead);
}
