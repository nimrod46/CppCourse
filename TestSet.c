#include "TestSet.h"
#include "Set.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

static Element clone_int(Element int_elem) {
    int *p = malloc(sizeof(int));
    *p = *((int*)int_elem);
    return p;
};

static bool cmp_int(Element int_elem_1, Element int_elem_2) {
    return *((int*)int_elem_1) == *((int*)int_elem_2);
}

static int set_size(Set set) {
    int c = 0;
    for(Element p=SetFirst(set); p; p=SetNext(set)) {
        c++;
    }
    return c;
}

static int get_set_bits(Set set) {
    int ret = 0;
    for(int i=0; i<30; i++) {
        if (SetIsIn(set,&i))
            ret |= (1<<i);
    }
    return ret;
}

static void test_int_set1() {
    Set set = SetCreate(clone_int, free, cmp_int);
    assert(SetIsEmpty(set));
    assert(set_size(set) == 0);
    assert(get_set_bits(set) == 0);
    int i0=0, i1=1, i7=7;
    SetAdd(set, &i0);
    SetAdd(set, &i7);
    SetAdd(set, &i7);
    assert(!SetIsEmpty(set));
    assert(set_size(set) == 2);
    assert(SetIsIn(set,&i0));
    assert(SetIsIn(set,&i7));
    assert(get_set_bits(set) == 0x81);
    SetRemove(set, &i7);
    SetAdd(set, &i1);
    assert(set_size(set) == 2);
    assert(get_set_bits(set) == 0x3);
    SetDestroy(set);
}

static void test_int_set2(int n) {
    Set set = SetCreate(clone_int, free, cmp_int);
    for(int i=0; i<n; i++)
        SetAdd(set, &i);
    assert(set_size(set) == n);
    for(int i=0; i<n/2; i++)
        SetRemove(set,&i);
    assert(set_size(set) == n-n/2);
    for(int* p=SetFirst(set); p; p=SetNext(set)) {
        assert(*p >= n/2 && *p < n);
    }
}

static Element clone_str(Element str_elem) {
    char *p = malloc(strlen(str_elem)+1);
    strcpy(p, str_elem);
    return p;
};

static bool cmp_str(Element str_elem_1, Element str_elem_2) {
    return !strcmp(str_elem_1, str_elem_2);
}

static void test_str_set() {
    Set set = SetCreate(clone_str, free, cmp_str);
    assert(set_size(set) == 0);
    assert(SetIsEmpty(set));
    SetAdd(set, "");
    SetAdd(set, "abc");
    SetAdd(set, "def");
    assert(set_size(set) == 3);
    assert(!SetIsEmpty(set));
    assert(SetIsIn(set,"abc"));
    assert(SetIsIn(set,""));
    assert(!SetIsIn(set,"ABC"));
    SetRemove(set, "abc");
    SetRemove(set, "abc");
    assert(set_size(set) == 2);
    assert(!SetIsIn(set,"abc"));
    assert(SetIsIn(set,""));
    assert(!SetIsIn(set,"ABC"));
    assert(!SetIsEmpty(set));
    SetDestroy(set);
}

void test_set() {
    test_int_set1();
    test_int_set2(1100);
    test_str_set();
}
