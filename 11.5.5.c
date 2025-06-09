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
TWN *n = list->cur->next;

while (n != list->cur)
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


int main(void) 
{
 CTWL *list = ctwl_create_random(15);
 unsigned int size = ctwl_get_size(list);
 
 printf("Pocet uzlov: %u\n", size);

 ctwl_print(list);
 ctwl_destroy(list);
     
    return 0;
}
