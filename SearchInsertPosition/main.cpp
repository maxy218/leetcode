/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Search Insert Position
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 11时07分50秒
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
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int l = 0, r = n - 1;
        while(r >= l){
            int mid = l + ((r - l) >> 1);
            if(A[mid] == target)
                return mid;
            else if(target > A[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
}
