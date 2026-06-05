#ifndef CONTACT_H
#define CONTACT_H

typedef struct Contact Contact;
Contact* create_contact(char* name, char* number);
void destroy_contact(Contact* self);

char* get_contact_name(Contact* self);
void set_contact_name(Contact* self, char* name);

char* get_contact_number(Contact* self);
void set_contact_number(Contact* self, char* number);

#endif // CONTACT_H