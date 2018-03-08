/* run.config
   OPT: -rpp
*/

/*
 * Based on http://stackoverflow.com/questions/19325256/java-lang-illegalargumentexception-comparison-method-violates-its-general-contr
 *
 */

struct Node{
  int ID;
};

struct hack{
  int t[10];
};

/*@ requires 0 <= id < 10;
  @ assigns \result \from id,h.t[id];
  @ ensures h.t[id] != -1 ==> \result == 1;
  @ ensures h.t[id] == -1 ==> \result == 0;*/
int containsKey(int id,struct hack h){
  if (h.t[id] != -1) return 1;
  else return  0;
}

/*@ requires 0 <= id < 10;
  @ assigns \result \from id,h.t[id];
  @ ensures \result == h.t[id];*/
int get(int id, struct hack h){
  return h.t[id];
}

/*@ requires 0 <= o1.ID < 10;
  @ assigns \result \from o1;
  @ ensures \result == o1.ID;
  @ ensures 0 <= \result < 10;*/
int getID(struct Node o1){
  return o1.ID;
}

/*@ requires 0 <= o1.ID < 10;
  @ requires 0 <= o2.ID < 10;
  @ assigns \result \from o1,o2,h;
  @ relational \forall struct Node x1,x2,struct hack p; \callpure(compare,x1,x2,p) == -(\callpure(compare,x2,x1,p));
  @ relational \forall struct Node x1,x2,x3,struct hack p; (\callpure(compare,x1,x2,p) > 0 && \callpure(compare,x2,x3,p) > 0) ==> \callpure(compare,x1,x3,p) > 0;
  @ relational \forall struct Node x1,x2,x3,struct hack p; \callpure(compare,x1,x2,p) == 0 ==> (\callpure(compare,x1,x3,p) == \callpure(compare,x2,x3,p));*/
int compare(struct Node o1, struct Node o2,struct hack h){
  if(containsKey(getID(o1),h) && containsKey(getID(o2),h)){
    int order1 = get(getID(o1),h);
    int order2 = get(getID(o2),h);

    if(order1 < order2)
      return -1;
    else if(order1 > order2)
      return 1;
    else
      return 0;
  }
  return 0;
}
