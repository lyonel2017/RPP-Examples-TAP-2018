/* run.config
   OPT: -rpp
*/

/*
 * Based on http://stackoverflow.xluat.com/questions/31235938/java-order-by-priority-list
 *
 */

struct MyClass{
  int Name;
};

struct hack{
  int t[3];
};

/*@ assigns \result \from x,y;
  @ ensures x < y ==> \result == -1;
  @ ensures x > y ==> \result == 1;
  @ ensures x == y ==> \result == 0;
*/
int IntCompare(int x, int y){
  if (x < y){
    return -1;
  }
  if(x > y){
    return 1;
  }

  return 0;
}

/*@ assigns \result \from o1,o2,h;
  @ relational \forall struct MyClass x1,x2,struct hack p; \callpure(compare,x1,x2,p) == -(\callpure(compare,x2,x1,p));
  @ relational \forall struct MyClass x1,x2,x3,struct hack p; (\callpure(compare,x1,x2,p) > 0 && \callpure(compare,x2,x3,p) > 0) ==> \callpure(compare,x1,x3,p) > 0;
  @ relational \forall struct MyClass x1,x2,x3,struct hack p; \callpure(compare,x1,x2,p) == 0 ==> (\callpure(compare,x1,x3,p) == \callpure(compare,x2,x3,p));*/
int compare(struct MyClass o1, struct MyClass o2,struct hack h){
  int x = o1.Name;
  int y = o2.Name;
  int i = 0;

  /*@ loop invariant 0 ≤ i ≤ 3;
      loop invariant ∀ ℤ k; 0 ≤ k < i ⇒ h.t[k] ≢ x ∧ h.t[k] ≢ y;
      loop assigns i;
  */
  while(i < 3){
    if(h.t[i] == x) {
      return 1;
    }
    if(h.t[i] == y) {
      return -1;
    }
    i++;
  }
  return IntCompare(x,y);
}
