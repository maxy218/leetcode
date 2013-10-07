/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Search for a Range
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 11时18分34秒
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
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int l = 0, r = n - 1;
        while(r >= l){
            int mid = l + ((r - l) >> 1);
            if(target <= A[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        int lEnd = l;
        
        l = 0, r = n - 1;
        while(r >= l){
            int mid = l + ((r - l) >> 1);
            if(target < A[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        int rEnd = r;
        
        if(lEnd > rEnd)
            return vector<int>(2, -1);
            
        vector<int> res;
        res.push_back(lEnd);
        res.push_back(rEnd);
        return res;
    }
};
