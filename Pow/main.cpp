/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  pow(x, n)
 *
 *        Version:  1.0
 *        Created:  10/02/2013 07:36:37 PM
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
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0)
            return 1.0;
        bool ifNeg = false;
        double ret = 0.0;
        if(n < 0){
            ifNeg = true;
            n = -n;
        }
        if( n == 1){
            ret = x;
            if(ifNeg)
                ret = 1.0 / ret;
            return ret;
        }
        ret = pow(x, n >> 1);
        ret *= ret;
        if(n & 0x1)
            ret *= x;
        if(ifNeg)
            ret = 1.0 / ret;
        return ret;
    }
};
