/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Integer to Roman
 *
 *        Version:  1.0
 *        Created:  10/02/2013 09:35:26 PM
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
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        string thousands[] = {"M", "MM", "MMM"};
        string hundreds[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string tens[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ones[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        string res = "";
        if(num >= 1000){
          res += thousands[num / 1000 - 1];
          num %= 1000;
        }
        if(num >= 100){
          res += hundreds[num / 100 - 1];
          num %= 100;
        }
        if(num >= 10){
          res += tens[num / 10 - 1];
          num %= 10;
        }
        if(num > 0){
          res += ones[num - 1];
        }
        return res;
    }

    int romanToInt(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int romanNum[256];
        romanNum['I'] = 1;
        romanNum['V'] = 5;
        romanNum['X'] = 10;
        romanNum['L'] = 50;
        romanNum['C'] = 100;
        romanNum['D'] = 500;
        romanNum['M'] = 1000;

        int r = 0;
        int len = s.length();
        for(int i = 0; i < len; ++i){
          if(i < len - 1 && romanNum[s[i+1]] > romanNum[s[i]])
            r -= romanNum[s[i]];
          else
            r += romanNum[s[i]];
        }
        return r;
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
  cout << s.romanToInt(s.intToRoman(1)) << endl;
  cout << s.romanToInt(s.intToRoman(5)) << endl;
  cout << s.romanToInt(s.intToRoman(10)) << endl;
  cout << s.romanToInt(s.intToRoman(1976)) << endl;
  cout << s.romanToInt(s.intToRoman(98)) << endl;
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
