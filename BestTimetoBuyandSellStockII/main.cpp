/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Best Time to Buy and Sell Stock II 
 *
 *        Version:  1.0
 *        Created:  10/06/2013 05:42:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<vector>
#include	<iostream>
using namespace std;

class Solution {
public:

    int maxProfit(vector<int> &prices, int l, int r) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(l == r)
            return 0;
        int min = prices[l];
        int maxPro = 0;
        for(int i = l + 1; i <= r; ++i){
            if(prices[i] - min > maxPro){
                maxPro = prices[i] - min;
            }
            else if(prices[i] < min){
                min = prices[i];
            }
        }
        return maxPro;
    }

    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(prices.size() == 0 || prices.size() == 1)
          return 0;
        int maxPro = 0;
        vector<int> revPoint;
        for(int i = 0; i < prices.size() - 1; ++i){
          if(prices[i] > prices[i + 1])
             revPoint.push_back(i);
        }
        revPoint.push_back(prices.size() - 1);
        if(revPoint.size() == 0) // if the prices is always increasing
          return prices[prices.size() - 1] - prices[0];
        int l = 0;
        int r = 0;
        int totProf = 0;
        for(int i = 0; i < revPoint.size(); ++i){
          r = revPoint[i];
          totProf += maxProfit(prices, l, r);
          l = r + 1;
        }
        return totProf;
    }
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
