#include <stdio.h>
#include <stdlib.h>

typedef struct TWN{        //definicia obojsmernoho uzlu
float data;
struct TWN *prev;
struct TWN *next;
}TWN;

typedef struct{           //reprezentacia celeho zoznamu
TWN *cur;                 //kurzorovy uzol
}CTWL;

unsigned int ctwl_get_size(CTWL *list)
{
if (list == NULL || list->cur == NULL)
 {
  return 0;
 } 

unsigned int pocet = 1;
TWN *n = list->cur->next;

while (n != list->cur->next)
 {
  pocet++;
  n = n->next;
 }

return pocet;
}