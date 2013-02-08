#include <string.h>
#include "triple.h"


int predicate_exists(predicate* pred, existing_predicates) {
	//checks an array of string to determine if a predicate exists or not
	char *name = pred->name;
	unsigned int *length = existing_predicates->length;
	for(unsigned short i = 0; i < *length; ++i) {
		if(!strcmp(*name, existing_predicates->existing[i]))
		{
			return 1;
		}
	}

	return 0;
}