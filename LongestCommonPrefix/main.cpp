/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Longest Common Prefix
 *
 *        Version:  1.0
 *        Created:  10/03/2013 08:56:12 AM
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
#include	<string>
#include	<algorithm>
using namespace std;

class Solution {
public:

    void output(const vector<string> & strs){
      for(int i = 0; i < strs.size(); ++i){
        cout << strs[i] << endl;
      }
      cout << endl;
    }

    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(strs.size() == 0)
          return "";
        if(strs.size() == 1)
          return strs[0];
        sort(strs.begin(), strs.end());
        int len = 0;
        while(strs[0][len] == strs[strs.size() - 1][len])
          ++len;
        if(len != 0)
          return strs[0].substr(0,len);
        else
          return "";
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
  vector<string> strs;
  strs.push_back("abd");
  strs.push_back("abc");
  strs.push_back("aba");
  strs.push_back("ab");
  strs.push_back("bcd");

  s.longestCommonPrefix(strs);

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
