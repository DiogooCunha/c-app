#ifndef CONTACT_H
#define CONTACT_H

typedef struct Contact Contact;
Contact* create_contact(char* name, char* number);
void destroy_contact(Contact* self);

char* get_contact_name(Contact* self);

#endif // CONTACT_H