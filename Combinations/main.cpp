/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Combinations
 *
 *        Version:  1.0
 *        Created:  09/29/2013 02:53:23 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<vector>
#include	<set>
using namespace std;


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       vector<bool> unused(n);
       for(int i = 0; i < n; ++i)
          unused[i] = true;
       vector<int> subComb;
       vector<vector<int> > totComb;
       rCombine(n, k, unused, subComb, totComb);
       return totComb;
    }

    void rCombine(int n, int k, vector<bool>& unused, vector<int>& subComb, vector<vector<int> > & totComb){
      if(subComb.size() == k){
        totComb.push_back(subComb);
        return;
      }

      int nextNum = 1;
      if(subComb.size() > 0)
        nextNum = subComb[subComb.size() - 1]; // should be subComb[subComb.size() - 1]+1, but it's index, so still subComb[subComb.size() - 1]
      for(int i = nextNum - 1; i < n; ++i){
        if(unused[i]){
          subComb.push_back(i + 1);
          unused[i] = false;
          rCombine(n, k, unused, subComb, totComb);
          subComb.pop_back();
          unused[i] = true;
        }
      }
    }
};

void output(vector<vector<int> >& vec){
  for(int i = 0; i < vec.size(); ++i){
    for(int j = 0; j < vec[i].size(); ++j){
      cout << vec[i][j] << ", ";
    }
    cout << endl;
  }
}

int main(){
  Solution s;
  vector<vector<int> > vec = s.combine(4,2);
  output(vec); 
}
