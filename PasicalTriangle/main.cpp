/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  pasical triangle
 *
 *        Version:  1.0
 *        Created:  2013年09月11日 13时20分13秒
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
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result(numRows);
        for(int l = 0; l < numRows; ++l){
          vector<int> tmp(l+1);
          tmp[0] = tmp[l] = 1;
          for(int i = l - 1; i > 0; --i){
            tmp[i] = result[l - 1][i] + result[l - 1][i-1];
          }   
          result[l] = tmp;
        }   
        return result;
    }
};

void output(const vector<int> & vec){
  int len = vec.size();
  for(int i = 0; i < len; ++i){
    cout << vec[i] << ", ";
  }
  cout << endl;
}

void output(const vector< vector<int> > & vec){
  int len1 = vec.size();
  for(int i = 0; i < len1; ++i){
    int len2 = vec[i].size();
    for(int j = 0; j < len2; ++j){
      cout << vec[i][j] << ", ";
    }
    cout << endl;
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
        vector<vector<int> > vec = s.generate(5);
        output(vec);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
