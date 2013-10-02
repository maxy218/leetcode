/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Regular Expression Matching
 *
 *        Version:  1.0
 *        Created:  10/02/2013 07:49:46 PM
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
#include	<cstring>
#include	<vector>
using namespace std;

void output(const vector<vector<bool> > & Mat){
  for(int i = 0; i < Mat.size(); ++i){
    for(int j = 0; j < Mat[i].size(); ++j){
      cout << Mat[i][j] << ", ";
    }
    cout << endl;
  }
}

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        int lenStr = strlen(s); int lenPat = strlen(p);
        vector<vector<bool> > Mat = vector<vector<bool> >(lenPat + 1, vector<bool>(lenStr + 1, false) );
        Mat[0][0] = true;
        for(int i = 0; i <= lenPat; ++i){
          if(i < lenPat - 1 && p[i + 1] == '*'){
            Mat[i + 1][0] = true;
            Mat[i + 2][0] = true;
            ++i;
          }
          else{
            break;
          }
        }

        for(int i = 0; i < lenPat; ++i){
          for(int j = 0; j < lenStr; ++j){
            if((p[i] == s[j] || p[i] == '.') && Mat[i][j]){  // if the char is same and the left-upper elem in the matrix is true
              Mat[i + 1][j + 1] = true;
              if(i < lenPat - 1 && p[i + 1] == '*'){ // if next char in pattern is '*', j will keep increasing before the next different char occur.
                Mat[i + 2][j + 1] = true;
                while(j < lenStr - 1 && (p[i] == s[j + 1] || p[i] == '.')){
                  ++j;
                  Mat[i + 1][j + 1] = true;
                  Mat[i + 2][j + 1] = true;// the line of the '*' is also assigned with true.
                }
              }
            }
            else if(i < lenPat - 1 && p[i + 1] == '*'){
              Mat[i + 2][j + 1] = Mat[i + 1][j + 1] || Mat[i][j + 1];
            }
          }
          if(p[i + 1] == '*') ++i;// skip the *
        }
//        output(Mat);
        return Mat[lenPat][lenStr];
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
  cout << s.isMatch("aa","a") << endl;
  cout << s.isMatch("aa","aa") << endl;
  cout << s.isMatch("aaa","aa") << endl;
  cout << s.isMatch("aa", "a*") << endl;
  cout << s.isMatch("aa", ".*") << endl;
  cout << s.isMatch("ab", ".*") << endl;
  cout << s.isMatch("aab", "c*a*b") << endl;
  cout << s.isMatch("aaa", "ab*ac*a") << endl;

  cout << s.isMatch("aaa", "ab*a*c*a") << endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
