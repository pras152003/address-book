#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    printf("------------List of Contacts--------- \n");
    printf("%-10s %-20s %s\n", "Name", "Phone", "Email");
    for(int i=0;i<addressBook->contactCount;i++){
      printf("%-10s %-20s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

 void get_phone(AddressBook *addressBook,char *phone);
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char name[50];
    char phone[20];
    char email[50];
   int count=0;
   do{
    printf("Enter name: ");
    scanf(" %[^\n]",name);
    if((name[0]>='A'&&name[0]<='Z')||(name[0]>='a'&&name[0]<='z')){
      strcpy(addressBook->contacts[addressBook->contactCount].name,name);
      get_phone(addressBook,phone);
       
       break;
    }
    else{
      printf("first character should be alphabet\n");
      count++;
    }
  }while(count<3);
      
    
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

int get_validate(AddressBook *addressBook,char *phone);
void get_email(AddressBook *addressBook,char *email);
void get_phone(AddressBook *addressBook,char *phone){
  char email[50];
  int count=0;
    printf("------------phone number--------- \n");
    printf("            should be start with 6,7,8,9\n");
    printf("            should contain 10 digit only not a single other charcater\n");
  do{
    printf("enter phone number :-");
    scanf(" %[^\n]", phone);
        if(phone[0]>='6'&&phone[0]<='9'){//start with 6/7/8/9
         int i=0;
          while(phone[i]!='\0')
          {    
                if(phone[i]>='0'&&phone[i]<='9'){  //checks numbers character and counts
                   i++;
                 }
                 else{
                    count++;
                  printf("should contain only digits\n");
                    break;
                  
                 }
                }

                 if(i!=10){
                    count++;
                    printf("should contain 10 digit only\n");

                 }
                else{
                     int res= get_validate(addressBook,phone);
                     if(res){
                       strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
                       printf("phone number is added\n");
                       get_email(addressBook,email);
                       break;
                     }
                     else{
                      count++;
                      printf("phone number is matched\n");
                     }
                 }
                }
        else{
          count++;
          printf("should start with 6/7/8/9\n");
        }
  }while(count<3);

}

int get_validate(AddressBook *addressBook,char *phone){
      int flag=1;//comparing any existing phone number
      for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].phone,phone)==0){
          flag=0;
          break;
        }
        else{
          flag;
        }

      }
      return flag;
    

}

//void get_domain(AddressBook *addressBook,char *email,int *count);
int get_domain(char *email,int n);
int validate_unique_email(AddressBook *addressBook,char *email);
void get_email(AddressBook *addressBook,char *email){
    int count=0;
    do{
    char email[50]; 
    printf("enter the email details:- ");                
    scanf(" %s", email);         
    if(email[0]>='a'&&email[0]<='z'||email[0]>='0'&&email[0]<='9'){//check first charcacter
        int i=1;
        int flag=1;                                        //check for first charcter
        while(email[i]!='\0'){                      
             if(!(email[i]>='A'&&email[i]<='Z')){        //email should not contain any uppercase
               flag=1;
               i++;
             }
             else{
                printf("email should not contain upper case\n");
                count++;
                break;
             }
        }
        if(flag==1){                                    //now whole array not with any upper case
            int atcount=0; // traverse whole string to count @
            int atposition;
            int i=0;                                                        
            while(email[i]!='\0'){
                if(email[i]=='@'){
                    atcount++;
                    atposition = i;
                    i++;
                }
                else{
                    i++;
                }
            }
            if(atcount==1){        //check for .com             
              int res=get_domain(email,atposition);
              if(res){
                int uniq=validate_unique_email(addressBook,email);
                if(uniq){
                  strcpy(addressBook->contacts[addressBook->contactCount].email,email);
                       printf("email is added\n");
                       addressBook->contactCount++;
                       return;
                }
                else{
                  printf("email is already exist\n");
                  count++;
                }
              }
              else{
                count++;
              }
            }
            else{
                printf("should contain only 1 @\n");
                count++;
            }

        }
    }
    else{
        count++;
        printf("first charc either lower case or digit\n");
    }
}while(count<3);
}


int get_domain(char *email,int n){

     int atdotcom=0;
     
     char *ptr=email;
     while((ptr=strstr(ptr,".com"))!=NULL){//!=NULL .com is present
         atdotcom++;

         ptr++;
     }
     
      
     if(atdotcom==1){
        int i=n+1;//i points to 1 point after @
        int charc=0;
        while(email[i]!='.'){
            charc++;
            i++;
        }
        if(charc>=5){
            return 1;
        }
        else{
            printf("invalid domain\n");
            return 0;
            
        }
     }
     else if(atdotcom>1){
        printf("should not contain more than 1 .com\n");
        return 0;
     }
     else{
        printf("should contain atleast 1 .com\n");
        return 0;
     }

    }

    int validate_unique_email(AddressBook *addressBook,char *email){
      
      int flag=1;//comparing any existing phone number
      for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].email,email)==0){
          flag=0;
          break;
        }
        else{
          flag;
        }

      }
      return flag;
    }





