/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Best Time to Buy and Sell Stock
 *
 *        Version:  1.0
 *        Created:  10/06/2013 05:42:11 PM
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
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(prices.size() == 0)
            return 0;
        int min = prices[0];
        int maxPro = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] - min > maxPro){
                maxPro = prices[i] - min;
            }
            else if(prices[i] < min){
                min = prices[i];
            }
        }
        return maxPro;
    }
};
