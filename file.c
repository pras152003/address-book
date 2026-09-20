#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fptr;
    fptr=fopen("file1.csv","w");

    if(fptr!=NULL){
    fprintf(fptr,"#%d\n",addressBook->contactCount);
    // fprintf(fptr,"%s%s%s %s\n", "contacts",   "Name", "Phone", "Email");
    for(int i=0;i<addressBook->contactCount;i++){
        fprintf(fptr,"%d, %s, %s, %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    }
    
    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook) {

    FILE *fptr;
    fptr = fopen("file1.csv", "r");

    if (fptr != NULL)
    {
       // char buffer[200];

        // Read contact count
        fscanf(fptr, "#%d\n", &addressBook->contactCount);
        // Read contacts
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            fscanf(fptr, "%*d, %[^,], %[^,], %[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }

        fclose(fptr);
    }
    else
    {
        printf("File could not be opened\n");
    }

}
