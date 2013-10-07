/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
<<<<<<< HEAD
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 07时23分51秒
=======
 *    Description:  Best Time to Buy and Sell Stock III
 *
 *        Version:  1.0
 *        Created:  10/07/2013 01:08:53 PM
>>>>>>> d76088d662aec4ef1c8667afd00e10a76aa85639
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
        if(prices.size() <= 1)
            return 0;
        vector<int> curMaxProfFront = vector<int>(prices.size()); // curMaxProfFront[idx] means：if only one transaction is allowed, the maximum profit from 0th to idx-th day
        vector<int> curMaxProfBack = vector<int>(prices.size()); // curMaxProfBack[idx] means：if only one transaction is allowed, the maximum profit from idx-th to (N - 1)-th day
        // init
        curMaxProfFront[0] = 0;
        curMaxProfBack[curMaxProfBack.size() - 1] = 0;
        
        int min = prices[0];
        int maxProFront = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] - min > maxProFront){
                maxProFront = prices[i] - min;
            }
            else if(prices[i] < min){
                min = prices[i];
            }
            curMaxProfFront[i] = maxProFront;
        }
        
        int maxProBack = 0;
        int max = prices[prices.size() - 1];
        for(int i = prices.size() - 2; i >= 0; --i){
            if(max - prices[i] > maxProBack){
                maxProBack = max - prices[i];
            }
            else if(prices[i] > max){
                max = prices[i];
            }
            curMaxProfBack[i] = maxProBack;
        }
        
        int maxPro = 0;
        for(int i = 1; i < prices.size() - 1; ++i){
            if(curMaxProfFront[i] + curMaxProfBack[i + 1] > maxPro){
                maxPro = curMaxProfFront[i] + curMaxProfBack[i + 1];
            }
        }
        
        return maxPro > maxProFront ? maxPro : maxProFront;// maxProFront is the max profit if only one transaction is allowed
    }
};
