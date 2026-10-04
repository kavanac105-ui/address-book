#include "contact.h"
// Function to display all contacts in tabular format
void list_contacts(AddressBook *addressbook)
{
    /* Check if address book is empty */
    if(addressbook->contact_count==0)
    {
        printf("No contacts available to display.\n");
        return;
    }
    printf("\nContact List:\n");

    /* Display each contact */
    for(int i = 0; i < addressbook->contact_count; i++)
    {
        /* print contact in one line */
        printf("%d. Name: %s | Mobile: %s | Email: %s\n",
        i + 1,
        addressbook->contact_details[i].Name,
        addressbook->contact_details[i].Mobile_number,
        addressbook->contact_details[i].Mail_ID);
    }

    
    
}