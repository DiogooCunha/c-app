#include<stdio.h>

#include "contact.h"

int main() {
    Contact* contact = create_contact("Diogo", "55");
    printf("%s\n", get_contact_name(contact));
    printf("%s\n", get_contact_number(contact));

    destroy_contact(contact);

    return 0;
}