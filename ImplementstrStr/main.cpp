/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Implement strStr()
 *
 *        Version:  1.0
 *        Created:  10/05/2013 03:02:54 PM
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
using namespace std;

class Solution {
public:
    bool strMatch(const char* src, const char* tgt){
        while(*src != '\0' && *tgt != '\0' && *src == *tgt){
            ++src;
            ++tgt;
        }
        return *tgt == '\0';
    }

    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        if(len1 < len2) 
            return NULL;
        int i = 0;
        for(; i <= len1 - len2; ++i){
            if(strMatch(&haystack[i], needle))
                return &haystack[i];
        }
        if(i > len1 - len2)
            return NULL;
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
  char A[] = "aabc";
  char B[] = "abc";
  cout << s.strStr(A, B) << endl;
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
