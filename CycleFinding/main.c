#include <unistd.h>
//#define checkMemoryLeak

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include "CycleFinding.h"

//////////////////////////////////////////////////
void test(void);
Element_t *createCycleList(int length, int cycleEntrance);
void destroyCycleList(Element_t *start, int length);
Element_t *createElementForSLList(int value);

//////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
    
#ifdef checkMemoryLeak
    while (true) {
        test();
        sleep(1);
    }
#else
    test();
#endif
    
    return EXIT_SUCCESS;
}

void test() {
    int length = 10;
    int cycleEntrance = 5;
    
    Element_t *start = createCycleList(length, cycleEntrance);
    if (start == NULL) return;
    
    int entrance = findCycle(start);
    if (entrance >= 0) {
        printf("[%s] The list is a cycle list. \ncycle entrance is element ID = %d.\n", __func__, entrance);
    }
    else {
        printf("[%s] The list is Not a cycle list.\n", __func__);
    }
    
    destroyCycleList(start, length);
}

//////////////////////////////////////////////////
// for Cycle list.
Element_t *createCycleList(int length, int cycleEntrance) {
    // Block illegal parameters.
    if (length <= 1) {
        printf("error [%s] : The length is insufficient. (length > 1)\n", __func__);
        return NULL;
    }
    if (cycleEntrance >= length) {
        printf("error [%s] : The cycleEntrance is insufficient.\nThe cycleEntrance must be less than length.\n", __func__);
        return NULL;
    }
    
    Element_t *start = NULL;
    Element_t *prev = start;
    Element_t *e = NULL;
    Element_t *entrance = NULL;
    for (int i=0; i<length; i++) {
        e = createElementForSLList(i);
        if (i == 0) {
            start = e;
        }
        else {
            prev->next = e;
        }
        if (i == cycleEntrance) {
            entrance = e;
        }
        prev = e;
    }
    e->next = entrance;
    
    Element_t *element = start;
    for (int i=0; i<length; i++) {
        printf("[%s] element ID : %4d -> ", __func__, element->id);
        if (element->next != NULL) {
            printf("%4d\n", element->next->id);
        }
        else {
            printf("null\n");
        }
        element = element->next;
    }
    
    return start;
}

void destroyCycleList(Element_t *start, int length) {
    Element_t *e = start;
    for (int i=0; i<length; i++) {
        Element_t *next = e->next;
        free(e);
        e = next;
    }
}

Element_t *createElementForSLList(int value) {
    Element_t *element = malloc(sizeof(Element_t));
    if (element == NULL) return NULL;
    element->id = value;
    element->next = NULL;
    
    return element;
}
