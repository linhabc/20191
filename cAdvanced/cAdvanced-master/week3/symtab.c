#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 15
#define INCREMENTAL_SIZE 10

SymbolTable createSymbolTable(Entry (*makeNode)(void*, void*), int (*compare)(void*, void*)){
  SymbolTable pb;
  pb.entries = (Entry*)malloc(INITIAL_SIZE*sizeof(Entry));
  pb.total = 0;
  pb.size = INITIAL_SIZE;
  pb.makeNode = makeNode;
  pb.compare = compare;
  return pb;
}

// SymbolTable createPhoneBook(){
//   SymbolTable pb;
//   pb.entries = (Entry*)malloc(INITIAL_SIZE*sizeof(Entry));
//   pb.total = 0;
//   pb.size = INITIAL_SIZE;

//   return pb;
// };

void dropSymbolTable(SymbolTable* pb){
  for(int i=0; i<pb->total; i++){
    free((pb->entries[i]).key);
    free((pb->entries[i]).value);
  }
  free(pb->entries);
}

// void addEntry(void* key, void* value, SymbolTable* tb){
//   Entry *e = getEntry(key, tb);
//   Entry *new_entries;

//   if(e==NULL){
//     if(tb->total >= tb->size){
//       new_entries = (Entry*)malloc((tb->size+INCREMENTAL_SIZE)*sizeof(Entry));
//       memcpy(new_entries, tb->entries, tb->total*sizeof(Entry));
//       tb->entries = new_entries;
//       tb->size += INCREMENTAL_SIZE;
//     }
//     tb->entries[tb->total] = tb->makeNode(key,value);
//     tb->total++;
//   } else {
//     e->value = value;
//   }
// }

void addEntry(void* key, void* value, SymbolTable* tb){
  Entry *e = getEntry(key, tb);
  Entry *new_entries;
  Entry *new_entry = (Entry*)malloc(sizeof(Entry));
  new_entry->key = key;
  new_entry->value = value;

  if(e==NULL){
    if(tb->total >= tb->size){
      new_entries = (Entry*)malloc((tb->size+INCREMENTAL_SIZE)*sizeof(Entry));
      memcpy(new_entries, tb->entries, tb->total*sizeof(Entry));
      tb->entries = new_entries;
      tb->size += INCREMENTAL_SIZE;
    }
    tb->entries[tb->total] = *new_entry;
    tb->total++;
  } else {
    e->value = value;
  }
}

Entry* getEntry(void* name, SymbolTable* book){
  char* name_c = (char*)name;
  int i;
  for(i=0; i<book->total; i++)
    if(strcmp(name_c, book->entries[i].value)==0)
      break;

  if(i<book->total)
    return &book->entries[i];
  else return NULL;
}




// int compare(void* key1, void* key2){
//   return strcmp(((char*)key1),((char*)key2));
// }



//
