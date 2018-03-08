/* run.config
   OPT: -rpp
*/

/*
 * Based on http://stackoverflow.com/questions/30458633/why-does-my-compare-methd-throw-illegalargumentexception-sometimes
 *
 */

struct FileItem{
  int FileName;
  int toInt;
};

/*@ assigns \result \from o1,o2;
  @ relational \forall struct FileItem x1,x2; \callpure(compare,x1,x2) == -(\callpure(compare,x2,x1));
  @ relational \forall struct FileItem x1,x2,x3; (\callpure(compare,x1,x2) > 0 && \callpure(compare,x2,x3) > 0) ==> \callpure(compare,x1,x3) > 0;
  @ relational \forall struct FileItem x1,x2,x3; \callpure(compare,x1,x2) == 0 ==> (\callpure(compare,x1,x3) == \callpure(compare,x2,x3));
*/
int compare (struct FileItem o1, struct FileItem o2) {
  int result = 0;
  if ((o1.toInt != 0) && (o2.toInt != 0)) {

    int n1 = o1.FileName;
    int n2 = o2.FileName;

    if ((n1 != 0) && (n2 != 0))
      result = n1 - n2; //n1.compareTo(n2);
  }

  return result;
}
