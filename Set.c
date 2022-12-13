#include "Set.h"
#include <stdio.h>
#include <stdlib.h>

#define    QUOTA        512

struct Set {
    Element* array;
    size_t array_size;
    Element* it;     // Used for SetFirst() and SetNext()
    Element (*clone_func)(Element);
    void (*free_func)(Element);
    bool (*cmp_func)(Element, Element);
};


Set SetCreate(Element (*clone_func)(Element),
              void (*free_func)(Element),
              bool (*cmp_func)(Element, Element)) {
    Set set = malloc(sizeof(struct Set));
    if(!set) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n",
                __FILE__, __LINE__, sizeof(struct Set));
        exit(-1);
    }
    set->array_size = QUOTA;
    set->array = calloc(QUOTA, sizeof(Element));
    if(!set->array) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n",
                __FILE__, __LINE__, QUOTA*sizeof(Element));
        exit(-1);
    }
    set->it = NULL;
    set->clone_func = clone_func;
    set->free_func = free_func;
    set->cmp_func = cmp_func;
    return set;
}


void SetDestroy(Set s) {
    for(int i=0; i<s->array_size; i++) {
        s->free_func(s->array[i]);
    }
    free(s->array);
    free(s);
}


void SetRemove(Set s, Element e) {
    int i;
    for(i=0; i<s->array_size; i++)
        if (s->array[i] && s->cmp_func(s->array[i], e))
            break;
    // Remove e, if it was found
    if(i < s->array_size) {
        s->free_func(s->array[i]);
        s->array[i] = NULL;
    }
}


void SetAdd(Set s, Element e) {
    // Nothing to do if e is already in
    if(SetIsIn(s, e))
        return;
    // Look for an empty spot
    int i;
    for(i=0; i<s->array_size && s->array[i]; i++)
        ;
    // If array is full we need to increase size
    if(i == s->array_size) {
        s->array_size *= 2;
        s->array = realloc(s->array, s->array_size*sizeof(Element));
        if(!s->array) {
            fprintf(stderr, "%s/%u: failed to re-allocated %lu bytes\n\n",
                    __FILE__, __LINE__, s->array_size*sizeof(Element));
            exit(-1);
        }
        for(int j=i; j<s->array_size; j++)
            s->array[j] = NULL;
    }
    s->array[i] = s->clone_func(e);
}


bool SetIsIn(Set s, Element e) {
    int i;
    for(i=0; i<s->array_size; i++)
        if (s->array[i] && s->cmp_func(s->array[i], e))
            break;
    return (i < s->array_size);
}


bool SetIsEmpty(Set s) {
    int i;
    for(i=0; i<s->array_size && !s->array[i]; i++)
        ;
    return (i == s->array_size);
}


// Return first non-empty element in the range [it, it_end)
// Note: range includes it, but does not include it_end.
static Element *FirstElementAfter(Element *it,
                                       Element *it_end) {
    while (it < it_end && !*it) it++;
    return (it<it_end) ? it : NULL;
}


Element SetFirst(Set s) {
    s->it = FirstElementAfter(s->array, s->array + s->array_size);
    return s->it ? *(s->it) : NULL;
}


Element SetNext(Set s) {
    if (!s->it) return NULL;
    s->it = FirstElementAfter(s->it+1, s->array + s->array_size);
    return s->it ? *(s->it) : NULL;
}
