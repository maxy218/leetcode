/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Permutations
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 10时40分46秒
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

void output(const vector<int> & vec){
  for(int i = 0; i < vec.size(); ++i){
      cout << vec[i]<< ", ";
  }
  cout << endl;
}

void output(const vector<vector<int> > & vecs){
  for(int i = 0; i < vecs.size(); ++i){
    for(int j = 0; j < vecs[0].size(); ++j){
      cout << vecs[i][j] << ", ";
    }
    cout << endl;
  }
}

class Solution {
public:
    void swap(int& a, int& b){
        int t = a;
        a = b;
        b = t;
    }
    
    void reverse(vector<int>& vec, int l, int r){
        while(r > l){
            swap(vec[l++], vec[r--]);
        }
    }

    void nextPermutation(vector<int>& num){
        int len = num.size();
        int idx = len - 2;
        while(idx >= 0 && num[idx] >= num[idx + 1]){
            --idx;
        }
        
        if(idx < 0){ // no next-permutation
            reverse(num, 0, num.size() - 1);
            return;
        }
        
        int swapIdx = len - 1;
        while(swapIdx > idx && num[swapIdx] <= num[idx]){
            --swapIdx;
        }
        
        swap(num[swapIdx], num[idx]);
        reverse(num, idx + 1, num.size() - 1);
    }

   bool isSameVec(const vector<int>& vec1, const vector<int>& vec2){
     if(vec1.size() != vec2.size())
       return false;
     int len = vec1.size();
     for(int i = 0; i < len; ++i){
       if(vec1[i] != vec2[i])
         return false;
     }
     return true;
   }

    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(num.size() == 1)
            return vector<vector<int> >(1, num);
        
        vector<vector<int> > res;
        res.push_back(num);
        
        vector<int> backupNum = num;

        nextPermutation(num);
        while(! isSameVec(num, backupNum)){
            res.push_back(num);
            nextPermutation(num);
        }
        return res;
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
  int A[] = {3,2,1};
  vector<int> vec(A, A + 3);
  vector<vector<int> > res = s.permute(vec);
  output(res);
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
