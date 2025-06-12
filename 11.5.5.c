#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct TWN{        //definicia obojsmernoho uzlu
	float data;            //hodnota ktoru chrani uzol
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


CTWL *ctwl_create_empty(void)                //inicializacis prazneho zoznamu
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
	CTWL *list = ctwl_create_empty();

	for (unsigned int i = 0; i < size; i++)
	{
   	int cely = rand() % 101 - 50;
   	int drob = rand() % 100;
   	float cisla = cely + drob / 100.0f;
   	ctwl_insert_right(list, cisla);                 //vstavka uzla sprava v zoznam s hodnotou cisla
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

 	TWN *zaciatok = list->cur;
 	TWN *uzol  = zaciatok;

 	do 
 	{
 	printf("%.2f ", uzol->data);                      //zvernenia na pole data na ktory ukazuje uzol
 	uzol = uzol->next;         
 	}
 	while (uzol != zaciatok);
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
 	TWN *vuzol = malloc(sizeof(TWN));

 	if (vuzol == NULL)
 	{
  	return NULL;
 	}

 	vuzol->data = val;

 	if (list->cur == NULL)
 	{
  	vuzol->next = vuzol->prev = vuzol;
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
 
 	TWN *zaciatok = list->cur;
 	TWN *uzol = zaciatok->next;

 	while (uzol != zaciatok) 
 	{
  	TWN *temp = uzol;
  	uzol = uzol->next;
  	free(temp);
 	}

 	free(zaciatok);
 	free(list);
}
