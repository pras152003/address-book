read me

 -->>   using do while loop for atleast run once to show menu for input fields or selection of menu
-->>    using of selective scanf( %[^\n])  to read spaces if thier in name and for avoiding            newline character living space


---------------create contact-------------
->> enter name through user
    1. before moving to get phone number validate it should start with alpabet or digit not any special characters
 
     3 chances for user to enter correct name

-->> phone number input and validation 
     1. it should start with 6/7/8/9
     2. contains 10 digits only not other characters
     3. unique phone number
      again 3 chances 


-->>  email input and validation
     first char should be lower alpa or digit
     should not contain an upper case through out email id
     should contain @ .com once 
     '.' should come after '@'
     unique email id
    no special characters expect @ '.'

--------------save contact and increse count-----------

------------------search count-----------

-->>   3 ways to search contact    common function where we use in edit and delete to search contact
   searching contact with validation
      by name
             if any duplicates list all macthing contacts
      by phone   
      by email


-->>edit contact 
     search by name phone email
     edit phone/name/email
     validation every field before updating
     update contact
    
-->>  delete contact
     search by name phone email
     confirmation of delete and swap next contact to pre one and reduce contact size

-->> saving file to csv file     comma separtor value
    csv act as buffer clearing in when we use multiple selctive scanf creates buffer

    save contact to file through fprintf  "w"   

    load through fprintf
