/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Climbing Stairs
 *
 *        Version:  1.0
 *        Created:  10/03/2013 09:04:53 PM
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
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 2) return n;
        
        int* cnt = new int[n];
        cnt[0] = 1; cnt[1] = 2;
        for(int i = 3; i <= n; ++i){
            cnt[i - 1] = cnt[i - 2] + cnt[i - 3];
        }
        return cnt[n - 1];
    }
};
