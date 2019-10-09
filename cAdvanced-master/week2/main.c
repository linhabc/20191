#include <stdio.h>
#include <stdlib.h>
#include "Jval.h"

int main(){

  uJval a;

  a = new_Jval_c("linh");

  printf("a.i: %s", a.c);
  return 0;
}




  
