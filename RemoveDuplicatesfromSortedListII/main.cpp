/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Remove Duplicates from Sorted List II
 *
 *        Version:  1.0
 *        Created:  10/06/2013 10:52:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL || head -> next == NULL)
            return head;
        
        ListNode* pre = new ListNode(-1);
        pre -> next = head;
        ListNode* cur = pre;
        int dupNum = -1;
        while(cur != NULL && cur -> next != NULL && cur -> next -> next != NULL){
            if(cur -> next -> val == cur -> next -> next -> val){
                dupNum = cur -> next -> val;
                while(cur -> next != NULL && cur -> next -> val == dupNum){
                    ListNode* tmp = cur -> next;
                    cur -> next = cur -> next -> next;
                    delete tmp;
                }
            }
            else{
                cur = cur -> next;
            }
        }
        head = pre -> next;
        delete pre;
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

int main(){
  ListNode* head = new ListNode(1);
  head -> next = new ListNode(1);

  Solution s;
  output(head);
  head = s.deleteDuplicates(head);
  output(head);
}

