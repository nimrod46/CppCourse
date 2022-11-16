#ifndef _ADTSTACK_H
#define _ADTSTACK_H

typedef struct Stack_t* Stack;

/* initializes the Stack; sets the maximal capacity to max_size
   returns a pointer to a record on the HEAP
 */
Stack init(int max_size, void* (*cpy_elm)(void*), void (*free_elm)(void*), char* (*label_elm)(void*));

/* inserts a copy of the element to the top of the stack. 
returns a non-zero value upon success, zero on fail.
fails if init was not called prior to that, or if the stack is full. */
int push (Stack s, void* elm);

/* removes the element at the top of the stack and returns it.
fails either if init was not called prior to that, or if the stack is empty */
void* pop (Stack s);

/* removes all elements from the stack; all elements are freed.
fails if init was not called prior to that */
void clear (Stack s);

/* returns the number of elements in the stack, or a negative value when fails.
fails either if init was not called prior to that, or if the stack is empty */
int size(Stack s);

/* prints the contents of the stack.
fails if init was not called prior to that */
void print(Stack s);

/* releases all the resources of the stack */
void destroy (Stack s);

#endif
