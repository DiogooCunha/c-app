#include<stdio.h>

#include "contact.h"

int main() {
    Contact* contact = create_contact("Diogo", "55");
    printf("%s", get_contact_name(contact));

    destroy_contact(contact);

    return 0;
}