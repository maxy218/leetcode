/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Search in Rotated Sorted Array
 *
 *        Version:  1.0
 *        Created:  10/05/2013 09:58:50 AM
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

//#define DEBUG

class Solution {
public:
    int binarySearch(int A[], int l, int r, int target){
      while(r >= l){
#ifdef DEBUG
        cout << "l: " << l << "\t" << "r: " << r << endl;
#endif
        int mid = l + ((r - l) >> 1);
        if(A[mid] == target)
          return mid;
        else if(A[mid] > target)
          r = mid - 1;
        else
          l = mid + 1;
      }
      if(r < l)
        return -1;
    }

    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

        int l = 0, r = n - 1;
        while(r >= l){
#ifdef DEBUG
          cout << "l: " << l << "\t" << "r: " << r << endl;
#endif
          if(A[l] <= A[r]) // if no rotation. do nothing temp
            return binarySearch(A, l, r, target);

          if(A[l] == target)
            return l;
          if(A[r] == target)
            return r;

          int mid = l + ((r-l) >> 1);
          if(target == A[mid])
            return mid;

          if(A[mid] >= A[l]){
            if(target < A[mid] && target >= A[l])
              r = mid - 1;
            else
              l = mid + 1;
          }
          else{
            if(target > A[mid] && target <= A[r])
              l = mid + 1;
            else 
              r = mid - 1;
          }
        }
        if(r < l)
          return -1;
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
/*
  int A[] = {4, 5, 6, 7, 0, 1, 2};
  cout << s.search(A, 7, 0) << endl;
  cout << s.search(A, 7, 1) << endl;
  cout << s.search(A, 7, 2) << endl;
  cout << s.search(A, 7, 4) << endl;
  cout << s.search(A, 7, 5) << endl;
  cout << s.search(A, 7, 6) << endl;
  cout << s.search(A, 7, 7) << endl;
*/

/*  int A[] = {5, 1, 3};
  cout << s.search(A, 3, 5) << endl;
  cout << s.search(A, 3, 1) << endl;
  cout << s.search(A, 3, 3) << endl;
*/

  int A[] = {8,1,2,3,4,5,6,7};
  cout << s.search(A, 8, 1) << endl;
  cout << s.search(A, 8, 2) << endl;
  cout << s.search(A, 8, 3) << endl;
  cout << s.search(A, 8, 4) << endl;
  cout << s.search(A, 8, 5) << endl;
  cout << s.search(A, 8, 6) << endl;
  cout << s.search(A, 8, 7) << endl;

  int B[] = {3, 1};
  cout << s.search(B, 2, 1) << endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
