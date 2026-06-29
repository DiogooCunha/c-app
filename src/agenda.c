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
    if (self->quantContacts == self->max_contacts) {
        int new_max = self->max_contacts * 2;
        Contact** tmp = realloc(self->contacts, new_max * sizeof(Contact*));
        if (!tmp) {
            printf("Error: failed to expand agenda\n");
            return;
        }
        self->contacts = tmp;
        self->max_contacts = new_max;
    }

    self->contacts[self->quantContacts] = contact;
    self->quantContacts++;
}

void list_contacts(Agenda* self) {
    for(int i = 0; i < self->quantContacts; i++) {
        printf("\n[%i] Contato: %s\n", i+1, get_contact_name(self->contacts[i]));
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

void drop_contact(Agenda* self, int index) {
    int indexReal = index - 1;
    if(indexReal < 0 || indexReal >= self->quantContacts) {
        printf("Indice invalido.");
        return;
    }

    destroy_contact(self->contacts[indexReal]);

    for(int i = indexReal; i <= self->quantContacts; i++) {
        self->contacts[i] = self->contacts[i+1];
    }

    self->quantContacts--;
}