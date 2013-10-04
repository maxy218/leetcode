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

    bool isInt(const char* s, int l, int r, bool ifSignAllowed, bool ifOnlySignAllowed){
      if(l > r) return false;
      int i = l;

      if(s[i] == '+' || s[i] == '-'){
        if(ifSignAllowed) // if sign allowed and the cur char is sign char
          ++i;
        else // if sign is not allowed
          return false;
      }
      if(!ifOnlySignAllowed && i > r) return false; // there's only one sign char in this int number

      for(; i <= r; ++i){
        if(!isNumeric(s[i])) return false;
      }
      return true;
    }

    bool isFloat(const char* s, int l, int r){
      if(l > r) return false;
      if(isInt(s, l, r, true, false)) return true; // int is one kind of float
      int posPoint = -1;
      for(int i = l; i <= r; ++i){
        if(s[i] == '.'){
          if(posPoint == -1) posPoint = i;
          else return false;
        }
      }
      if(posPoint == -1) // if no point, and not the int at the same time, there's something wrong 
        return false;
      else if(posPoint == l)
        return isInt(s, l + 1, r, false, false); // at the right hand of the point, sign char is not allowed.
      else if(posPoint == r) // if . is the last char in the string
        return isInt(s, l, r - 1, true, false); // at the left hand of the point, sign char is allowed.
      else
        return isInt(s, l, posPoint - 1, true, true) && isInt(s, posPoint + 1, r, false, false);
    }


    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // it's ambiguous:
        //    .1 ?   0xabc ?  
        //    + ?   - ?   +10 ?    -0.1?    -.1?


        if(!s) return false;
        int len = strlen(s);
        // remove space at both ends.
        int l = 0; int r = len - 1;
        while(l < len && isSpace(s[l]))
          ++l;
        if(l > r) // if the string is full of space, return false;
          return false;
        while(r >= 0 && isSpace(s[r]))
          --r;

        int posSci = -1; // -1 means not exist. if double exist, return false.
        for(int i = l; i <= r; ++i){
          if(s[i] == 'e' || s[i] == 'E'){
            if(posSci == -1) posSci = i;
            else return false;
          }
        }

        if(posSci == -1)
          return isFloat(s, l, r);
        else{
          return isFloat(s, l, posSci - 1) && isInt(s, posSci + 1, r, true, false);
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
  cout << s.isNumber("3.") << endl;
  cout << s.isNumber(".3") << endl;

  cout << s.isNumber("+0") << endl;
  cout << s.isNumber("+0.3") << endl;
  cout << s.isNumber("+.3") << endl;
  cout << s.isNumber("-.3") << endl;
  cout << s.isNumber("-3.") << endl;
  cout << s.isNumber("3.0") << endl;

  cout << s.isNumber("3.0e+3") << endl;
  cout << s.isNumber("3.0e +3") << endl;

  // should be false;
  cout << "should all be false." << endl;
  cout << s.isNumber("3.-") << endl;
  cout << s.isNumber("3.-1") << endl;
  cout << s.isNumber(". 1") << endl;
  cout << s.isNumber(" ") << endl;
  cout << s.isNumber("4e+") << endl;

  double a = -.1;
  cout << a << endl;
  
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
