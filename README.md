# RPP-Examples-TAP-2018
Examples for RPP tool paper for TAP 2018

- In the `stackoverflow/` folder are located the set of comparator examples taken 
  from the PLDI 2016 paper *Cartesian Hoare Logic for Verifying k-safety Properties*
  by **Marcelo Sousa** and **Isil Dillig**
 
- In the `rpp/` folder are located the subset of example for testing the RPP tool.
  Notice that some of these examples have incorrect specification (but are also supported by RPP).

- In the `stady-bechmark/` folder are located the subset of example from the stackoverflow benchmark what
  contains unvalided properties. StaDy and E-ASCL can be run on these examples unsing the script `script.sh`.
  First argument is the `*.c` file, second argument is the relational property of interest (specified by
  the corresponding wrapper function) and last argument specifiy if E-ASCL is run on generated test cases
  (`0` no, `1` yes). E-ASCL can take time, since it will be run on all genertated test cases for one property.
  Example of use in the `stady-benchmark/` folder without E-ACSL:
      
        sh script.sh Contact-flase.c relational_wrapper_2 0
   
  Example of use in the `stady-benchmark/` folder with E-ACSL:
         
        sh script.sh Contact-flase.c relational_wrapper_2 1
   	    
  To avoid pollution of the console during E-ACSL execution, you can grep interesting information:
  
        sh script.sh Contact-flase.c relational_wrapper_2 1 2>&1 | grep -B1 "failed"
  
