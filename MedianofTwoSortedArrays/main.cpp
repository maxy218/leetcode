/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Median of Two Sorted Arrays
 *
 *        Version:  1.0
 *        Created:  10/02/2013 03:45:21 PM
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
#include	<cassert>
#include	<algorithm>
using namespace std;

#define DEBUG

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int tot = m + n;
        if(tot & 0x1) // elem number is odd
          return rFindKthElem2Arrays(A, m, B, n, (tot >> 1) + 1);
        else
          return (rFindKthElem2Arrays(A, m, B, n, (tot >> 1)) + rFindKthElem2Arrays(A, m, B, n, (tot >> 1) + 1)) / 2;
    }

    int min(int a, int b){
      return a < b ? a : b;
    }

    double rFindKthElem2Arrays(int A[], int m, int B[], int n, int k){
      if(m > n)
        return rFindKthElem2Arrays(B, n, A, m, k);
      if(m == 0)
        return B[k - 1];
      if(k == 1)
        return min(A[0], B[0]);

      int pa = min(k >> 1, m); int pb = k - pa;
      if(A[pa - 1] > B[pb - 1])
        return rFindKthElem2Arrays(A, m, B + pb, n - pb, k - pb);
      else if(A[pa - 1] < B[pb - 1])
        return rFindKthElem2Arrays(A + pa, m - pa, B, n, k - pa);
      else
        return A[pa - 1];
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
  srand(time(NULL));
  const int N = 10;
  const int NA = N; const int NB = N;  
  int* A = new int[NA];
  int* B = new int[NB];
  int* tot = new int[NA + NB];

  for(int i = 0; i < NA; ++i){
    tot[i] = A[i] = rand() % 100;
  }
  for(int i = 0; i < NB; ++i){
    tot[NA + i] = B[i] = rand() % 100;
  }



  sort(A, A + NA);
  sort(B, B + NB);
  sort(tot, tot + NA + NB);

  output(A, NA);
  output(B, NB);
  output(tot, NA + NB);

  Solution s;
  cout << "mid: " << s.findMedianSortedArrays(A, NA, B, NB) << endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

