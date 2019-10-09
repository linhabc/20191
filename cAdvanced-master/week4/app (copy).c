#include <stdio.h>
#include <stdio_ext.h> // __fpurge(stdio);
#include <string.h>
#include "jrb.h"
#include "jval.h"
#define strcut_newline(str) ((str)[strlen(str) - 1] == '\n')? (str)[strlen(str) - 1] = '\0':0;

#define MAX 50

void insertNode(JRB tree, char *key, Jval val);
void searchPhone(JRB tree, char *key);

int main(){
  char name[MAX];
  int number;
  int choice;
  JRB tmp;
  JRB book = make_jrb();
  
  do{
    printf("1. Add phone\n");
    printf("2. Search phonenumber\n");
    printf("3. Exit\n");

    do{
      printf("Enter(1-3): ");
      scanf(" %d", &choice);
    }while(choice>3 || choice<1);

    switch (choice) {
      case 1:
        __fpurge(stdin);
        printf("Enter name: ");
        fgets(name, MAX-1, stdin);
	strcut_newline(name);
        printf("Enter phoneNumber: ");
        scanf(" %d", &number);

        insertNode(book, name, new_jval_i(number));

	jrb_traverse(tmp, book){
	  printf("\n%s: %d\n\n", jval_s(tmp->key), jval_i(tmp->val));
	}
        break;

      case 2:
        //__fpurge(stdin);
        //printf("Enter name to search: ");
        //fgets(name, MAX-1, stdin);
	//strcut_newline(name);
	printf("Enter phoneNumber to search: ");
        scanf(" %d", &number);

        searchPhone(book, number);

        break;
    }

  }while (choice!=3);


  
  jrb_free_tree(book);
  return 0;
}

void insertNode(JRB tree, char *key, Jval val){
  JRB fnode = jrb_find_str(tree, key);

  if(fnode == NULL)
    jrb_insert_str(tree, key, val);
  else
    fnode->val = val;
}

void searchPhone(JRB tree, char *key){
  JRB fnode = jrb_find_str(tree, key);

  if(fnode == NULL)
    printf("Entry doesn't exist\n");
  else
    printf("\n%s: %d\n\n", jval_s(fnode->key), jval_i(fnode->val));
}


















//end
