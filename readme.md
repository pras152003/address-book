# Address Book in C

A command-line Address Book project developed in C. The project was provided with a basic skeleton, and the functionality is being implemented step-by-step by developing and validating each block of the program.

## 1. Overall Program Flow

The `main()` function contains the main control flow of the Address Book.

- A `do-while` loop is used so that the menu runs at least once.
- The menu displays the available operations.
- A `switch` statement is used to select the operation based on the user's choice.
- The operations include creating, searching, editing, deleting, and listing contacts.

The functionality is being implemented one block at a time.

## 2. Create Contact

The first functionality implemented is `createContact()`.

The contact details are taken from the user and validated before accepting them.

The validation is currently implemented for:

1. Contact name
2. Phone number

Each validation block allows the user a maximum of three attempts.

The `count` variable is used to track the number of failed attempts.

## 3. Name Input and Validation

The contact name is taken using:

```c
scanf(" %[^\n]", addressBook->contacts->name);//space in scanf which skips newline left in input buffer