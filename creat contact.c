#include "contact.h"
int create_contact(AddressBook *addressbook)
{
    int i=1; //controls whether user wants to add another contact
    while(i)
    {
        /* Read and validate contact name */
        while(1)
        {
            char name[10];
            printf("\nEnter the name: ");
            scanf(" %[^\n]",name);
            getchar();
            if(!valid_name(name)) //validate name
            {
                continue; 
            }
           strcpy(addressbook->contact_details[addressbook->contact_count].Name,name);
           break;
        }
         /* Read and validate mobile number */
        while(1)
        {
            char mobilenumber[100];
            printf("\nEnter the mobile number: ");
            scanf(" %[^\n]",mobilenumber);
            getchar();
            if(!valid_mobile(mobilenumber)) //validate mobile number
            {
                continue;
            }
            if(!duplicate_mobile(mobilenumber,addressbook)) //check duplicate
            {
                continue;
            }
            strcpy(addressbook->contact_details[addressbook->contact_count]. Mobile_number,mobilenumber);
            break;
        }
         /* Read and validate email ID */
        while(1)
        {
            char email_id[35];
            printf("\nEnter the email ID: ");
            scanf(" %[^\n]",email_id);
            getchar();
            if(!valid_email(email_id)) //validate email
            {
              continue;
            }
            if(!duplicate_email(email_id,addressbook))  // check duplicate
            {
                continue;
            }
            strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,email_id);
            break;
        }
       addressbook->contact_count++;  // increment contact count

       /* Ask user whether to add another contact */
       printf("\nDo you want to add another contact?\n1. Yes\n0. No\n");
       printf("\npls select one option: ");
       scanf(" %d",&i);
       getchar();

    }
}