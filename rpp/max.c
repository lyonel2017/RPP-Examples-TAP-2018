/* run.config
   OPT: -rpp
*/

/*@ requires \valid(t+(0..n));
  @ requires n >= 1;
  @ requires \forall integer k; 0 <= k < n ==> 0 <= t[k];
  @ requires \separated(t+(0..n));
  @ assigns \result \from t[0..n];
  @ ensures \forall integer k; 0 <= k < n ==> \result >= t[k];
  @ ensures \exists integer k; 0 <= k < n && \result == t[k];
  @ relational \forall int *t1,*t2,*tn,*t;
      (tn[0] == \callpure(0,f,t1,2) &&
      tn[1] == \callpure(0,f,t2,2) &&
      t[0] == t1[0] &&
      t[1] == t1[1] &&
      t[2] == t2[0] &&
      t[3] == t2[1]) ==>
      \callpure(0,f,tn,2) == \callpure(0,f,t,4);
*/
int f(int t[], int n){
  int max = t[0];
  int i = 0;
  /*@ loop assigns i,max;
    @ loop invariant 0 <= i <= n;
    @ loop invariant \forall integer k; 0 <= k < i ==> max >= t[k];
    @ loop invariant \exists integer k; 0 <= k < n && max == t[k];
    @ loop variant n-i;
  */
  while(i < n){
    if(t[i] > max){
      max = t[i];
    }
    i++;
  }
 return max;
}
