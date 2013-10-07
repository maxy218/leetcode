/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Length of Last Word
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 08时49分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s == NULL)
            return 0;
        int len = strlen(s);
        if(len == 0)
            return 0;
            
        int r = len - 1;
        while(r >= 0 && s[r] == ' '){
            --r;
        }
        if(r < 0) // no word
            return 0;
        
        int l = r - 1;
        while(l >= 0 && s[l] != ' '){
            --l;
        }
//        if(l < 0)// only one word and there's no space in the front of the word.
//            return r + 1; // it's the same with (r - l)
        return r - l;
    }
};
