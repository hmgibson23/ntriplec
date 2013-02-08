#include "triple.h"
#include <assert.h>


int main() {

	Set* s = create_set();
	predicate* pred = malloc(sizeof(predicate));
	pred->name = "This";
	//insert_predicate(s, pred);
	//predicate* pred1 = malloc(sizeof(predicate));
	//pred1->name = "This";
	//assert(insert_predicate(s, pred));
	printf("Should have failed");

	predicate* pred2 = malloc(sizeof(predicate));
	pred2->name = "Tasdashis";
	//insert_predicate(s, pred2);


	//remove_predicate(s, pred);
	assert(predicate_exists(s, pred));

	return 0;
}