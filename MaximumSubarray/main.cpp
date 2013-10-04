/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Maximum Subarray
 *
 *        Version:  1.0
 *        Created:  2013年10月04日 21时56分36秒
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
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int maxSum = A[0];
        int curSum = A[0] > 0 ? A[0] : 0;
        for(int i = 1; i < n; ++i){
            curSum += A[i];
            if(curSum > maxSum)
                maxSum = curSum;
            if(curSum < 0)
                curSum = 0;
        }
        return maxSum;
    }
};
