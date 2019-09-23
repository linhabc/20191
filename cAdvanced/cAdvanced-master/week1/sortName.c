#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct book{
  char name[MAX];
  int phone;
  char email[MAX];
};

typedef struct book keyType;

int compareName(char name1[], char name2[]);
int name_compare(void const* x, void const *y);


int main(){

  keyType book1[10];
  FILE*fin = fopen("phone.txt", "r");
  
  for(int i=0;i<10;i++){
    fscanf(fin, " %d", &book1[i].phone);
    fgets(book1[i].name, 23, fin);
    fscanf(fin, " %s", book1[i].email);
  }

  printf("Before sort.\n");
  for(int i=0; i<10; i++){
    printf("%-20s%23s%10d\n", book1[i].email, book1[i].name, book1[i].phone);
  }
  
  qsort(book1, 10, sizeof(keyType), name_compare);

  printf("After sort.\n");
  for(int i=0; i<10; i++){
    printf("%-20s%23s%10d\n", book1[i].email, book1[i].name, book1[i].phone);
  }

  return 0;
}


int compareName(char name1[], char name2[]){
  int l1 = strlen(name1);
  int l2 = strlen(name2);
  int count1=0, count2=0;
  int check=0;
  int i,j=0;
  //count numbers of space->number of words
  for(i=0; i<l1; i++){
    if(name1[i] == ' '){
      count1++;
    }
  }
  for(i=0; i<l2; i++){
    if(name2[i] == ' '){
      count2++;
    }
  }
  //reverse name by words
  char r1[MAX];
  char r2[MAX];
  
  while(count1 >= 0){
    for(i=0; i<l1; i++){
      if(name1[i] == ' '){
        check++;
        i++;
      }
      if(check == count1){
	while(name1[i] != ' ' && name1[i] != '\0'){
	  //printf("%c \n", name[i]);
	  r1[j] = name1[i];
	  j++;
	  i++;
	}
	count1--;
	check = 0;
	//printf("%d \n", count);
	break;
      }
    }
  }
  check = 0,j=0;
  
  while(count2 >= 0){
    for(i=0; i<l2; i++){
      if(name2[i] == ' '){
        check++;
        i++;
      }
      if(check == count2){
	while(name2[i] != ' ' && name2[i] != '\0'){
	  //printf("%c \n", name[i]);
	  r2[j] = name2[i];
	  j++;
	  i++;
	}
	count2--;
	check = 0;
	//printf("%d \n", count);
	break;
      }
    }
  }
  return strcmp(r1, r2);
}

int name_compare(void const* x, void const *y){
  keyType* n1 = ((keyType*)x);
  keyType* n2 = ((keyType*)y);

  return strcmp(n1->name,n2->name);
}
