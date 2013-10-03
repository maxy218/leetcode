/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Single Number II
 *
 *        Version:  1.0
 *        Created:  10/03/2013 06:45:33 PM
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
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        const int N = 32;
        int cnt[N];
        for(int i = 0; i < N; ++i)
          cnt[i] = 0;
        for(int i = 0; i < n; ++i){
          unsigned int tmp = A[i];
          for(int j = 0; j < 32; ++j){
            if((tmp >> j) & 0x1){
              ++cnt[31 - j];
            }
          }
        }
        unsigned int res = 0;
        for(int i = 0; i < N; ++i){
          res <<= 1;
          if(cnt[i]%3 == 1){
            ++res;
          }
        }
        return (int)res;
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
  int A[] = {-1, 2, -3, -1, 2, -1, 2};
  int B[] = {-1};
  cout << s.singleNumber(A, 7) << endl;
  cout << s.singleNumber(B, 1) << endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
