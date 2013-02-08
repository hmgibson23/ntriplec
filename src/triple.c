#include <string.h>
#include "triple.h"


int predicate_exists(predicate* pred, existing_predicates* ep) {
	//checks an array of string to determine if a predicate exists or not
	char *name = pred->name;
	unsigned int length = ep->length;
	unsigned short i = 0;
	for(i = 0; i < length; ++i) {
		if(!strcmp(name, ep->existing[i]))
		{
			return 1;
		}
	}

	return 0;
}