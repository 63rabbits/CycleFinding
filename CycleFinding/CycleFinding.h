#ifndef CycleFinding_h
#define CycleFinding_h

//////////////////////////////////////////////////
typedef struct Element {
    int id;
    struct Element *next;
} Element_t;

//////////////////////////////////////////////////
int findCycle(Element_t *start);

#endif
