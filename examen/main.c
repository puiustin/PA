#include <stdio.h>
#include <stdlib.h>

#include "cox.h"

int main(void)
{

    Node *head = createList();

    addtolist(head, 5);
    addtolist(head, 4);
    addtolist(head, 3);
    addtolist(head, 2);
    addtolist(head, 1);
    addtolist(head, 0);

    afisare(head);

    return 0;
}