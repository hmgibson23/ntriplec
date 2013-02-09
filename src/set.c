#include <string.h>
#include <assert.h>

#include <stdio.h>
#include "set.h"


Set* create_set() {
	Set* set = malloc(sizeof(Set));
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

int predicate_exists(Set* s, predicate pred) {
	if(s->head == NULL) {
		fprintf(stderr, "Head appears to be null\n");
		return 0;
	}

	ListElem* iter = s->head;
	const char* name = pred;
	while(iter->next != NULL) {
		/*fprintf(stderr, "Iter is at: %s\n", iter->value);*/
		/*fprintf(stderr, "Name is: %s\n", name);*/
		if(!strcmp(name, iter->value)) {
			fprintf(stderr, "%s\n", name);
			fprintf(stderr, "%s\n", iter->value);
			return 1;
		}
		else
			fprintf(stderr, "%s\n", iter->value);
			iter = iter->next;
	}
	return 0;
}

int insert_predicate(Set* s, predicate pred) {
	if(predicate_exists(s, pred) && s->length != 0) {
		return -1;
	}

	if(s->head == NULL) {
		ListElem* newElem = malloc(sizeof(ListElem));
		newElem->next = NULL;
		newElem->value = pred;
		s->head = newElem;
		s->tail = newElem;
		s->length++;
		fprintf(stderr, "Element inserted at head\n");
		assert(s->head != NULL);
		fprintf(stderr, "%s\n", s->head->value);
		return 1;
	} else {
		ListElem* newElem = malloc(sizeof(ListElem));
		newElem->next = NULL;
		newElem->value = pred;
		s->tail->next = newElem;
		s->tail = newElem;
		s->length++;
		fprintf(stderr, "Inserted another element\n");
		fprintf(stderr, "Tail after insert now: %s\n", s->tail->value);
		fprintf(stderr, "Head after insert is: %s\n", s->head->value);
		return 1;
	}
}

int remove_predicate(Set* s, predicate pred) {
	if(!predicate_exists(s, pred))
		return -1;

	const char* val = pred;
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
		fprintf(stderr, "Head after remove is: %s\n", s->head->value);
		fprintf(stderr, "Tail after remove is: %s\n", s->tail->value);
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
		fprintf(stderr, "Tail after remove is: %s\n", s->tail->value);
		fprintf(stderr, "Head after remove is: %s\n", s->head->value);

		s->length--;
		return 1;
	}
}
