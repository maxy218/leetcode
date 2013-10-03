/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Remove Duplicates from Sorted Array
 *
 *        Version:  1.0
 *        Created:  10/03/2013 08:24:41 PM
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
        if(n <= 1) return n;
        int cnt = 1;
        for(int r = 0; r < n - 1; ++r){
          if(A[r] != A[r+1]){
            A[cnt++] = A[r+1];
          }
        }
        return cnt;
    }
};

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
 // int A[] = {1,1,2,3};
  int A[] = {1};
  cout << s.removeDuplicates(A, 1) << endl;
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
