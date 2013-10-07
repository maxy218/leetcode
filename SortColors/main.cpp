/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Sort Colors
 *
 *        Version:  1.0
 *        Created:  2013年10月08日 00时13分06秒
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
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // two ways counting sort
        if(n <= 1)
            return;
        int cnt[3] = {0, 0, 0};
        for(int i = 0; i < n; ++i){
            cnt[ A[i] ] ++;
        }
        int color = 2;
        int idx = n - 1;
        while(color >= 0){
            while(cnt[color]-- > 0){
                A[idx--] = color;
            }
            --color;
        }
    }
};
