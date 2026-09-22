#include <stdio.h>
#include "contact.h"

int edit=0;
int duplicate=0;
int indexarr[100];
int index1=0;
int main() 
{
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book
   int count=0;
    do 
    {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save and Exit\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                //printf("%20s\n","----------------Search Contact----------------");
                searchContact(&addressBook,&edit,&duplicate,indexarr,&index1);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                
               // printf("Saving and Exiting...\n");
                saveAndExit(&addressBook);
                break;
            case 7:
                //printf("Exiting without saving...\n");
                exitfunction(&addressBook);
                
                break;    
            default:
                printf("Invalid choice. Please try again.\n");
                count++;//if we read any alpha going infinty times 
                break;
        }
    } while (count <= 6);
    
    
    return 0;
}
