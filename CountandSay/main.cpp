/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Count and Say
 *
 *        Version:  1.0
 *        Created:  10/07/2013 01:29:21 PM
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
#include	<iostream>
#include	<cstdio>
using namespace std;

class Solution {
public:
    string count(const string& str){
      int len = str.length();
      if(len == 1)
        return string(1, '1') + str;

      char num = str[0];
      int cnt = 1;
      char cntStr[1000];
      string res;
      for(int i = 1; i < len; ++i){
        if(str[i] == str[i - 1]){
          ++cnt;
        }
        else{
          sprintf(cntStr, "%d", cnt);
          res += string(cntStr) + string(1, num);
          num = str[i];
          cnt = 1;
        }
      }
      sprintf(cntStr, "%d", cnt);
      res += string(cntStr) + string(1, num);
      return res;
    }

    string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int idx = 1;
        string pre = "1";
        string next = pre;
        while(idx < n){
          next = count(pre);
          pre = next;
          ++idx;
        }
        return next;
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
  cout << s.countAndSay(1) << endl;
  cout << s.countAndSay(2) << endl;
  cout << s.countAndSay(3) << endl;
  cout << s.countAndSay(4) << endl;
  cout << s.countAndSay(5) << endl;
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
