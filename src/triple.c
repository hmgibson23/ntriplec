#include <string.h>
#include <assert.h>


#include "triple.h"


Set* create_set() {
	Set* set = malloc(sizeof(set));
	set->length = 0;
	set->head = NULL;
	set->tail = NULL;

	return set;
}

void destroy_set(Set* s) {
	ListElem* iter = s->head;
	while(iter->next != NULL) {
		ListElem* temp = iter;
		iter = iter->next;
		free(temp);
	}
}

int predicate_exists(Set* s, predicate* pred) {
	ListElem* iter = s->head;
	const char* name = pred->name;
	while(iter->next != NULL) {
		if(!strcmp(name, iter->value))
			return 1;
		else
			iter = iter->next;
	}
	return 0;
}

int insert_predicate(Set* s, predicate* pred) {
	if(predicate_exists(s, pred)) {
		return -1;
	}

	if(s->head == NULL) {
		ListElem* newElem = malloc(sizeof(ListElem));
		newElem->next = NULL;
		newElem->value = pred->name;
		s->tail = newElem;
		s->length++;
		return 1;
	} else {
		ListElem* newElem = malloc(sizeof(ListElem));
		newElem->next = NULL;
		newElem->value = pred->name;
		s->tail = newElem;
		s->length++;
		return 1;
	}
}

int remove_predicate(Set* s, predicate* pred) {
	if(!predicate_exists(s, pred))
		return -1;

	const char* val = pred->name;
	ListElem* iter;
	ListElem* head = s->head;
	ListElem* tail = s->tail;
	if(!strcmp(head->value, val)) {
		ListElem* temp = head->next;
		free(s->head);
		s->head = temp;
		assert(s->head != NULL);
		s->length--;
		return 1;
	} else if(!(strcmp(tail->value, val))) {
		iter = s->head;
		while(iter->next != s->tail) {
			iter = iter->next;
		}
		free(s->tail);
		s->tail = iter;
		s->length--;
		return 1;
	} 
	else {
		iter = s->head;
		while(strcmp(iter->value, val)) {
			iter = iter->next;
		}
		ListElem* temp = iter->next;
		temp->next = iter->next->next;
		free(iter);
		s->length--;
		return 1;
	}
}