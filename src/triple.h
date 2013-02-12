#ifndef TRIPLE_H
#define TRIPLE_H


typedef struct _triple {
	predicate* pred;
	const char* subject;
	_triple* object;
} Triple;


Triple* create_triple(const char*, predicate*, const char*); 


#endif