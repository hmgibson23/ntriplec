#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	const char* name; /*the name of the predicate*/
	struct node* object; /*the object the predicate belongs to*/
} predicate;

typedef struct {
	char* name; /*name of object or sublect */
	struct predicate* pred; /*the predicate.*/
} node;


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
int insert_predicate(Set*, predicate*);
int predicate_exists(Set*, predicate*);
int remove_predicate(Set*, predicate*);
