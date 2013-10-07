/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Remove Duplicates from Sorted Array II 
 *
 *        Version:  1.0
 *        Created:  10/06/2013 11:49:58 PM
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

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 2) // if the number of elements are <= 2, do nothing.
            return n;

        int l = 0, r = 0;
        int cnt = 1;
        for(; r < n - 1; ++ r){
            if(A[r] == A[r + 1] && cnt >= 2){
                continue;
            }
            else{
                A[l++] = A[r];
                if(A[r] != A[r + 1])
                    cnt = 1;
                else
                    ++cnt;
            }
        }
        A[l++] = A[r];
        return l;
    }
};

void output(int A[], int n){
  for(int i = 0; i < n; ++i){
    cout << A[i] << ", ";
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
  int A[] = {1,1,1,2,2,2,3};
  Solution s;
  int len;
  cout << (len = s.removeDuplicates(A, 7))<< endl;
  output(A, len);
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
