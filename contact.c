#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    int count=0;
    do{
    printf("enter the name of contact:- ");
    scanf(" %[^\n]",addressBook->contacts->name);
    if((addressBook->contacts->name[0]>='a'&&addressBook->contacts->name[0]<='z')
      ||(addressBook->contacts->name[0]>='A'&&addressBook->contacts->name[0]<='Z')){
         count=0;
        do{
         printf("enter Phone number:-");
        scanf(" %[^\n]",addressBook->contacts->phone);
        
          if(addressBook->contacts->phone[0]>='6'&&addressBook->contacts->phone[0]<='9'){
            count=0;
            int i=0;
             while(addressBook->contacts->phone[i]!='\0'){
                  if(addressBook->contacts->phone[i]>='0'&&addressBook->contacts->phone[i]<='9'){
                    i++;
                  }
                  else{
                    printf("enter only digits\n");
                    count++;
                    break; 
                  }
             }
             if(i==10){
                //check for unique number
                printf("check for unique");

             }
             else{
                printf("enter phone number with 10 digits\n");
                count++;
             }
            
          }
          else{
            printf("enter the first digit range of 6 to 9\n");
            count++;
          }
       }while(count!=3);
        
    }

   else{
     printf("enter first character as alphabet\n");
        count++;
    }
}while(count!=3);


}
    


void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}
