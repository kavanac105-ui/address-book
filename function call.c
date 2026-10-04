#include "contact.h"
// Functions to validate name, mobile, email, check duplicates, and edit contact details in AddressBook
int valid_name(char *name)
{
    for(int i=0; name[i]!='\0';i++)
    {
        if(!((name[i]>='a' && name[i]<='z') || //small alphabates can check here
        (name[i]>='A' && name[i]<='Z')||(name[i]==' '))) //capital alphabates can check here
        {
            printf("Invalid name! Only alphabets allowed.\n");
            return 0;//invalid output
        }
    }
    return 1;//valid output
}
int valid_mobile(char *mobilenumber)
{
    int len=strlen(mobilenumber);//length of the mobile number
    if(len!=10)//with out 10 digit
    {
        printf("Mobile number must be 10 digits.\n");
        return 0;//invalid
    }
    if(mobilenumber[0]< '6' || mobilenumber[0]> '9')//first digit of mobile number always is higher than 5
    {
        printf("Mobile number must start with 6 0r 7 0r 8 0r 9 digit.\n");
        return 0;//invalid
    }
    for(int i=0; mobilenumber[i]!='\0'; i++)
    {
        if(!isdigit(mobilenumber[i]))//not digit value can found
        {
            printf("MObile number should contain only number! Try again.\n");
            return 0;//invalid
        }
    }
    return 1;//finally valid input
}
int duplicate_mobile(char *mobilenumber,AddressBook *addressbook)
{
    for(int i=0; i<addressbook->contact_count; i++)
    {
        if(strcmp(addressbook->contact_details[i].Mobile_number,mobilenumber)==0)
        {
            printf("Mobile Number already exists! Please enter a different Mobile Number.\n");
            return 0;
        }
    }
    return 1;
}

int valid_email(char *email_id)
{
    int i;
    int len=strlen(email_id);//length will calculate
    // if(email_id[0]>=0  && email_id[0]<=9)//start mail id not start from digit
    // {
    //     printf("Invalid Email ID: Email should not start with a number!\n");
    //     return 0; //invalid
    // }
    if (!isalpha(email_id[0]))  //if  first character is not  alphabet then return 0
    {
        printf("Mail ID should start with alphabet character only.\n");
        return 0;//invalid
    }
    if(len>0 && len<5)//check the length
    {
        printf("Mail ID length should be minimum 5 character\n");
        return 0;//invalid
    }
    for(i=0; i<len; i++)
    {
       char ch=email_id[i];
       if(!(isalnum(ch) || ch== '@' ||ch=='.'))
       {
            printf("Mail ID must contain alphabets,digits,@ and dot.\n");
            return 0;
       }
    }
    int dot=0;
    int at=0;
    for(int i=0; email_id[i]!='\0'; i++)
    {
        char ch=email_id[i];
        if(ch=='@')
        {
          at++;
        }
        if(ch=='.')
        {
            dot++;
        }
    }
    if(dot==0 || dot>1)
    {
        printf("Invalid Email: '.' must appear only once!\n");
        return 0;
    }
    if(at==0 || at>1)
    {
        printf("Invalid Email: '@' must appear only once!\n");
        return 0;
    }
    int dotindex;int atindex;
    for(int i=0; email_id[i]!='\0'; i++)
    {
       if(email_id[i]=='@')
       {
            atindex=i;
       }
       if(email_id[i]=='.')
       {
            dotindex=i;
       }
    }
    if(dotindex<atindex)
    {
        printf("Invalid Email: '.' must come after '@'\n");
        return 0; 
    }
    if(dotindex==atindex+1)
    {
        printf("Invalid Email: '.' cannot be immediately after '@'\n");
        return 0;
    }
    int length=strlen(email_id);
    if(strcmp(email_id+length-4,".com")!=0)//email id compare with last .com is there or not
    {
       printf("Invalid Email: Email must end with .com\n");
       return 0;
    }
    return 1;//valid function
    
}
int duplicate_email(char *email_id,AddressBook *addressbook)
{
    for(int i=0; i<addressbook->contact_count; i++)
    {
        if(strcmp(addressbook->contact_details[i].Mail_ID,email_id)==0)
        {
           printf("Email_Id already exists! Please enter a different email_id.\n");
           return 0;
        }
    }
    return 1;
}
int edit_contact_details(AddressBook *addressbook, int index)
{
    while(1)
    {
        printf("\nEditing Contact [%d]\n", index + 1);
        printf("Current Details:\n");
        printf("Name: %s\n", addressbook->contact_details[index].Name);
        printf("Phone: %s\n", addressbook->contact_details[index].Mobile_number);
        printf("Email: %s\n", addressbook->contact_details[index].Mail_ID);

        // Menu options for editing
        int count;
        int choice;
        printf("\nWhich detail do you want to edit?\n");
        printf("1. Name\n2. Mobile Number\n3. Email ID\n4. Edit All Details\n5. Exit\n");
        printf("Enter your choice (1 to 5): ");
        scanf(" %d", &choice);
        while (getchar() != '\n');   // clear newline
        switch(choice)
        {
            case 1:
            {
                while(1)
                {
                    char name[20];
                    printf("enter the new name\n");
                    scanf(" %[^\n]",name);
                    getchar();
                    if(!valid_name(name))
                    {
                        continue;
                    }
                    strcpy(addressbook->contact_details[index].Name,name);
                    break;
                }
            }
            break;

            case 2:
            {
                while(1)
                {
                    char mobilenumber[20];
                    printf("enter new mobile number\n");
                    scanf("%[^\n]",mobilenumber);
                    getchar();
                    if(!valid_mobile(mobilenumber))
                    {
                        continue;
                    }
                    if(!duplicate_mobile(mobilenumber,addressbook))
                    {
                        continue;
                    }
                    strcpy(addressbook->contact_details[index].Mobile_number,mobilenumber);
                    break;
                }
            }
            break;
            case 3:
            {

                while(1)
                {
                    char email_id[20];
                    printf("enter new Mail_ID: \n");
                    scanf(" %[^\n]",email_id);
                    getchar();
                    if(!valid_email(email_id))
                    {
                    continue;
                    }
                    if(!duplicate_email(email_id,addressbook))
                    {
                        continue;
                    }
                    strcpy(addressbook->contact_details[index].Mail_ID,email_id);
                    break;
                }

            }
            break;
            case 4:
            {
                while(1)
                {
                    char name[20];
                    printf("enter the new name\n");
                    scanf(" %[^\n]",name);
                    getchar();
                    if(!valid_name(name))
                    {
                          continue;
                    }
                    strcpy(addressbook->contact_details[index].Name,name);
                    break;
                }
                while(1)
                {
                    char mobilenumber[20];
                    printf("enter new mobile number\n");
                    scanf("%[^\n]",mobilenumber);
                    getchar();
                    if(!valid_mobile(mobilenumber))
                    {
                        continue;
                    }
                    if(!duplicate_mobile(mobilenumber,addressbook))
                    {
                        continue;
                    }
                    strcpy(addressbook->contact_details[index].Mobile_number,mobilenumber);
                    break;
                }
                while(1)
                {
                    char email_id[20];
                    printf("enter new Mail_ID: \n");
                    scanf(" %[^\n]",email_id);
                    getchar();
                    if(!valid_email(email_id))
                    {
                    continue;
                    }
                    if(!duplicate_email(email_id,addressbook))
                    {
                        continue;
                    }
                    strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,email_id);
                    break;

                }
                
            }
            break;
            case 5:
            printf("thank you\n");
            count=0;
            break;
        }
        if(count==0)
        break;
    }
}