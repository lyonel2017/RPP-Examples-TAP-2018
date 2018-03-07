/* run.config
   OPT: -rpp
*/

/*@ axiomatic Sum {
  @   // sum(t,i,j) denotes t[i]+...+t[j-1]
  @   logic integer sum{L}(int *t, integer i, integer j)
  @        reads i,j,t, t[..] ;
  @   axiom sum1{L} :
  @     \forall int *t, integer i, j; i >= j ==> sum(t,i,j) == 0;
  @   axiom sum2{L} :
  @     \forall int *t, integer i, j; i <= j ==>
  @       sum(t,i,j+1) == sum(t,i,j) + t[j];
  @ }
  @*/

/*@ lemma sum3{L} :
  @     \forall int *t, integer i, j, k;
  @       i <= j <= k ==>
  @         sum(t,i,k) == sum(t,i,j) + sum(t,j,k);
  @*/

/*@ lemma sum_footprint{L} :
  @     \forall int *t1,*t2, integer i, j;
  @       (\forall integer k; i<=k<j ==> t1[k] == t2[k]) ==>
  @       sum(t1,i,j) == sum(t2,i,j);
  @*/

/*@ requires n > 0;
  @ requires \valid(t+(0..n));
  @ assigns \result \from n,t[0..n];
  @ relational \forall int n, int *t; \callpure(f,n,t) == \callpure(0,f,n-1,t) + t[n-1];
*/
int f (int n, int t[]){

  int i = 0;
  int s = 0;

  /*@ loop invariant 0 <= i <= n && s == sum(t,0,i);
    @ loop assigns s,i;
    @ loop variant n-i;
  */
  for(i=0; i < n; i++){
    s = s + t[i];
  }
  return s;
}


/*@ requires n > 0;
  @ requires \valid(t+(0..n));
  @ assigns \result \from n,t[0..n];
  @ relational \forall int n, int *t; \callpure(g,n,t) == \callpure(0,g,n-1,t) + t[n-1];
*/
int g (int n, int t[]);


/*@ requires 10 > n > 0;
  @ requires \valid(t+(0..n));
  @ assigns \result \from n,t[0..n];
  @ relational \forall int *t; \callpure(k,t,t[9]) == t[10];
*/
int k (int t[],int n);

/*@ requires 10 > n > 0;
  @ requires \valid(t+(0..n));
  @ assigns \result \from n,t[0..n];
  @ relational \forall int *t;\callpure(p,t,t[9]) == t[10];
*/
int p (int t[], int n){
  return t[n];
}
