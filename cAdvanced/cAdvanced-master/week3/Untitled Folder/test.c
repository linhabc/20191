#include <stdio.h>

typedef struct{
  char key[50];
  int value;
}phoneEntry_t;

int main(){
  phoneEntry_t book[10];

  FILE*fin = fopen("phone.txt", "r");
  
  for(int i=0; i<10; i++){
    fscanf(fin, " %d", &book[i].value);
    fgets(book[i].key, 23, fin);
    printf("%14d %19s\n", book[i].value, book[i].key);
  }

  fclose(fin);

  return 0;
}
