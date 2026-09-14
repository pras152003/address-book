#include <stdio.h>
#include <string.h>


int get_domain(char *email,int n);
int main(){
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
                printf("save email\n");
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
}while(count<=3);
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