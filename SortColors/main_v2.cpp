/*
 * =====================================================================================
 *
 *       Filename:  main_v2.cpp
 *
 *    Description:  Sort Colors
 *
 *        Version:  1.0
 *        Created:  2013年10月08日 00时32分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<iostream>
using namespace std;

class Solution {
public:
    void swap(int& a, int& b){
        int t = a;
        a = b;
        b = t;
    }

    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // two ways counting sort
        if(n <= 1)
            return;

        int idx[2] = {-1, -1}; // idx[0]: the last 0, idx[1]: the last 1. -1 mean no 0 or 1
        int cur = 0;
        while(cur < n){
            if(A[cur] == 1){
                if(idx[1] == -1){ // if there's no 1
                    idx[1] = idx[0] + 1;
                    swap(A[idx[1]], A[cur]);
                }
                else{ 
                    swap(A[++idx[1]], A[cur]);
                }
            }
            else if(A[cur] == 0){
                if(idx[1] != -1){
                    swap(A[++idx[1]], A[cur]);
                    swap(A[++idx[0]], A[idx[1]]);
                }
                else{
                    swap(A[++idx[0]], A[cur]);
                }
            }
            // if A[cur] == 2: do nothing
            ++cur; 
        }
    }
};

void output(int A[], int n){
  for(int i = 0; i < n; ++i){
    cout << A[i] << ", ";
  }
  cout << endl;
}

int main(){
        Solution s;
	int A[] = {1,2,2,2,2,0,0,0,1,1};
        output(A, 10);
        s.sortColors(A, 10);
        output(A, 10);
        
}
