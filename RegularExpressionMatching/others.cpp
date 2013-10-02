/*
 * =====================================================================================
 *
 *       Filename:  others.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/02/2013 09:29:58 PM
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
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if( 0 == *p) return 0 == *s;  
  
        if(*(p+1) != '*')  
        {  
            if(*p == *s || (*p) == '.' && (*s) != 0)  
            {  
                return isMatch(s+1, p+1);  
            }  
            return false;  
        }  
        else  
        {  
            while(*p == *s || ((*p) == '.' && (*s) != 0))  
            {  
                if(isMatch(s, p + 2))  
                {  
                    return true;  
                }  
                s++;  
            }  
            return isMatch(s, p + 2);  
  
        }  
    }
};
