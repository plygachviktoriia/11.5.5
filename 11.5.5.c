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

int main(void) 
{
 CTWL *list = ctwl_create_random(15);
 unsigned int size = ctwl_get_size(list);
 
 printf("Pocet uzlov: %u\n", size);

 ctwl_print(list);
 ctwl_destroy(list);
     
    return 0;
}
