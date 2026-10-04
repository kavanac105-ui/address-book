#include "contact.h"
// Function to display all contacts in a single line format
int edit_contact(AddressBook *addressbook)
{
    int found, match_indices[100], match_count, chosen_serial;
    while(1)
    {
        int opt;
        printf("which contact based you can search\n1.name\n2.mobile number\n3.email id\n4.exit\n");
        printf("\npls select one option\n");
        scanf(" %d",&opt);
        getchar();
        int count=0;
        match_count = 0; 
        found = 0;
        switch(opt)
        {
            
            case 1:
            {
                char name[20];
                printf("\nEnter the name of the person you want to edit: ");
                scanf(" %[^\n]",name);
                getchar();
                for(int i=0; i<addressbook->contact_count; i++)
                {
                    if(strcmp(addressbook->contact_details[i].Name,name)==0)
                    {
                        match_indices[match_count++]=i;
                        found=1;
                    }
                }
                if(!found)
                {
                    printf("\nPlease enter the email ID of the contact you want to delete: ");

                }
                if(match_count==1)
                {
                //directly edit only one match
                    edit_contact_details(addressbook,match_indices[0]);
                }
                else
                {
                    for(int j=0; j<match_count; j++)
                    {
                        printf("%2d.  Name : %-20s  Phone : %-15s  Email : %s\n",
                        j + 1,
                        addressbook->contact_details[match_indices[j]].Name,
                        addressbook->contact_details[match_indices[j]].Mobile_number,
                        addressbook->contact_details[match_indices[j]].Mail_ID);
                    }
                    printf("please chosen one serial option: \n");
                    scanf(" %d",&chosen_serial);
                    while (getchar() != '\n');  // clear buffer
                    if(chosen_serial<1 || chosen_serial>match_count)
                    {
                        printf("\nPlease select valid option, try again.\n");
                        break;
                    }
                    edit_contact_details(addressbook,match_indices[chosen_serial - 1]);

                }
                
            }
            break;
            case 2:
            {
                
                char mobilenumber[20];
                printf("\nEnter the mobile number to search for: ");
                scanf(" %[^\n]",mobilenumber);
                getchar();
                for(int i=0; i<addressbook->contact_count; i++)
                {
                    if(strcmp(addressbook->contact_details[i].Mobile_number,mobilenumber)==0)
                    {
                        printf("Contact Details:\nName:%s | Phone:%s | Email:%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
                        edit_contact_details(addressbook, i); // go to edit
                        found = 1;
                        break;
                    }
                }
                if(!found)
                {
                    printf("\nmobile number is not found\n");

                }
                
            }
            break;
            case 3:
            {
                char email_id[20];
                printf("\nEnter the email ID to edit for: ");
                scanf(" %[^\n]",email_id);
                getchar();
                for(int i=0; i<addressbook->contact_count; i++)
                {
                    if(strcmp(addressbook->contact_details[i].Mail_ID,email_id)==0)
                    {
                        printf("Contact Details:\nName:%s\n  Phone:%s\n  Email:%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
                        edit_contact_details(addressbook,i); // go to edit
                        found = 1;
                        break;
                    }
                }
                if(!found)
                {
                    printf("\nEmail ID not found.\n");
                }
                
            
            }
            break;
            case 4:
            printf("thank you\n");
            count=0;
            break;
        
            
        }
        if(count==0)
        break;
    }
}