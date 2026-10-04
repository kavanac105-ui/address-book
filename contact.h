#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#include<string.h>
#include<ctype.h>
/* Structure definitions */
typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;

typedef struct AddressBook_Data
{
    Contacts contact_details[100];
    int contact_count;
} AddressBook;

/* Function declarations */
// void init_intitalization(AddressBook *);
int create_contact(AddressBook *);
void list_contacts(AddressBook *);
int search_contacts(AddressBook *);
int edit_contact(AddressBook *);
int delete_contact(AddressBook *);
int save_contacts(AddressBook *);
int save_and_exit(AddressBook *);
int valid_mobile(char *mobilenumber);
int valid_email(char *email_id);
int valid_name(char *name);
int duplicate_mobile(char *mobilenumber,AddressBook *addressbook);
int duplicate_email(char *email_id,AddressBook *addressbook);
int load_contact_file(AddressBook *addressbook);
int edit_contact_details(AddressBook *addressbook,int index);
#endif // CONTACT_H
       // CONTACT_H
