#include "phoneEntry.h"
#include "symtab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

SymbolTable createPhoneBook();
void findPhone(SymbolTable* pb);
void readTxt(phoneEntry_t* book);
int compare(void* key1, void* key2);
Entry makeNode(void *value, void* key);

int main(){
  int n;
  SymbolTable pb = createPhoneBook();
  phoneEntry_t *book;
  printf("make tb done\n");
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

SymbolTable createPhoneBook(){
  return createSymbolTable(makeNode, compare);
};

void readTxt(phoneEntry_t* book){
  FILE*fin = fopen("phone.txt", "r");

  if( fin == NULL) 
    printf("IO error occur!");
  
  book = (phoneEntry_t*)malloc(10*sizeof(phoneEntry_t));

  for(int i=0; i<10; i++){
    (book+i)->value = (int*)malloc(sizeof(int));
    (book+i)->key = (char*)malloc(sizeof(char)*23);

    fscanf(fin, "%d", (int*)(book+i)->value);

    fgets((char*)(book+i)->key, 23, fin);

    printf("_%d_ _%s_\n", *(int*)book[i].value, (char*)book[i].key);
  }

  fclose(fin);
}

void findPhone(SymbolTable* pb){
  char name[23];
  printf("Enter name: ");
  fgets(name, 23, stdin);
  phoneEntry_t* finded = getEntry(name, pb);
  if(finded==NULL)
    printf("Not found\n");
  else
    printf("%14d %19s\n", *(int*)finded->value, (char*)finded->key);
}

int compare(void* key1, void* key2){
  return strcmp(((char*)key1),((char*)key2));
}

Entry makeNode(void *value, void* key){
  Entry newEntry;
  newEntry.key = (char*)key;
  newEntry.value = (int*)value;
  return newEntry;
}















//
