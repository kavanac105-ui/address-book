#include "contact.h"
// Function to delete a contact from the address book
int delete_contact(AddressBook *addressbook)
{
    int found,match_indices[100],match_count,chosen_serial;
    while(1)
    {
        int count;
        int k;
        int found=0;  // flag to check if contact is found
        int match_count=0; // number of matching contacts
        int i; 
        printf("How would you like to delete the contact details?\n1. By Name\n2. By Address\n3. By Email ID\n4. Exit\n");
        scanf("%d",&i);
        switch(i)
        {
            /* Deleted by name */
            case 1:
            {
                char name[20];
                printf("\nEnter the contact name you want to delete: ");
                scanf(" %[^\n]",name);
                getchar();
                /* Search matching names */
                for(int i=0; i<addressbook->contact_count; i++)
                {
                    if(strcmp(addressbook->contact_details[i].Name,name)==0)
                    {
                        match_indices[match_count++]=i;
                        found=1;
                    }
                }
                if(found==0)
                {
                    printf("\nname is not found\n");
                    break;
                }
                /* if only one contact matches */
                if(match_count==1)
                {
                    //directly you can delete
                    int index=match_indices[0];
                    printf("Contact Details:\nName:%s\nPhone:%s\n Email:%s\n",addressbook->contact_details[index].Name,addressbook->contact_details[index].Mobile_number,addressbook->contact_details[index].Mail_ID);


                    int ch;
                    printf("\nconfirm you can delete\n 1.yes\n2.no\n");
                    scanf(" %d",&ch);
                    getchar();
                    if(ch==1)
                    {
                         /* Shift contacts after deleted index */
                        for(int j=index; j<addressbook->contact_count-1; j++)
                        {
                            addressbook->contact_details[k]=addressbook->contact_details[k+1];
                        }
                        addressbook->contact_count--;
                        printf("\nsucessfully delecte\n");
                    }

                    
                }
                else
                {
                    //multiple name is found
                    for(int j=0; j<match_count; j++)
                    {
                        printf("\n----- Contact Details -----\n");
                        printf("Name       : %s\n", addressbook->contact_details[match_indices[j]].Name);
                        printf("Phone      : %s\n", addressbook->contact_details[match_indices[j]].Mobile_number);
                        printf("Email      : %s\n", addressbook->contact_details[match_indices[j]].Mail_ID);
                        printf("---------------------------\n");
                    }
                    printf("\nPlease choose one serial number: ");
                    scanf(" %d",&chosen_serial);
                    while (getchar() != '\n'); 
                    if (chosen_serial < 1 || chosen_serial > match_count) {
                        printf("Invalid choice, please select valid choice to delete\n");
                        break;
                    }
                    int ws;
                    printf("confirm you can delete: 1.yes\n2.no\n");
                    scanf("%d",&ws);
                    if(ws==1)
                    {
                        for(int k=chosen_serial; k<addressbook->contact_count; k++)
                        {
                            addressbook->contact_details[k]=addressbook->contact_details[k+1];
                        }
                        addressbook->contact_count--;
                        printf("\nsucessfully delete\n");
                    }


                }
            }
            break;
            
            /* Deleted by mobile number */
            case 2:
            {
                char mobilenumber[20];
                printf("\nEnter the specific mobile number to delete: ");
                scanf(" %[^\n]",mobilenumber);
                getchar();
                int found=0;
                for(int i=0; i<addressbook->contact_count; i++)
                {
                    if(strcmp(addressbook->contact_details[i].Mobile_number,mobilenumber)==0)
                    {
                        int ch;
                        printf("confirm you can delete:\n1.yes\n2.no\n");
                        scanf("%d",&ch);
                        if(ch==1)
                        {

                        
                            for (int k = i; k < addressbook->contact_count - 1; k++)
                            {
                                addressbook->contact_details[k] = addressbook->contact_details[k + 1];
                            }
                            addressbook->contact_count--;
                            found = 1;
                            printf("\nAll contact details have been deleted successfully.\n");
                            break;
                        }
                    }
                }
                if(found==0)
                {
                    printf("mobile number is not found\n");
                }
            }
            break;
            
            /* Deleted by email id */
            case 3:
            {
                char email_id[20];
                printf("\nPlease enter the email ID of the contact you want to delete: ");
                scanf(" %[^\n]",email_id);
                getchar();
                int found=0;
                for(int j=0; j<addressbook->contact_count; j++)
                {
                    if(strcmp(addressbook->contact_details[j].Mail_ID,email_id)==0)
                    {
                        int ch;
                        printf("confirm you can delete:\n1.yes\n2.no\n");
                        scanf("%d",&ch);
                        if(ch==1)
                        {
                            for (int k = j; k < addressbook->contact_count - 1; k++)
                            {
                                addressbook->contact_details[k] = addressbook->contact_details[k + 1];
                            }
                            addressbook->contact_count--;
                            found = 1;
                            printf("Deleted the complete contact details.\n");
                            break;
                        }
                    }
                }
                if(found==0)
                {
                    printf("mail_id is not found\n");
                }
            }
            break;

            /* EXIt */
            case 4:
            printf("than you.\n");
            count=0;
            break;
            printf("one more attemts you want\n1.yes\n0.no");
            scanf("%d",&i);
            
        }
        if(count==0)
        break;
    }
    return 0;
   
} 