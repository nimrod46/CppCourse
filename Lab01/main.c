#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADTStack.h"

#define MAX_LENGTH 16
struct intl_passenger {
    char given_name[MAX_LENGTH];
    char surname[MAX_LENGTH];
    char passport_id[MAX_LENGTH];
    char country[MAX_LENGTH];
};

typedef struct intl_passenger intl_passenger;

unsigned int get_data_by_index(const char *str, unsigned int startIndex, unsigned int endIndex, char *dest) {
    unsigned int i = 0;
    while (str[startIndex + i] != ' ' && startIndex + i <= endIndex) {
        dest[i] = str[startIndex + i];
        i++;
    }
    dest[i] = '\0';
    return startIndex + i;
}

void* clone_passenger(void* str_elem) {
    if (!str_elem) return NULL;
    intl_passenger *p = calloc(sizeof (struct intl_passenger), 1);
    intl_passenger* old_str_elem = (struct intl_passenger*) str_elem;
    strcat(p->given_name , old_str_elem->given_name);
    strcat(p->surname , old_str_elem->surname);
    strcat(p->passport_id , old_str_elem->passport_id);
    strcat(p->country , old_str_elem->country);
    return p;
};

char* label_elm(void* elem) {
    if (!elem) return NULL;
    intl_passenger* intlPassenger = (intl_passenger*) elem;
    char *p = calloc(strlen(intlPassenger->given_name) + 1 +
            strlen(intlPassenger->surname) + 1 +
            strlen(intlPassenger->passport_id) + 1 + 1,1);
    strcat(p , intlPassenger->given_name);
    strcat(p , " ");
    strcat(p , intlPassenger->surname);
    strcat(p , " ");
    strcat(p , intlPassenger->passport_id);
    return p;
};

//int main() {
//    FILE *f_in = fopen("international_passengers.dat", "r");
//    char *buf = NULL;
//    size_t buf_size = 0;
//    if (!f_in) {
//        fprintf(stderr, "Failed to open file: %s\n", "international_passengers.dat");
//        exit(2);
//    }
//    Stack stack = init(10000, clone_passenger, free, label_elm);
//    while (getline(&buf, &buf_size, f_in) != EOF) {
//        unsigned len = strlen(buf) - 2;
//        struct intl_passenger intlPassenger;
//        unsigned i = get_data_by_index(buf, 0, len, intlPassenger.given_name);
//        i = get_data_by_index(buf, ++i, len, intlPassenger.surname);
//        i = get_data_by_index(buf, ++i, len, intlPassenger.passport_id);
//        get_data_by_index(buf, ++i, len, intlPassenger.country);
//        push(stack, &intlPassenger);
//    }
//    print(stack);
//    return 0;
//}

