#include <stdio.h>

    int main() {
       for(int i=0;i<10;i++){
        if(i==5){
            break;
        }
        printf("%d\n", i);
       }
    }


    if(res){
                int uniq=validate_unique_email(addressBook,email);
                if(uniq){
                  strcpy(addressBook->contacts[addressBook->contactCount].email,email);
                       printf("email is added\n");
                       addressBook->contactCount++;
                       *res2=1;
                }
                else{
                  printf("email is already exist\n");
                  *res2=0;
                }
              }
              else{
                *res2=0;
              }
            }
            else{
                printf("should contain only 1 @\n");
                *res2=0;
            }