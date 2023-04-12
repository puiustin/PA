#include <stdio.h>
#include "list.h"

int main()
{
    Node *list = create_list();

    Punct punct1 = {"punct_1", 0.0, 0.0};
    Punct punct2 = {"punct_2", 1.0, 0.0};
    Punct punct3 = {"punct_3", 1.0, 1.0};
    Punct punct4 = {"punct_4", 0.0, 1.0};

    add_element(list, punct1, 0);
    add_element(list, punct2, 1);
    add_element(list, punct3, 2);
    add_element(list, punct4, 3);

    printf("Lista initiala:\n");
    print_list(list);

    printf("\nDupa stergerea elementului de pe pozitia 1:\n");
    delete_element(list, 1);
    print_list(list);

    Punct punct5 = {"punct_5", 2.0, 1.0};
    printf("\nDupa adaugarea elementului punct5 pe pozitia 1:\n");
    add_element(list, punct5, 1);
    print_list(list);

    printf("\nDupa modificarea elementului de pe pozitia 2 cu punct2:\n");
    modify_element(list, punct2, 2);
    print_list(list);

    double perimeter = calculate_perimeter(list);
    printf("\nPerimetrul poligonului: %lf\n", perimeter);

    delete_list(list);

    return 0;
}
