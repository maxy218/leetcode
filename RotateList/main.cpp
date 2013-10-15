/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年10月15日 21时38分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(k < 0 || head == NULL)
			return NULL;
		
		int len = 0;
		ListNode *cur = head;
		while(cur){
			++len;
			cur = cur -> next;
		}
		
		k %= len;
		
		if(k == 0)
			return head;
			
		int cnt = k;
		ListNode* right = head;
		ListNode* left = head;
		while(cnt > 0 && right != NULL){
			right = right -> next;
			--cnt;
		}
		if(right == NULL){ // if right == NULL, it means that the list is not long enough. Do nothing.
			return head;
		}
		while(right -> next != NULL){
			right = right -> next;
			left = left -> next;
		}
		
		ListNode* newHead = left -> next;
		left -> next = NULL;
		right -> next = head;
		return newHead;
    }
};
