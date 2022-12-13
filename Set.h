#ifndef SET_H
#define SET_H

// ADT set type - an unordered set of elements.
#include <stdbool.h>

typedef void *Element;
typedef struct Set *Set;

// Create an empty set, with element manipulation functions:
// clone_func - return a pointer to the cloned element.
// free_func - free an element returned by clone_func
// cmp_func - return true if the two elements are equal
Set SetCreate(Element (*clone_func)(Element),
              void (*free_func)(Element),
              bool (*cmp_func)(Element, Element));

// Destroy the set, calling free_func to free all its elements
void SetDestroy(Set set);

// Add (a clone of) e to the set (if it is already in, do nothing).
void SetAdd(Set set, Element e);

// Remove e from set (if it is not in the set, do nothing)
void SetRemove(Set set, Element e);

// Return true if e is in the set
bool SetIsIn(Set set, Element e);

// Return true if the set is empty
bool SetIsEmpty(Set set);

// SetFirst, SetNext support iteration over all the set elements in some arbitrary order.
// Current position in the set is maintained through an internal iteration pointer to the set.
// Any changes made to the set (through SetAdd or SetRemove) invalidate the iteration pointer.
// Note that the returned elements are NOT CLONES and should not be modified.

// Resets the iteration pointer to the first element and returns that element.
// If the set is empty, return NULL.
Element SetFirst(Set set);

// Advances the iteration pointer to the next set element and returns  that element.
// If there is no next element returns NULL.
Element SetNext(Set set);

#endif
