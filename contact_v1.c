#include <stdio.h>
#include <cs50.h>
#include <string.h>

void swap(string *x, string *y);
int main(void)
{   
    int option;
    string name[100];
    string number[100];
    string email[100];
    char another;
    int count = 0;
    
    do
    {
        // taking input from user
        printf("Please select an option: \n");
        printf("1. Add a new contact\n");
        printf("2. Search contact\n");
        printf("3. View contacts\n");
        printf("4. Exit\n");
        
        option = get_int();
        
        // adding a new contact
        if (option == 1)
        {
            for (int i=0; i<100; i++)
            {
                printf("Name: ");
                name[i] = get_string();
                printf("Phone Number: ");
                number[i] = get_string();
                printf("Email: ");
                email[i] = get_string();
                
                printf("Contact saved.\n");
                count++;
                printf("Do you want to add another contact? ");
                another = get_char();
                
                if (another == 'n' || another == 'N')
                {
                    break;
                }
            }
        }
        // sorting the contacts
        int j=count-1;
        do
        {
            for(int i=0; i<j; i++)
            {
                if (strncmp(name[i], name[i+1], 1) > 0)
                {
                    swap(&name[i], &name[i+1]);
                    swap(&number[i], &number[i+1]);
                    swap(&email[i], &email[i+1]);
                }
            }
            j--;
        }
        while (j>0);
        
        
        
        // viewing the contacts
        if (option == 3)
        {
            printf("Name                    Number                  Email          \n");
            printf("---------------------------------------------------------------\n");
            for (int i=0; i<count; i++)
            {
                printf("%s              %s              %s              \n", name[i], number[i], email[i]);
            }
            
        }
        
        
        
        
    }
    while (option != 4);
    
}

void swap(string *x, string *y)
{
    string temp[1];
    temp[0] = *x;
    *x = *y;
    *y = temp[0];
}
