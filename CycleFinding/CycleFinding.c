#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include "CycleFinding.h"

//////////////////////////////////////////////////
int findCycle(Element_t *start) {
    Element_t *turtle = start;
    Element_t *rabbit = start;
    
    while (rabbit != NULL) {
        turtle = turtle->next;          // Hop 1.
        rabbit = rabbit->next->next;    // Hop 2.
        if (turtle == rabbit) {
            // search cycle entrance.
            turtle = start;
            while (true) {
                if (turtle == rabbit) {
                    return rabbit->id;
                }
                turtle = turtle->next;
                rabbit = rabbit->next;
            }
        }
    }
    
    return -1;
}
