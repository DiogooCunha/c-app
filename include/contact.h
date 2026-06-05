/**
 * @file contact.h
 * @brief Contact utility functions
 */

#ifndef CONTACT_H
#define CONTACT_H

/**
 * @brief type representing a contact.
 */
typedef struct Contact Contact;

/**
 * @brief Creates a new contact.
 *
 * @param name    The contact's name
 * @param number  The contact's phone number
 * @return        Pointer to the new Contact, or NULL if allocation fails
 */
Contact* create_contact(char* name, char* number);

/**
 * @brief Frees all memory associated with a contact.
 *
 * @param self  Pointer to the Contact to destroy
 */
void destroy_contact(Contact* self);

/**
 * @brief Returns the contact's name.
 *
 * @param self  Pointer to the Contact
 * @return      The contact's name as a null-terminated string
 */
char* get_contact_name(Contact* self);

/**
 * @brief Sets the contact's name.
 *
 * @param self  Pointer to the Contact
 * @param name  New name
 */
void set_contact_name(Contact* self, char* name);

/**
 * @brief Returns the contact's phone number.
 *
 * @param self  Pointer to the Contact
 * @return      The contact's number as a null-terminated string
 */
char* get_contact_number(Contact* self);

/**
 * @brief Sets the contact's phone number.
 *
 * @param self    Pointer to the Contact
 * @param number  New phone number (null-terminated string)
 */
void set_contact_number(Contact* self, char* number);

#endif // CONTACT_H