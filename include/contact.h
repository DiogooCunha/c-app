#ifndef CONTACT_H
#define CONTACT_H

typedef struct Contact Contact;

/**
 * @brief Creates a new contact
 *
 * @param name The contact's name
 * @param number The contact's phone number
 * @return Pointer to the new contact, or NULL if malloc fails
 */
Contact* create_contact(char* name, char* number);

/**
 * @brief Frees all memory associated with a contact
 *
 * @param self Pointer to the contact to destroy 
 */
void destroy_contact(Contact* self);

/**
 * @brief Returns the contact name
 *
 * @param self Pointer to the contact
 * @return The contact's name
 */
char* get_contact_name(Contact* self);

/**
 * @brief Sets the contact name
 *
 * @param self Pointer to the contact
 * @param name New name
 */
void set_contact_name(Contact* self, char* name);

/**
 * @brief Returns the contact phone number
 *
 * @param self Pointer to the contact
 * @return The contact's phone number
 */
char* get_contact_number(Contact* self);

/**
 * @brief Sets the contact name
 *
 * @param self Pointer to the contact
 * @param number New phone number
 */
void set_contact_number(Contact* self, char* number);

#endif // CONTACT_H