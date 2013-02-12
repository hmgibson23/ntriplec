#include "triple.h"

Triple* create_triple(const char* subject, predicate* pred, const char* object) {
	Triple* trip = malloc(sizeof(Triple));
	trip->subject = subject;
	trip->pred = pred;

	Triple* obj = malloc(sizeof(Triple)); //create another possible triple for the object.
	obj->value = object;
	obj->pred = NULL;
	obj->object = NULL;

	trip->object = obj;


	return trip;
}