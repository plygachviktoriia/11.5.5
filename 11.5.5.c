#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct TWN{        //definicia obojsmernoho uzlu
float data;
struct TWN *prev;
struct TWN *next;
}TWN;

typedef struct{           //reprezentacia celeho zoznamu
TWN *cur;                 //kurzorovy uzol
}CTWL;

CTWL *ctwl_create_random(unsigned int size); 
void ctwl_destroy(CTWL *list);
void ctwl_print(CTWL *list);
TWN *ctwl_insert_right(CTWL *list, float val);
CTWL *ctwl_create_empty(void);


CTWL *ctwl_create_empty(void)
{
 CTWL *list = malloc(sizeof(CTWL));
 if (list != NULL) 
 {
  list->cur = NULL;
 }
return list;
}


CTWL *ctwl_create_random(unsigned int size)
{
 srand(time(NULL));
 CTWL *list = ctwl_create_empty();
 for (unsigned int i = 0; i < size; i++)
 {
   int cely = rand() % 101 - 50;
   int drob = rand() % 100;
   float cisla = cely + drob / 100.0f;
   ctwl_insert_right(list, cisla);
 }
 return list;
}


void ctwl_print(CTWL *list)
{
 if (list == NULL || list->cur == NULL)
 {
  printf("List je prazdny\n");
  return;
 }

 TWN *start = list->cur;
 TWN *uzol  = start;

 do 
 {
 printf("%.2f ", uzol->data);
 uzol = uzol->next;
 }
 while (uzol != start);
 printf("\n");
}


unsigned int ctwl_get_size(CTWL *list)
{
 if (list == NULL || list->cur == NULL)
 {
  return 0;
 } 

 unsigned int pocet = 1;
 TWN *n = list->cur->next;

 while (n != list->cur)
 {
  pocet++;
  n = n->next;
 }

return pocet;
}


TWN *ctwl_insert_right(CTWL* list, float val)
{
 TWN *vuzol = (TWN *)malloc(sizeof(TWN));
 if (vuzol == NULL)
 {
  return NULL;
 }

 vuzol->data = val;

 if (list->cur == NULL)
 {
  vuzol->next = vuzol;
  vuzol->prev = vuzol;
  list->cur = vuzol;
 }
 else 
 {
  TWN *right = list->cur->next;
  vuzol->next = right;
  vuzol->prev = list->cur;
  list->cur->next = vuzol;
  right->prev = vuzol;
 }

return vuzol; 
}


int main(void) 
{
 srand(time(NULL));
 int velkost = rand() % 15;
 CTWL *list = ctwl_create_random(velkost);
 
 ctwl_print(list);

 unsigned int size = ctwl_get_size(list);
 printf("Pocet uzlov: %u\n", size);

 ctwl_destroy(list);
     
 return 0;
}


void ctwl_destroy(CTWL* list)
{
if (list == NULL || list->cur == NULL)
 {
  return;
 } 
 
 TWN *start = list->cur;
 TWN *uzol = start->next;

 while (uzol != start) 
 {
  TWN *temp = uzol;
  uzol = uzol->next;
  free(temp);
 }

 free(start);
 free(list);
}
