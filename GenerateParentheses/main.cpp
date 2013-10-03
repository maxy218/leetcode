/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Generate Parentheses 
 *
 *        Version:  1.0
 *        Created:  10/03/2013 04:25:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<string>
#include	<vector>
#include	<iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
      if(n == 0)
        return vector<string>(1, "");
      if(n == 1)
        return vector<string>(1, "()");

      vector<string> res;
      for(int i = 0; i < n; ++i){
        vector<string> tmp1 = generateParenthesis(i);
        vector<string> tmp2 = generateParenthesis(n - i - 1);
        for(int j = 0; j < tmp1.size(); ++j){
          for(int k = 0; k < tmp2.size(); ++k){
            res.push_back("(" + tmp1[j] + ")" + tmp2[k]);
          }
        }
      }
      return res;
    }
};

void output(const vector<string> & strs){
  for(int i = 0 ; i < strs.size(); ++i){
    cout << strs[i] << ", ";
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
  vector<string> strs = s.generateParenthesis(3);
  output(strs);
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
