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
        return rFindKthElem2Arrays(A, 0, m - 1, B, 0, n - 1, (n + m) >> 1);
    }

    double findKthElem(int A[], int start, int end, int k){
      assert(end >= start);
      assert(end - start >= k);
      return A[start + k];
    }

    double rFindKthElem2Arrays(int A[], int startA, int endA, int B[], int startB, int endB, int k){
    #ifdef DEBUG
      cout << "new invoke paras: " << startA << ", " << endA << ",\t" << startB << ", " << endB << ":\t" << k << endl;
    #endif
      int midA = 0; int midB = 0;
      if(startA > endA){
        return findKthElem(B, startB, endB, k);
      }
      if(startB > endB){
        return findKthElem(A, startA, endA, k);
      }
      midA = startA + (endA - startA) >> 1;
      midB = startB + (endB - startB) >> 1;

    #ifdef DEBUG
      cout << "midA: " << midA << ", midB: " << midB << endl;
    #endif
  
      int lenA = endA - startA + 1;
      int lenB = endB - startB + 1;
      int lenTot = lenA + lenB;
      if(k >= (lenTot >> 1)){
        if(A[midA] > B[midB]){
          return rFindKthElem2Arrays(A, startA, endA, B, midB + 1, endB, k - (lenB >> 1)); // midB + 1?
        }
        else{
          return rFindKthElem2Arrays(A, midA + 1, endA, B, startB, endB, k - (lenA >> 1)); // midB + 1?
        }
      }
      else{
        if(A[midA] > B[midB]){
          return rFindKthElem2Arrays(A, startA, midA, B, startB, endB, k); 
        }
        else{
          return rFindKthElem2Arrays(A, startA, endA, B, startB, midB, k); 
        }
      }


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
  cout << "answer: " << tot[(NA + NB) >> 1]<< endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

