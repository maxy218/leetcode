/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Letter Combinations of a Phone Number
 *
 *        Version:  1.0
 *        Created:  10/03/2013 09:17:06 AM
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
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> digTab = vector<string>(10);
        digTab[1] = "";
        digTab[2] = "abc";
        digTab[3] = "def";
        digTab[4] = "ghi";
        digTab[5] = "jkl";
        digTab[6] = "mno";
        digTab[7] = "pqrs";
        digTab[8] = "tuv";
        digTab[9] = "wxyz";

        if(digits.size() == 0)
          return vector<string>(1, "");
 
        vector<string> res = vector<string>(1, "");
        for(int i = 0; i < digits.size(); ++i){
          string& str = digTab[digits[i] - '0'];
          vector<string> tmpRes;
          for(int j = 0; j < str.size(); ++j){
            for(int k = 0; k < res.size(); ++k){
              tmpRes.push_back(res[k] + string(1, str[j]));
            }
          }
          res = tmpRes;
        }
        return res;
    }
};

void output(const vector<string>& strs){
  for(int i = 0; i < strs.size(); ++i){
    cout << strs[i] << endl;
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
  vector<string> res = s.letterCombinations("23");
  output(res);
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
