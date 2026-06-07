#ifndef AGENDA_H
#define AGENDA_H

#include "contact.h"

typedef struct Agenda Agenda;

/**
 * @brief Creates a new agenda
 *
 * @return Pointer to the new agenda, or NULL if malloc fails
 * @note Should be called only once, at the start of the application
 */
Agenda* create_agenda(void);

/**
 * @brief Frees all memory associated with the agenda
 *
 * @param self Pointer to the agenda to destroy
 */
void destroy_agenda(Agenda* self);

/**
 * @brief Add a contact to the agenda
 *
 * @param self The agenda create in the start
 * @param contact The contact information
 */
void add_contact(Agenda* self, Contact* contact);

/**
 * @brief List all contacts in the agenda
 *
 * @param self The agenda containing all contacts
 * @note This function does not return a value, but print all contact's infos
 */
void list_contacts(Agenda* self);

/**
 * @brief Filter contact by name
 * 
 * @param self The agenda containing all contacts
 * @param name The name that will be filtered
 * @note Print of the contact containing the exact name entered
 */
void list_contact_by_name(Agenda* self, char* name);

#endif