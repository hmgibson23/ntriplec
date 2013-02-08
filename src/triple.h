#include <string.h>
#include <stdio.h>


typedef struct {
	char* name; /*the name of the predicate*/
	node* object /*the object the predicate belongs to*/
} predicate;

typedef struct {
	char* name; /*name of object or sublect */
	predicate* pred; /*the predicate.*/

} node;


typedef struct {
	const char** existing; /*array of existing predicates*/
	unsigned int length;
} existing_predicates;

/*functions mapping nodes to predicates etc.*/

/*check for the existence of a predicate so as to have no dupliate mappings*/
int predicate_exists(predicate*, existing_predicates);