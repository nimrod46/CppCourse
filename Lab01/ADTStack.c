#include <stdio.h>
#include <malloc.h>
#include "ADTStack.h"

struct Stack_t {
void** array;
int top;
int maxCapacity;
void* (*cp_elm)(void*);
void (*fr_elm)(void*);
char* (*lbl_elm)(void*);
};

Stack init(int max_size, void* (*cpy_elm)(void*), void (*free_elm)(void*), char* (*label_elm)(void*)) {
	Stack ps;
	if ((max_size<=0)||(!cpy_elm)||(!free_elm)||(!label_elm)) {
		fprintf(stderr,"Fatal error\n");
                return NULL; 
        }        
	ps = (Stack)malloc(sizeof(struct Stack_t));
	if (!ps) {
		fprintf(stderr,"Fatal error\n");
		return NULL;
	}	
	ps->array = malloc(max_size*sizeof(void*));
	if (!(ps->array)) {
		free(ps);
		fprintf(stderr,"Fatal error\n");
		return NULL;
	}
	ps->top = 0;
	ps->maxCapacity = max_size;
	ps->cp_elm = cpy_elm;
	ps->fr_elm = free_elm;
	ps->lbl_elm = label_elm;
	return ps;
}

int push (Stack s, void* elm) {
	if((!s)||(s->top==s->maxCapacity)) {
		fprintf(stderr,"Fatal error\n");
		return 0;
	}
	s->array[s->top] = s->cp_elm(elm);
	s->top++;
	return 1;
}

void* pop (Stack s) {
	if ((!s)||(s->top==0)) {
		fprintf(stderr,"Fatal error\n");
		return NULL;
	}
	s->top--;
	return s->array[s->top]; 
}

void clear (Stack s) {
	if (!s) {
		fprintf(stderr,"Fatal error\n");
                return;
        } 
	while (s->top > 0)
		s->fr_elm(s->array[--s->top]);
}

int size(Stack s) {
	if (!s) {
                fprintf(stderr,"Fatal error\n");
                return -1;
        }
	return s->top;
}

void print(Stack s) {
	int cur;
	char* label = NULL;
	if (!s) {
                fprintf(stderr,"Fatal error\n");
                return;
        } 
	cur = s->top;
	while (cur > 0) {
		label = s->lbl_elm(s->array[--cur]);
		if (!label) {
			fprintf(stderr,"Fatal error\n");
			return;
		} else {
			printf("%s\n",label);
			free(label);
		}
	}
}

void destroy (Stack s) {
	if (!s) {
                fprintf(stderr,"Fatal error\n");
                return;
        } 
	clear(s);
	free(s->array);
	free(s);
}
