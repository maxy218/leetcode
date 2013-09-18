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
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(rowIndex + 1);
        for(int l = 0; l <= rowIndex; ++l){
          for(int i = l; i >= 0; --i){
            if(i == 0) result[i] = 1;
            else if(i == l) result[i] = 1;
            else result[i] += result[i-1];
          } 
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
        vector<int> vec = s.getRow(3);
        output(vec);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
