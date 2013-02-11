#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef char* predicate;


typedef struct _ListElem {
	const char* value;
	struct _ListElem* next;
} ListElem;

/*essentially a linked list but with set style operations enforced.*/
typedef struct {
	unsigned short length;
	ListElem* head;
	ListElem* tail;	
} Set;

/*functions mapping no
des to predicates etc.*/

Set* create_set();
void destroy_set(Set*);

/*Predicate insertion and deltion*/
int insert_predicate(Set*, predicate);
int predicate_exists(Set*, predicate);
int remove_predicate(Set*, predicate);
void print_set(Set*);
void print_list(ListElem*);
