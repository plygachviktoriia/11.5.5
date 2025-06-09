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
void ctwl_destroy(CTWL* list);
void ctwl_print(CTWL *list);
TWN *ctwl_insert_right(CTWL* list, float val);
CTWL *ctwl_create_empty(void);


unsigned int ctwl_get_size(CTWL *list)
{
 if (list == NULL || list->cur == NULL)
 {
  return 0;
 } 

 unsigned int pocet = 1;
 TWN *zaciatok = list->cur;
 TWN *n = zaciatok->next;

 while (n != zaciatok)
 {
  pocet++;
  n = n->next;
 }

return pocet;
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


CTWL *ctwl_create_empty(void)
{
 CTWL *list = malloc(sizeof(CTWL));
 if (list != NULL) 
 {
  list->cur = NULL;
 }
return list;
}


TWN *ctwl_insert_right(CTWL* list, float val)
{
 TWN *zaciatok = list->cur;
 TWN *vuzol = (TWN *)malloc(sizeof(TWN));
 if (vuzol == NULL)
 {
  return NULL;
 }

 vuzol->data = val;

 if (zaciatok == NULL)
 {
  vuzol->next = vuzol;
  vuzol->prev = vuzol;
  zaciatok = vuzol;
 }
 else 
 {
  TWN *right = zaciatok->next;
  vuzol->next = right;
  vuzol->prev = zaciatok;
  zaciatok->next = vuzol;
  right->prev = vuzol;
 }

return vuzol; 
}


int main(void) 
{
 CTWL *list = ctwl_create_random(15);
 unsigned int size = ctwl_get_size(list);
 
 printf("Pocet uzlov: %u\n", size);

 ctwl_print(list);
 ctwl_destroy(list);
     
    return 0;
}


void ctwl_print(CTWL *list)
{
 if (list == NULL || list->cur == NULL)
 {
  printf("List je prazdny\n");
  return;
 }

 TWN *start = zaciatok;
 TWN *uzol  = start;

 do 
 {
 printf("%.2f ", uzol->data);
 uzol = uzol->next;
 }
 while (uzol != start);
 printf("\n");
}


void ctwl_destroy(CTWL* list)
{
if (list == NULL || list->cur == NULL)
 {
  return;
 } 
 
}
