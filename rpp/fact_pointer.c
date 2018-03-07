/* run.config
   OPT: -rpp
*/

int r;

/*@ requires x >= 0;
  @ assigns r \from r,x;
  @ relational \forall int x1; \callset(\call(fact,x1,id1)) ==> x1 <= 1 ==> \at(r,Post_id1) == 1;
  @ relational \forall int x1; \callset(\call(1,fact,x1,id2), \call(1,fact,x1-1,id3)) ==> x1 > 1 ==> \at(r,Post_id2) == x1 * \at(r,Post_id3);
*/
void fact(int x) {
  if(x <= 1){
    r = 1;
    return;
  }
  else{
    fact(x-1);
    r = r * x;
    return;
 }
}
