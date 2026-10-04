#include "contact.h"
// Function to search contacts based on name, mobile number, or email ID
int search_contacts(AddressBook *addressbook)
{
    int found,match_indices[100],match_count,chosen_serial;
    int i=1;
    while(i)   // Main loop for search menu
    {
        match_count=0;  //Reset match count
        int count=0;   //Control variable to exit loop
        int opt;

        // Dislay search options
        printf("what base you can search\n1.name\n2.mobile number\n3.mail id\n4.exit");
        scanf(" %d",&opt);
        getchar();  // Clear new line
        switch(opt)
        {
            case 1:  //search by name
            {
                char name[100];
                printf("pls enter the name which detailes you can search:\n");
                scanf(" %[^\n]",name);
                getchar();
                if(!valid_name(name))  // valid name
                {
                    continue;
                }
                for(int i=0; i<addressbook->contact_count; i++)
                {
                    if(strcmp(addressbook->contact_details[i].Name,name)==0)
                    {
                        match_indices[match_count++]=i;
                        found=1;
                    }
                }
                if(found==0)  //if no match found
                {
                    printf("name is not found\n");
                    break;
                }
                if(match_count==1)  //only one matching contact
                {
                    printf("name is found\n");
                    //direct value is print
                    int index=match_indices[0];
                    printf("Contact Details:\nName:%s | Phone:%s | Email:%s\n",
                    addressbook->contact_details[index].Name,
                    addressbook->contact_details[index].Mobile_number,
                    addressbook->contact_details[index].Mail_ID);
                    

                }
                else // multiple matching contacts
                {
                    
                    for(int j=0; j<match_count; j++)
                    {
                        //direct value is print
                        printf("%d.    name:%s      phone:%s   mail_id:%s\n",
                        j+1,addressbook->contact_details[match_indices[j]].Name,
                        addressbook->contact_details[match_indices[j]].Mobile_number,
                        addressbook->contact_details[match_indices[j]].Mail_ID);
                    
                    }

                    
                }
            }
            break;
            
            case 2: // search by mobile number
            {
                while(1)
                {
                    char mobilenumber[100];
                    printf("pls enter the mobile number whitch detailes you can search:");
                    scanf(" %[^\n]",mobilenumber);
                    getchar();
                    if(!valid_mobile(mobilenumber))  //validate mobie number
                    {
                    continue;
                    }
                    int found=0;
                    int i;
                    // search contact list
                    for(i=0; i<addressbook->contact_count; i++)
                    {
                        if(strcmp(addressbook->contact_details[i].Mobile_number,mobilenumber)==0)
                        {
                            found = 1;
                            printf("\nMobile number is found:\n");
                            printf("Name  : %s\n",  addressbook->contact_details[i].Name);
                            printf("Phone : %s\n",  addressbook->contact_details[i].Mobile_number);
                            printf("Email : %s\n",  addressbook->contact_details[i].Mail_ID);
                            printf("----------------------------------------\n");
                            break;                 
                        }
                    }
                    if(found==0)  //if not found
                    {
                    printf("mobile number is not found:\n");
                    }
                    printf("you want to search again\n1.yes\n0.no\n");
                    scanf("%d",&i);
                    if(i==0)
                      {
                        break;
                    }
                }
            }
            break;

            case 3:  //Search by email ID
            {
                while(1)
                {
                    char email_id[100];
                    printf("pls enter the email id whitch detailes you can search:");
                    scanf(" %[^\n]",email_id);
                    getchar();
                    if(!valid_email(email_id))  //valiadate email
                    {
                    continue;
                    }
                    int found=0;
                    int i;
                    // search contact list
                    for(i=0; i<addressbook->contact_count; i++)
                    {
                        if(strcmp(addressbook->contact_details[i].Mail_ID,email_id)==0)
                        {
                            found = 1;
                            printf("\nEmail ID is found:\n");
                            printf("Name  : %s\n",  addressbook->contact_details[i].Name);
                            printf("Phone : %s\n",  addressbook->contact_details[i].Mobile_number);
                            printf("Email : %s\n",  addressbook->contact_details[i].Mail_ID);
                            printf("----------------------------------------\n");
                            break;
                        }
                    }
                    if(found==0)  // If email not found 
                    {
                    printf("\nEmail ID not found.\n");
                    }
                    // ask user whether to search again
                    printf("Do you want to search again?\n1. Yes\n0. No\n");
                    scanf("%d",&i);
                    if(i==0)
                    {
                        break;
                    }
                }
            }
            break;
            case 4:  // Exit search
            printf("thank you\n");
            count=0;
            break;

        }
        if(count==0);  // Exit main loop
        break;
    }
            
}
