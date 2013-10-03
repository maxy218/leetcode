/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Valid Parentheses
 *
 *        Version:  1.0
 *        Created:  10/03/2013 06:44:12 PM
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
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        list<char> stack;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push_back(s[i]);
            }
            else{
                if(s[i] == ')'){
                    if(stack.back() == '('){
                        stack.pop_back();
                    }
                    else{
                        return false;
                    }
                }
                else if(s[i] == ']'){
                    if(stack.back() == '['){
                        stack.pop_back();
                    }
                    else{
                        return false;
                    }
                }
                else if(s[i] == '}'){
                    if(stack.back() == '{'){
                        stack.pop_back();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(stack.size() > 0) return false;
        else return true;
    }
};
