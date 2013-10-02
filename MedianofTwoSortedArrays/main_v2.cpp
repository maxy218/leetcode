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
        int k = m + n;
        double res = 0.0 + rFindKthElem2Arrays(A, m, B, n, k/2+1);
        if(k % 2 == 0)res = (res + rFindKthElem2Arrays(A, m, B, n, k/2))/2;
        return res; 
    }

    double rFindKthElem2Arrays(int A[], int m, int B[], int n, int k){
        if(m == 0)return B[k-1];
        if(n == 0)return A[k-1];
        int i = m>>1, j = n>>1, *p, *q, t;
        if(A[i] <= B[j])p = A, q = B;
        else p = B, q = A, swap(i, j), swap(m, n);
        t = i + j + 1;
        if(t >= k)return rFindKthElem2Arrays(p, m, q, j, k);
        else if(t < k)return rFindKthElem2Arrays(p+i+1, m-i-1, q, n, k-i-1);
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

