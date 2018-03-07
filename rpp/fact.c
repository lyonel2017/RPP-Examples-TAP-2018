/* run.config
   OPT: -rpp
*/

/*@ requires x >= 0;
  @ assigns \result \from x;
  @ relational \forall int x1; x1 <= 1 ==> \callpure(1,fact,x1) == 1;
  @ relational \forall int x1; x1 > 1 ==> \callpure(1,fact,x1+1) == \callpure(0,fact,x1)*(x1+1);
  @ relational \forall int x1; \callpure(2,fact,x1+1) == 1;
*/
int fact(int x) {
  if(x <= 1){
      return 1;
    }
else{
  return x*fact(x-1);
 }
}
