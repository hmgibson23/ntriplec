#include "set.h"
#include <assert.h>


int main() {

	Set* s = create_set();
	predicate pred = malloc(sizeof(predicate));
	pred = "This";
	insert_predicate(s, pred);
	predicate pred1 = malloc(sizeof(predicate));
	pred1 = "This";
	//assert(insert_predicate(s, pred));
	//printf("Should have failed");

	predicate pred2 = malloc(sizeof(predicate));
	pred2 = "Tasdashis";

	insert_predicate(s, pred2);

	
	assert(predicate_exists(s, pred));

	remove_predicate(s, pred);
	predicate pred3 = malloc(sizeof(predicate));
    pred3 = "poopoo";
	insert_predicate(s, pred3);
	insert_predicate(s, pred);
	print_set(s);
	assert(predicate_exists(s, pred));
	

	return 0;
}
