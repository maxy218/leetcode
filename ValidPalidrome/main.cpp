/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  if valid palindrome
 *
 *        Version:  1.0
 *        Created:  2013年09月11日 11时00分08秒
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
#include	<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0; int j = 0; int len = s.length();
        //pre-progress: lower case; alphanumber 
        while(j < len){
          if((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')){
            if(s[j] >= 'A' && s[j] <= 'Z') s[i++] = s[j] + 'a' - 'A';
            else s[i++] = s[j];
          }
          ++j;
        }

        int shinkedLen = i;
        int l = 0; int r = shinkedLen - 1;
        while(l < r){
          if(s[l] != s[r]) return false;
          ++l; --r;
        }
        return true;
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
        cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
        cout << s.isPalindrome("race a car") << endl;
        cout << s.isPalindrome("1a2") << endl;

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
