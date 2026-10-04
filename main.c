#include "contact.h"
#include <stdio.h>

/*save_and_exit function definition*/
int save_and_exit(AddressBook *addressbook)
{
    printf("Contacts saved successfully. Exiting...\n");
    return 1;
}

/* Structure declaration */

int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;
    load_contact_file(&addressbook);

    while (1)
    {
        printf("\nAddress book menu\n"); /* Give a prompt message for a user */
        printf("1.Add contact\n2.search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.save and exit\n7.Exit\n");
        printf("Enter the option : ");
        scanf("%d", &option);

        switch (option) /* Based on choosed option */
        {
        case 1:
        {
             /*  
            Creates a contact in the addressbook 
            The contact include the details as name,mobile number and mail id
            Name should only consists of characters upto the size of 20 characters
            Mobile number must be a numeric string of length of 10 charaters
            Mail id should be in the format of (....)@(...).com , it should contain only one '@' and one '.com' ,and they shouldnot be consecutive 
            If all the conditions are followed the contact can be created in the addressbook
            If any requirements are not satisfied it shows the related text and allows to re-enter the detail as per the requirement
            After adding the contact details it updates the contact count
            */ 
            create_contact(&addressbook);
            break;
        }

        case 2:
        {
           /*
            Searches for a contact in the addressbook
            It can search the contact by name or mobile number or mail id based on the option choosen
            The contacts having similar data as the search will be shown in the output
            If no similar contacts are found the output shows as 'Contact is not found!,Try again' abd allows to search again for the contact
            */
            printf("Search Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4. Exit\nEnter the option : "); /* Providing menu */
            search_contacts(&addressbook);
            break;
        }
        case 3:
        {
           /*Search for the contact based on the option choosen
            Shows the contacts similar to the search
            if more than one contact are similar then asks for the exact details of the contact and searches for it
            Edit the contact details based on the option choosen and the requirements of the detail
            If the edited details are not as per the requirements then it shows related error and allows to re-enter the detail
            */
            printf("Edit Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */

            edit_contact(&addressbook);
            break;
        }

        case 4:
        {
            /*
            Search for the contact based on the option choosen
            Shows the contacts similar to the search 
            if more than one contact are similar then asks for the exact details of the contact and searches for it
            Delete the contact
            updates the contact count and other contact details 
            */
            printf("Delete Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */

            delete_contact(&addressbook);
            break;
        }
        case 5:
        {
            /*
            Sorts the contact details using bubble sorting based on the option choosen
            Shows all the contacts in the adddressbook in sorted order in the output
            Redirects to the main menu
            */
            printf("List Contacts:");
            list_contacts(&addressbook);
            break;
        }
        case 6:
        {
            /*
            write contact count and all the contacts in the addressbook to the load.txt file in the format of name,mobile number,mail id\n
            */
            printf("save contacts:");
            save_contacts(&addressbook);
            break;
        }
        case 7:
        {
            printf("save_and_exit:");
            save_and_exit(&addressbook);
            break;
        }

        case 8:
        {
             /*
            terminates the program
            */
            printf("Exiting...\n");
            return 0;
        }
        default:
            printf("Invalid option \n");
            break;
        }
    }
    return 0;
}