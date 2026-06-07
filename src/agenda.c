#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "agenda.h"
#include "contact.h"

struct Agenda
{
    Contact** contacts;
    int quantContacts;
    int max_contacts;
};

Agenda* create_agenda(void) {
    Agenda* self = malloc(sizeof(Agenda));
    
    if(self){
        self->max_contacts = 50;
        self->quantContacts = 0;
        self->contacts = malloc(self->max_contacts * sizeof(Contact*));
    }

    return self;
}

void destroy_agenda(Agenda* self) {
    for(int i = 0; i < self->quantContacts; i++) {
        destroy_contact(self->contacts[i]);
    }

    free(self->contacts);
    free(self);
}

void add_contact(Agenda* self, Contact* contact) {
    self->contacts[self->quantContacts] = contact;
    self->quantContacts++;
}

void list_contacts(Agenda* self) {
    for(int i = 0; i < self->quantContacts; i++) {
        printf("\nContato: %s\n", get_contact_name(self->contacts[i]));
        printf("Telefone: %s\n", get_contact_number(self->contacts[i]));
    }
}

void list_contact_by_name(Agenda* self, char* name) {
    for(int i = 0; i < self->quantContacts; i++) {
        if(strcmp(get_contact_name(self->contacts[i]), name) == 0) {
            printf("Contato: %s\n", get_contact_name(self->contacts[i]));
            printf("Telefone: %s\n", get_contact_number(self->contacts[i]));
            return;
        }
    }
    printf("Nenhum contato encontrado\n");
}