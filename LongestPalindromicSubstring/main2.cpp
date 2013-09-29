/*
 * =====================================================================================
 *
 *       Filename:  main2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2013 12:08:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

// pseudo code


N = strlen(S)-1; 
FOR (i, 0, N) S2[i<<1] = S2[(i<<1)|1] = S[i];
N <<= 1;
 
for (i = j = 0; i < N; i += k) {
  for (; i-j >= 0 && i+j+1 < N && S2[i-j] == S2[i+j+1]; j++);
  R[i] = j;
  for (k = 1; k <= j && i >= k && R[i-k] != R[i]-k; k++) {
    R[i+k] = min(R[i-k], R[i]-k);
    Res += (R[i+k]+1)>>1;
  }
  j = max(0, R[i]-k);
  Res += (R[i]+1)>>1;
}
 
printf("%lld\n", Res);
