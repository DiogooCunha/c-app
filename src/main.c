#include<stdio.h>

#include "contact.h"
#include "agenda.h"

int main() {
    Agenda* agenda = create_agenda();
    Contact* contact1 = create_contact("Diogo", "55");
    add_contact(agenda, contact1);

    Contact *contact2 = create_contact("Arthur", "47");
    add_contact(agenda, contact2);

    list_contacts(agenda);

    export_to_csv(agenda);

    return 0;
}