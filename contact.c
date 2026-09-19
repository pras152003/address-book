#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

//dispalying contacts
void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    printf("------------List of Contacts--------- \n");
    printf("%-10s %-10s %-20s %s\n", "contacts",  "Name", "Phone", "Email");
    for(int i=0;i<addressBook->contactCount;i++){
      printf("%-10d %-10s %-20s %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
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
void get_validatename(AddressBook *addressBook,char *name,int *res);
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
    int res=0;
    get_validatename(addressBook,name,&res);
    if(res!=0){
      strcpy(addressBook->contacts[addressBook->contactCount].name,name);
      get_phone(addressBook,phone);
      return;

    }
    else{
      count++;
    }

    
  }while(count<3);
      
    
}
    
//name validation
void get_validatename(AddressBook *addressBook,char *name,int *res){
            int i=0;
            if((name[0]>='A'&&name[0]<='Z')||(name[0]>='a'&&name[0]<='z')){
              *res=1;
              return;
            }
            else{
              printf("first character should be alpha\n");
              *res=0;
              return ;
            }
}

//phone number validation
void get_validatephone(AddressBook *addressBook,char *phone,int *res1){

  if(phone[0]>='6'&&phone[0]<='9'){//start with 6/7/8/9
         int i=0;
          while(phone[i]!='\0')
                {    
                if(phone[i]>='0'&&phone[i]<='9'){  //checks numbers character and counts
                   i++;
                 }
                 else{
                  printf("should contain only digits\n");
                   *res1=0;
                   return;
                 }
                }
                if(i==10){
                  *res1=1;
                  return;
                }
                else{
                  printf("should contain exactly 10 digits\n");
                  *res1=0;
                  return;
                }

     }
     else{
      printf("should start with 6/7/8/9\n");
      *res1=0;
      return;
     }
}

int get_validate(AddressBook *addressBook,char *phone);
void get_email(AddressBook *addressBook,char *email);
void get_phone(AddressBook *addressBook,char *phone){
  char email[50];
  int count=0;
    printf("------------phone number--------- \n");
    printf("%39s\n","should be start with 6/7/8/9");
    printf("%46s\n","should contain 10 digits only (0-9)");
  do{
    printf("enter phone number :-");
    scanf(" %[^\n]", phone);
             int res1=0;
             get_validatephone(addressBook,phone,&res1);//checking phone number consist digit only and counting
             if(res1==0){
             count++;
             continue;
               }
                else{
                     int res= get_validate(addressBook,phone);//check unique
                     if(res){
                       strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
                       printf("phone number is added\n");
                       get_email(addressBook,email);
                       return;
                     }
                     else{
                      count++;
                      printf("phone number is matched\n");
                     }
                 }
                
        
  }while(count<3);
}



int get_validate(AddressBook *addressBook,char *phone){
      int flag=1;//comparing any existing phone number
      for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].phone,phone)==0){
          flag=0;//phone number is matching
          break;
        }
        else{
          flag;
        }

      }
      return flag;
    

}
void get_domain(char *email,int n,int *res);
int validate_unique_email(AddressBook *addressBook,char *email);
void get_validateemail(AddressBook *addressBook,char *email,int *res2){
        int i=0;
        if(email[0]>='a'&&email[0]<='z'||email[0]>='0'&&email[0]<='9'){//check first charcacter
        int flag=1;                                        //check for first charcter
        while(email[i]!='\0'){                      
             if(!(email[i]>='A'&&email[i]<='Z')){        //email should not contain any uppercase
               flag=1;
               i++;
             }
             else{
                printf("email should not contain upper case\n");
                *res2=0;
                return;
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
              int atdotcom=0;
              char *ptr=email;
              while((ptr=strstr(ptr,".com"))!=NULL){//!=NULL .com is present
                atdotcom++;
                ptr++;
                 }
    
                  if(atdotcom==1){
                 int i=atposition+1;//i points to 1 point after @
                  int charc=0;
                  while(email[i]!='.'){
                  charc++;
                  i++;
                  }
                  if(charc>=5){
                  *res2=1;
                  return;
                    }
              else{
                  printf("invalid domain\n");
                      *res2=0;
                  return;
            
                 }
                }
              else if(atdotcom>1){
                printf("should not contain more than 1 .com\n");
                  *res2=0;
              return;
              }
            else{
              printf("should contain atleast 1 .com\n");
            *res2=0;
              return;
     }
               }
               else if(atcount>1){
                printf("1 @ only alowed\n");
                *res2=0;
                return;
               }
               else{
                printf("should contain atleast 1 @ \n");
                *res2=0;
                return;
               }
    }
    else{
        *res2=0;
        printf("first charc either lower case or digit\n");
    }
  }
  else{
    printf("first character should be lower alpha or digit\n");
    *res2=0;
    
  }
  return;
}


//void get_domain(AddressBook *addressBook,char *email,int *count);

void get_email(AddressBook *addressBook,char *email){
    int count=0;
    printf("------------email--------- \n");
    printf("%58s\n","first character should be lower case or digit");
    printf("%46s\n","should not contain any upper case");
    printf("%47s\n","should contain only 1 @ and 1 .com");
    do{
    char email[50]; 
    printf("enter the email details:- ");                
    scanf(" %s", email); 
                     int res2=0;
                     get_validateemail(addressBook,email,&res2);
                     if(res2==0){
                      count++;
                     }
                     else{
                      int uniq=validate_unique_email(addressBook,email);
                      if(uniq){
                      strcpy(addressBook->contacts[addressBook->contactCount].email,email);
                       printf("email is added\n");
                       addressBook->contactCount++;
                       printf("%80s","KUDOS--to u--Your contact sucessfully added to addressbook\n");
                       return;
                       } 
                    else{
                      printf("email is already exist\n");
                      return;
                }
              }
              
                      
                       
                                      
}while(count<3);
}


int validate_unique_email(AddressBook *addressBook,char *email){
      
      int flag=1;//comparing any existing email number
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

void searchContact(AddressBook *addressBook,int *edit,int *index1,int *duplicate) 
{
    /* Define the logic for search */
    char name[50];
    char phone[50];
    char email[50];
     int count=0;
    do{
      printf("%20s\n","----------------Search Contact----------------");
      printf("%39s\n","by name enter 1");
      printf("%40s\n","by phone enter 2");
      printf("%40s\n","by email enter 3");
      int num;
      printf("enter your choice:- \n");
      scanf("%d",&num);
      switch(num){
        case 1:
               do{
               printf("Enter name: ");
               scanf(" %[^\n]",name);
               int res=0;
               
               get_validatename(addressBook,name,&res);
               int no=1;
               int i=0;
                if(res!=0){
              
                  int found=0;
                  for(int i=0;i<addressBook->contactCount;i++){
                    if(strstr(addressBook->contacts[i].name,name)!=NULL)
                    {
                      found=1;
                    }
                  }
                  if(found==1){
                    printf("%20s\n","----------------List of Contacts-------------");
                   printf("%10s %10s %20s %20s %15s\n", "serial no","index" , "Name", "Phone", "Email");
                    for(int i=0;i<addressBook->contactCount;i++){
                    if(strstr(addressBook->contacts[i].name,name)!=NULL){
                    printf("%10d %10d %20s %20s %30s\n",i+1,i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
           
                    *edit=1;//search contact is founded next is to edit
                    *index1=i;// it returning the index not serial number index=serial-1
                     (*duplicate)++;
                }
               
              }
              return;
            }
                  else{
                    printf("contact not found\n");
                    count++;
                  //break;
                  }
                
               // return;
                }
                else{
                  count++;
                }
            
              }while(count<3);
              break;
        case 2:
        do{
             printf("enter phone number\n");
             scanf(" %[^\n]",phone);
             int res1=0;
             get_validatephone(addressBook,phone,&res1);
             if(res1==0){
             count++;
             continue;
               }
                else{
                     for(int i=0;i<addressBook->contactCount;i++){
                     if(strstr(addressBook->contacts[i].phone,phone)!=NULL){
                    printf("------------List of Contacts--------- \n");
                    printf("%10s %10s %20s %15s\n", "contacts",  "Name", "Phone", "Email");
                    printf("%10d %10s %20s %30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                     *edit=1;
                  }
                  else{
                    printf("contact not found\n");
                    count++;
                    return;
                  }
                }
                 return;
              }
            }while(count<3);
            break;
      
        case 3:
        do{
             printf("enter email want to search:- \n");
             scanf(" %[^\n]",email);
             int res2=0;
             get_validateemail(addressBook,email,&res2);
             if(res2==0){
              count++;
              continue;
             }
             else{
                     for(int i=0;i<addressBook->contactCount;i++){
                     if(strstr(addressBook->contacts[i].email,email)!=NULL){
                    printf("------------List of Contacts--------- \n");
                    printf("%10s %10s %20s %15s\n", "contacts",  "Name", "Phone", "Email");
                    printf("%10d %10s %20s %30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                     break;
                  }
                  else{
                    printf("contact not found\n");
                    count++;
                    return;
                  }
                }
                return; 
              }
            }while(count<3);
           break;
        default:
            printf("invalid choice\n");
            count++;
            break;
             
              }        
             } while(count<1);
}

void editContact(AddressBook *addressBook)
{ /* Define the logic for Editcontact */
  char name[50];
  char phone[50];
  char email[50];
   int edit=0;
   int count=0;
   int index1=0;
   int duplicate=0;
  searchContact(addressBook,&edit,&index1,&duplicate); 
  do{
  if(edit==1){
    printf("\n");
    printf("----you can see list of contacts choose which field u want to update \n");
    printf("%50s\n","name         -- choice--1");
    printf("%50s\n","phone number ---choice--2");
    printf("%50s\n","email id     ---choice--3");
    int num;
    int res=0;
    printf("enter your choice:-\n");
    scanf("%d",&num);
    switch(num){             //updgradation section
          case 1:
               if(duplicate>1){
                printf("there are duplicates contacts with name\n");
                printf("enter index to update:-\n");
                scanf("%d",&index1);
                printf("enter the name to update:-\n");
                scanf(" %[^\n]",name);
               get_validatename(addressBook,name,&res);//check entered name is valid or not 
               if(res==1){
               strcpy(addressBook->contacts[index1].name,name);
               printf("successfully contact updated\n");
                }
               else{
                count++;
               }
              }
              else{
                printf("enter the name to update:-\n");
                scanf(" %[^\n]",name);
               get_validatename(addressBook,name,&res);//check entered name is valid or not 
               if(res==1){
                strcpy(addressBook->contacts[index1].name,name);
                  printf("successfully contact updated\n");
               }
               else{
                count++;
               }
              }
               return;
          case 2:
              printf("enter the phone number to update:-\n");
              scanf(" %[^\n]",phone);
              get_validatephone(addressBook,phone,&res);//here validating entered phone number
              if(res==1){
             int res=get_validate(addressBook,phone);
             if(res){
                printf("enter index to update:- \n");
                scanf("%d",&index1);
               strcpy(addressBook->contacts[index1-1].phone,phone);
              printf("successfully contact updated\n");
                }
                else{
                  strcpy(addressBook->contacts[index1].phone,phone);
                  printf("successfully contact updated\n");
                }
              return;
              }
              else{
                count++;
              }
              return;
             break;
          case 3:
           printf("email edit\n");
           break;
          
           default :
           count++;
            printf("invalid input\n");
            break;
    }
         
  }
  else{
    count++;
  }
   
}while(count<3);
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}









