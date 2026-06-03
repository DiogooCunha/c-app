#include <stdio.h>
#include "contact.h"

int CreateContact() {
    contact NewContact;

    printf("Enter a name for new contact:\n");
    scanf("%v", &NewContact.name);

    printf("Enter a telephone for new contact:\n");
    scanf("%v", &NewContact.telephone);

    return 0;
}