#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 WELCOME THIS SMALL PROGRAM WILL CALCULATE BMI FOR ONE OR MORE PEOPLE
    There is a few option that are available
    1. Input new person [V]
    2. Sort by id [X]
    3. Save txt file of your results (can be also sorted by id) [X]
    4. Make dynamical table
    5. Sort by a few ids
*/

typedef struct PERSON
{
    int id;
    char *name;
    float weight;
    float height;
    float BMI;
} Person;

Person *NewId(Person *arr, int id);
void Table(int size, Person *arr);
Person *Sort(Person *arr, int id);
void WrongInput();

int main()
{
    Person *arr = NULL;
    int number = 1;
    while (1)
    {
        arr = NewId(arr,number);
        number++;
    }
    return 1;
}

// This function will create a new person in array
Person *NewId(Person *arr, int id)
{
    char buffer[100];
    int NameLen, len;

    // Allocate memory for new id
    Person *temp = (Person *)realloc(arr, id*sizeof(Person));
    if (temp == NULL)
    {
        printf("Not enough Memory");
        free(temp);
        exit(69);
    }

    // Check new position (assign ID)
    temp[id - 1].id = id;

    // Get name of person
    system("cls");
    printf("\nEnter name of person: ");
    fgets(buffer, sizeof(buffer), stdin);
    len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';

    temp[id - 1].name = (char *)malloc(len + 1);
    if (temp[id - 1].name == NULL)
    {
        printf("Not enough Memory");
        exit(69);
    }
    strcpy(temp[id - 1].name, buffer);

    // Get Weight and Height
    printf("\nEnter you Weight and Height in cm respectievly: ");
    for (int i = 0; i < 1;)
    {
        if (scanf("%f %f", &temp[id - 1].weight, &temp[id - 1].height) != 2)
        {
            WrongInput();
            temp[id - 1].weight = 0;
            temp[id - 1].height = 0;
            rewind(stdin);
        }
        else
            i++;
    }
    rewind(stdin);

    // Calculate BMI
    temp[id - 1].BMI = temp[id - 1].weight / pow((temp[id - 1].height / 100), 2);

    return temp;
}

// This function will print error if input is wrong
void WrongInput()
{
    printf("Wrong Input\n");
    printf("Please try again\n");
}

// This function will create table with buttons
void Table(int size, Person *arr)
{
    printf("+");
    for()
    printf("-")
}