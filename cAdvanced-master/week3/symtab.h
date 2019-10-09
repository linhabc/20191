#ifndef __SYMTAB_H__
#define __SYMTAB_H__

typedef struct{
  void* key;
  void* value;
}Entry;

typedef struct{
  Entry* entries;
  int size, total;
  Entry (*makeNode)(void*, void*);
  int (*compare)(void*, void*);
}SymbolTable;

SymbolTable createSymbolTable(Entry (*makeNode)(void*, void*), int (*compare)(void*, void*));
void dropSymbolTable(SymbolTable* book);
void addEntry(void* key, void* value, SymbolTable* book);
Entry* getEntry(void* key, SymbolTable* book);




#endif













//
