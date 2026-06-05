#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"

struct Contact {
    char* name;
    char* number;
};

Contact* create_contact(char* name, char* number) {
    Contact* self = malloc(sizeof(Contact));

    if (self) {
        self->number = strdup(number);
        self->name = strdup(name);
    }

    return self;
}

void destroy_contact(Contact* self) {
    free(self->name);
    free(self->number);
    free(self);
}

char* get_contact_name(Contact* self) {
    return self->name;
}

void set_contact_name(Contact* self, char* name) {
    free(self->name);
    self->name = strdup(name);
}

char* get_contact_number(Contact* self) {
    return self->number;
}

void set_contact_number(Contact* self, char* number) {
    free(self->number);
    self->number = strdup(number);
}