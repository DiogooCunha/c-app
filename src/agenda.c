#include <stdlib.h>
#include <stdio.h>

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
        printf("Contato: %s\n", get_contact_name(self->contacts[i]));
        printf("Telefone: %s\n", get_contact_number(self->contacts[i]));
    }
}

void export_to_csv(Agenda* self) {
    FILE *file = fopen("agenda.csv", "w");
    if (file == NULL) {
        perror("Error opening the file");
        return;
    }

    fprintf(file, "ID,Name,Number\n");

    for (int i = 0; i < self->quantContacts; i++) {
        fprintf(file, "%d,%s,%s\n", 
            i, 
            get_contact_name(self->contacts[i]), 
            get_contact_number(self->contacts[i])
        );
    }

    fclose(file);
}