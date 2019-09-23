#include "phoneEntry.h"
#include "symtab.h"
#include <stdio.h>

void findPhone(SymbolTable* pb);
void readTxt(phoneEntry_t* book);

int main(){
  int n;
  SymbolTable pb = createPhoneBook();
  phoneEntry_t book[10];

  do{
    printf("MENU\n");
    printf("1.read txt file.\n");
    printf("2.search phone by name.\n");
    printf("3.exit.\n");
    do{
      printf("ENTER: ");
      scanf(" %d", &n);
    }while(n<1 || n>3);

    switch (n) {
      case 1:
        readTxt(book);
        pb.entries = book;
        break;
      case 2:
        findPhone(&pb);
    }

  }while(n!=3);

  dropSymbolTable(&pb);
  return 0;
}


void readTxt(phoneEntry_t* book){
  FILE*fin = fopen("phone.txt", "r");
  for(int i=0; i<10; i++){
    fscanf(fin, " %d", (int*)book[i].value);
    fgets((char*)book[i].key, 23, fin);
    printf("%14d %19s\n", *(int*)book[i].value, (char*)book[i].key);
  }

  fclose(fin);
}

void findPhone(SymbolTable* pb){
  char name[23];
  printf("Enter name: ");
  fgets(name, 23, stdin);
  phoneEntry_t* finded = getEntry(name, pb);
  if(finded==NULL)
    printf("Not found");
  else
    printf("%14d %19s\n", *(int*)finded->value, (char*)finded->key);
}

































//
