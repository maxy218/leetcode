/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Remove Element
 *
 *        Version:  1.0
 *        Created:  10/03/2013 08:52:02 PM
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
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0) return 0;
        int l = 0, r = 0;
        for(; r < n; ++r){
          if(A[r] != elem){
             A[l++] = A[r];
          }
        }
        return l;
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
  int A[] = {2};
  cout << s.removeElement(A, 1, 1) << endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
