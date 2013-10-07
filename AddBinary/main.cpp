/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Add Binary
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 10时16分29秒
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
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(a.length() == 0)
            return b;
        if(b.length() == 0)
            return a;
        
        int carry = 0;
        string res = "";
        int idx1 = a.length() - 1, idx2 = b.length() - 1;
        while(idx1 >= 0 && idx2 >= 0){
            int sum = a[idx1--] - '0' + b[idx2--] - '0' + carry;
            carry = sum / 2;
            sum = sum % 2;
            res = string(1, sum + '0') + res;
        }
        while(idx1 >= 0){
            int sum = a[idx1--] - '0' + carry;
            carry = sum / 2;
            sum = sum % 2;
            res = string(1, sum + '0') + res;
        }
        while(idx2 >= 0){
            int sum = b[idx2--] - '0' + carry;
            carry = sum / 2;
            sum = sum % 2;
            res = string(1, sum + '0') + res;
        }
        if(carry > 0){
            res = string(1, carry + '0') + res;
        }
        return res;
    }
};
