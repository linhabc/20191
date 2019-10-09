typedef union Jval{
  int i;
  float f;
  double d;
  char* c;
} uJval;

uJval new_Jval_i(int i){
  uJval j;
  j.i = i;
  return j;
}

uJval new_Jval_f(float f){
  uJval j;
  j.f = f;
  return j;
}

uJval new_Jval_d(double d){
  uJval j;
  j.d = d;
  return j;
}

uJval new_Jval_c(char* c){
  uJval j;
  j.c = c;
  return j;
}

uJval* creat_array(int n){
  uJval* j = (uJval*)malloc(sizeof(uJval)*n);
  for(int i; i<n; i++)
    j[i] = new_Jval_i(rand()%100);
  return j;
}

int compare_i(void const* a, void const* b){
  uJval* j1 = (uJval*)a;
  uJval* j2 = (uJval*)b;

  if(j1->i == j2->i) return 0;
  return j1->i > j2->i ? 1 : -1;
}

void sort_gen(uJval a[], int size, int(*compare_i)(uJval*,uJval*)){
  qsort(a, size, sizeof(uJval), compare_i);
}

int search_gen(uJval a[], int l, int r, uJval item, int(*compare_i)(uJval*,uJval*)){
  if(r<l) return -1;
  i = (l+r)/2;
  int res = compare_i(item, a[i]);
  if(res == 0)
    return i;
  else if(res < 0)
    return search_gen(a, l, i-1, item, compare_i);
}

void sort_i(uJval a[], int size){
  return sort_gen(a, size, compare_i);
}

int search_i(uJval a[], int l, int r, int x){
  return search_gen(a, l, r, x, compare_i);
}

