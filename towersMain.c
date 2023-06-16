#include <stdlib.h>

#include "towers.h"

#include <stdio.h>



int main(int argc, char ** argv) {
  int n = 3;
  int from = 1;
  int dest = 2;





  // ZERO NUMBER OF ARGUMENTS GIVEN:

  if (argc == 1) { // no arguments given	 
    towers(n, from, dest);
    exit(0);
  }
  // if no arguments are given, move 3 disks from Tower 1 to Tower 2.







  // ONE NUMBER OF ARGUMENTS GIVEN:

  if (argc == 2) { // file name plus 1 argument (# of disks)
    n = atoi(argv[1]); // use the first argument as the value for n
    if (n <1) {
      fprintf(stderr, "ERROR: can not have %d number of disks, Please choose an integer above 0",n);
      exit(1); // just so that the user cant input 0 number of disks since that wouldnt make 		sense anyways

    } else {
      towers(n, from, dest); //from=1, and dest=2, defult parameters
      exit(0);
    }

  }







  // TWO NUMBER OF ARGUMENTS GIVEN:

  if (argc == 3) { // file name and 2 arguments, which is not allowed
    fprintf(stderr, "ERROR: you gave 2 arguments, please give either 0, 1 or 3 only");
    exit(1); // a way to test if the code goes wrong
  }









  // THREE NUMBER OF ARGUMENTS GIVEN:

  if (argc == 4) { // 3 arguments (# of disks, Start, End)	  

    n = atoi(argv[1]);
    from = atoi(argv[2]);
    dest = atoi(argv[3]);
    if (n < 1) {
      fprintf(stderr, "ERROR: can not have %d number of disks, Please choose an integer above 0",n);
      exit(1);
    } else {
      if (from == dest) {
        fprintf(stderr, "ERROR: From can not be the same number as destination");
        exit(1);
      }

      if (from > 3) {
        fprintf(stderr, "ERROR: from can not be above 3");

        exit(1);
      }

      if (dest > 3) {
        fprintf(stderr, "ERROR: destination can not be above 3");

        exit(1);
      }

      if (from < 1) {
        fprintf(stderr, "ERROR: From can not be below 1");

        exit(1);
      }
      if (dest < 1) {
        fprintf(stderr, "ERROR: Destination can not be below 1");

        exit(1);
      }

      towers(n, from, dest);
    }
  }









  // TOO MANY NUMBER OF ARGUMENTS GIVEN:

  else if (argc > 3) { // if more then 3 arguments are given
    int x = argc - 1; // not counting the first argument which is the file name
    int y = x - 3; // making max number of arguments 3

    fprintf(stderr, "ERROR: you gave %d arguments, remove %d of the arguments atleast to get proper output", x, y);

    // just for fun, could just make a simple statement saying "too many arguments for all values above 3"
    exit(1);
  }
}
