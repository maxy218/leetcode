/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Next Permutation
 *
 *        Version:  1.0
 *        Created:  10/05/2013 09:51:00 AM
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
#include	<vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int> &num, int l, int r){
        while(r > l){
            int tmp = num[l];
            num[l] = num[r];
            num[r] = tmp;
            --r; ++l;
        }
    }

    void swap(int & a, int & b){
        int t = a;
        a = b;
        b = t;
    }

    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(num.size() <= 1) 
            return;
        int idxFirstRev = num.size() - 2;
        while(idxFirstRev >= 0 && num[idxFirstRev] >= num[idxFirstRev + 1])
            --idxFirstRev;
        if(idxFirstRev < 0){ // if the array has been sorted in decreasing order.
            reverse(num, 0, num.size() - 1);
            return;
        }
        int idxFirstLarger = num.size() - 1;
        while(num[idxFirstLarger] <= num[idxFirstRev])
            --idxFirstLarger;
        swap(num[idxFirstRev], num[idxFirstLarger]);
        reverse(num, idxFirstRev + 1, num.size() - 1);
    }
};

void output(const vector<int> & vec){
  for(int i = 0; i < vec.size(); ++i){
    cout << vec[i] << ", ";
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
  Solution s;
//  vector<int> vec = vector<int>(2, 1);
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(1);
  output(vec);
  s.nextPermutation(vec);
  output(vec);


  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
