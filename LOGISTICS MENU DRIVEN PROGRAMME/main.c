#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_CITY_LENGTH 50

int addCity(char cities[MAX_CITIES][MAX_CITY_LENGTH],int currentCityCount);
void renameCity(char cities[MAX_CITIES][MAX_CITY_LENGTH],int currentCityCount);
int removeCity(char cities[MAX_CITIES][MAX_CITY_LENGTH], int cityCount);


int main()

{
    char cities[MAX_CITIES][MAX_CITY_LENGTH];
    int currentCityCount=0;
    int choice;

    do
    {
        printf("\n===City Management===\n");
        printf("1.Add City\n");
        printf("2.Rename City\n");
        printf("3.Remove City\n");
        printf("4.Show Cities\n");
        printf("5.Input or Edit Distances\n");
        printf("6.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            currentCityCount=addCity(cities,currentCityCount);
            break;
        case 2:
            renameCity(cities,currentCityCount);
            break;
        case 3:
            currentCityCount = removeCity(cities, currentCityCount);
            break;
        case 4:
            for(int i=0; i<currentCityCount; i++)
            {
                printf("%d.%s\n",i+1,cities[i]);
            }
            break;
            case 5:
            return 0;
            break;
        default:
            printf("Invalid number");

        }



    }
    while(choice!=5);

    return 0;
}

int addCity(char cities[MAX_CITIES][MAX_CITY_LENGTH],int currentCityCount)
{

    int count=0;
    int i;

    printf("Enter city count:");
    scanf("%d",&count);
    for(i=0; i<count; i++)
    {
        printf("Enter the city name:");
        scanf("%s",cities[currentCityCount]);
        currentCityCount++;
    }
    return currentCityCount;
}
void renameCity(char cities[MAX_CITIES][MAX_CITY_LENGTH],int currentCityCount)
{
    {
        if(currentCityCount==0)
        {
            printf("No cities available\n");
            return;
        }
        int index;
        char newCity[50];
        printf("Enter the city number:",currentCityCount);
        scanf("%d",&index);
        if(index<1||index>currentCityCount)
        {
            printf("Invalid city number\n");
            return;
        }
        printf("Enter new city name:");
        scanf("%s",newCity);
        printf("City '%s' renamed to '%s'\n",cities[index-1],newCity);
        strcpy(cities[index-1],newCity);
    }
}

int removeCity(char cities[MAX_CITIES][MAX_CITY_LENGTH], int currentCityCount)
{
    int index;
    printf("Enter remove city index:");
    scanf("%d",&index);
    printf("City '%s' removed\n",cities[index-1]);
    for (int i=index-1; i<currentCityCount-1; i++)
    {
        strcpy(cities[i],cities[i+1]);
    }
    return currentCityCount - 1;
}




