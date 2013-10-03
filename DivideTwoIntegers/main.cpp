/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Divide Two Integers
 *
 *        Version:  1.0
 *        Created:  10/03/2013 09:08:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        long long ldividend = (long long) dividend, ldivisor = (long long) divisor;
        bool isNeg1 = ldividend < 0;
        bool isNeg2 = ldivisor < 0;
        ldividend = ldividend > 0 ? ldividend : -ldividend;
        ldivisor = ldivisor > 0 ? ldivisor : -ldivisor;
        if(ldividend < ldivisor) return 0;
        if(ldividend == ldivisor){
          if(isNeg1 != isNeg2) return -1;
          else return 1;
        }
        if(ldivisor == 1){
          return ldividend;
        }

        unsigned long long tmpldividend = (unsigned long long)ldividend, tmpldivisor = (unsigned long long)ldivisor;
        int bitCnt = 0;
        while(tmpldivisor <= tmpldividend){
          tmpldivisor <<= 1;
          ++bitCnt;
        }
        int res = 0;
        while(bitCnt > 0){
         if(ldividend >= (ldivisor << (bitCnt - 1))){
            res |= (1 << (bitCnt - 1));
            ldividend -= (ldivisor << (bitCnt - 1));
          }
          --bitCnt;
        }
        if(isNeg1 != isNeg2) return -res;
        else return res;
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
  Solution s;
/*  cout << s.divide(1,3) << endl;
  cout << s.divide(3,3) << endl;
  cout << s.divide(5,3) << endl;
  cout << s.divide(10,3) << endl;
  cout << s.divide(21,3) << endl;
  cout << s.divide(22,3) << endl;
  cout << s.divide(10,5) << endl;
  cout << s.divide(-10,5) << endl;
  cout << s.divide(-10,3) << endl;
  cout << s.divide(-1,3) << endl;
  cout << s.divide(-2147483648, 1) << endl;
*/
  cout << s.divide(2147483647, 3) << endl;
  cout << s.divide(15,3) << endl;
  cout << s.divide(2147483647, 2) << endl;
  cout << s.divide(2147483647, 1) << endl;
  cout << s.divide(2100000000, 3) << endl;
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
