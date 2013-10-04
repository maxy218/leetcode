/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Valid Number
 *
 *        Version:  1.0
 *        Created:  10/04/2013 10:16:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<cstring>
#include	<iostream>
using namespace std;


class Solution {
public:
    bool isNumeric(char c){
      return (c >= '0' && c <= '9');
    }
    bool isSpace(char c){
      return (c == ' ' || c == '\t');
    }

    bool isInt(const char* s, int l, int r){
      if(l > r) return false;
      int i = l;
      while(isSpace(s[i])) ++i;
      if(i > r) return false; // if only space and no valid number, return false.
      for(; i <= r; ++i){
        if(isSpace(s[i])) break;
        else if(!isNumeric(s[i])) return false;
      }
      for(; i <= r; ++i){
        if(!isSpace(s[i])) return false; // if the string has one space in the middle and not end with space, return false.
      }
      return true;
    }

    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // it's ambiguous:
        //    .1 ?   0xabc ?  
        //    + ?   - ?   +10 ?    -0.1?    -.1?


        if(!s) return false;
        int len = strlen(s);
        /*bool spaceFront = true; // when it's true, the space is allowd. It's allowed if the space is at the end, but there's no need to use a var to flag it.
        bool point = true; // when it's true, the point is allowed. the right part of the sci is not allowed to contain a "."
        bool sci = true; // if it's true, e or E is allowed.

        for(int i = 0; i < len; ++i){
          
        }*/


        int posPoint = -1; int posSci = -1; // -1 means not exist. if double exist, return false.
        for(int i = 0; i < len; ++i){
          if(s[i] == '.'){
            if(posPoint == -1) posPoint = i;
            else return false;
          }
          if(s[i] == 'e' || s[i] == 'E'){
            if(posSci == -1) posSci = i;
            else return false;
          }
        }
        if(posPoint != -1 && posSci != -1 && posPoint > posSci) // if both exist, the point must be at the left hand of the e or E
          return false;

        if(posPoint == -1 && posSci == -1)
          return isInt(s, 0, len - 1);
        else if(posPoint != -1 && posSci == -1 ){
          if(posPoint == 0)
            return isInt(s, 1, len - 1);
          else
            return isInt(s, 0, posPoint - 1) && isInt(s, posPoint + 1, len - 1);
        }
        else if(posPoint == -1 && posSci != -1)
          return isInt(s, 0, posSci - 1) && isInt(s, posSci + 1, len - 1);
        else if(posPoint != -1 && posSci != -1){
          if(posPoint == 0)
            return isInt(s, 1, posSci - 1) && isInt(s, posSci + 1, len - 1);
          else
            return isInt(s, 0, posPoint - 1) && isInt(s, posPoint + 1,  posSci - 1) && isInt(s, posSci + 1, len - 1);
        }
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
  cout << s.isNumber("0") << endl;
  cout << s.isNumber(" 0.1 ") << endl;
  cout << s.isNumber("abc") << endl;
  cout << s.isNumber("1 a") << endl;
  cout << s.isNumber("2e10") << endl;
  
  cout << s.isNumber("2.0e10") << endl;
  cout << s.isNumber("0.2e10") << endl;
  cout << s.isNumber(".2e10") << endl;
  cout << s.isNumber("2.e10") << endl;
  cout << s.isNumber("") << endl;
  cout << s.isNumber(" ") << endl;
  
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
