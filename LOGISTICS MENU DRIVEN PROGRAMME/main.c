#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_CITY_LENGTH 50
#define MAX_DELIVERIES 100
#define FUEL_PRICE 450.0

typedef struct {
    int source;
    int destination;
    int vehicleType;
    float weight;
} Delivery;

void manageCities(char cities[MAX_CITIES][MAX_CITY_LENGTH], int*currentCityCount);
int addCity(char cities[MAX_CITIES][MAX_CITY_LENGTH],int currentCityCount);
void renameCity(char cities[MAX_CITIES][MAX_CITY_LENGTH],int currentCityCount);
int removeCity(char cities[MAX_CITIES][MAX_CITY_LENGTH], int cityCount);
void manageDistances(int distance[MAX_CITIES][MAX_CITIES], char cities[MAX_CITIES][MAX_CITY_LENGTH], int currentCityCount);
void inputDistances(int distance[MAX_CITIES][MAX_CITIES],char cities[MAX_CITIES][MAX_CITY_LENGTH],int currentCityCount);
void displayDistances(int distance[MAX_CITIES][MAX_CITIES],char cities[MAX_CITIES][MAX_CITY_LENGTH],int currentCityCount);
void manageVehicles(char vehicleType[3][20], int capacity[3], float ratePerKm[3], float avgSpeed[3], float fuelEfficiency[3]);
void displayVehicles(char vehicleType[3][20], int capacity[3], float ratePerKm[3], float avgSpeed[3], float fuelEfficiency[3]);
void handleDeliveries(Delivery deliveries[], int *deliveryCount, int currentCityCount,int capacity[], char cities[][50], char vehicleType[][20],int distances[][MAX_CITIES], float ratePerKm[], float avgSpeed[], float fuelEfficiency[]);
void createDelivery(Delivery deliveries[],int *deliveryCount,int currentCityCount,int capacity[],char cities[][50],char vehicleType[][20],int distances[][MAX_CITIES],float ratePerKm[],float avgSpeed[],float fuelEfficiency[]);
void displayDeliveries(Delivery deliveries[], int deliveryCount, char cities[][50], char vehicleType[][20]);






int main()
{

    char cities[MAX_CITIES][MAX_CITY_LENGTH];
    int currentCityCount=0;
    int choice;
    int distance[MAX_CITIES][MAX_CITIES] = {0};
    char vehicleType[3][20]= {"Van","Truck","Lorry"};
    int capacity[3]= {1000,5000,10000};
    float ratePerKm[3]= {30.0,40.0,80.0};
    float avgSpeed[3]= {60.0,50.0,45.0};
    float fuelEfficiency[3]= {12.0,6.0,4.0};
    Delivery deliveries[MAX_DELIVERIES];
    int deliveryCount = 0;


do
    {
        printf("\n=========================================\n");
        printf("LOGISTICS MANAGEMENT SYSTEM\n");
        printf("\n=========================================\n");
        printf("1.City Management\n");
        printf("2.Distance Management\n");
        printf("3.Vehicle Management\n");
        printf("4.Delivery Request Handling\n");
        printf("5.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            manageCities(cities,&currentCityCount);
            break;
        case 2:
            manageDistances(distance,cities,currentCityCount);
            break;
        case 3:
            manageVehicles(vehicleType,capacity,ratePerKm,avgSpeed,fuelEfficiency);
            break;
            case 4:
            handleDeliveries(deliveries,&deliveryCount,currentCityCount,capacity,cities,vehicleType,distance,ratePerKm,avgSpeed,fuelEfficiency);
break;
        case 5:
            printf("Exiting program...\n");
            break;
            return 0;

        default:
            printf("Invalid number\n");

        }



    }
    while(choice!=5);

    return 0;
}
void manageCities(char cities[MAX_CITIES][MAX_CITY_LENGTH],int *currentCityCount)
{
    int choice;
    do
    {
        printf("\n--- City Management ---\n");
        printf("1. Add City\n");
        printf("2. Rename City\n");
        printf("3. Remove City\n");
        printf("4. Display Cities\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            *currentCityCount = addCity(cities, *currentCityCount);
            break;
        case 2:
            renameCity(cities, *currentCityCount);
            break;
        case 3:
            *currentCityCount = removeCity(cities, *currentCityCount);
            break;
        case 4:
            for (int i=0; i<*currentCityCount; i++)
            {
                printf("%d.%s\n",i +1,cities[i]);
            }
            break;
        case 5:
            break;
        default:
            printf("Invalid number\n");
        }
    }
    while (choice != 5);


}

int addCity(char cities[MAX_CITIES][MAX_CITY_LENGTH], int currentCityCount)

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
void manageDistances(int distance[MAX_CITIES][MAX_CITIES], char cities[MAX_CITIES][MAX_CITY_LENGTH], int currentCityCount)
{

    int choice;
    do
    {
        printf("\n--- Distance Management ---\n");
        printf("1.Input/Edit Distance\n");
        printf("2.Display Distance Table\n");
        printf("3.Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputDistances(distance,cities,currentCityCount);
            break;
        case 2:
            displayDistances(distance,cities,currentCityCount);
            break;
        case 3:
            break;
        default:
            printf("Invalid number\n");
        }
    }
    while (choice != 3);
}

void inputDistances(int distance[MAX_CITIES][MAX_CITIES],char cities[MAX_CITIES][MAX_CITY_LENGTH],int currentCityCount)
{
    int city1,city2,dist;

    printf("Show cities:\n");
    for(int i=0; i<currentCityCount; i++)
    {
        printf("%d.%s\n",i+1,cities[i]);
    }
    printf("Enter first city number:");
    scanf("%d",&city1);
    printf("Enter second city number:");
    scanf("%d",&city2);

    if(city1<1||city1>currentCityCount||city2<1||city2>currentCityCount)
    {
        printf("Invalid city numbers\n");
        return;
    }

    if(city1==city2)
    {
        printf("Distance between same city is always 0\n");
        return;
    }

    printf("Enter distance between %s and %s(km):",cities[city1-1],cities[city2-1]);
    scanf("%d",&dist);

    distance[city1-1][city2-1]=dist;
    distance[city2-1][city1-1]=dist;
    printf("Input the distances successfully");
}
void displayDistances(int distance[MAX_CITIES][MAX_CITIES],char cities[MAX_CITIES][MAX_CITY_LENGTH],int currentCityCount)
{
    if(currentCityCount==0)
    {
        printf("No cities available\n");
        return;
    }
    printf("\nDistance Table(km):\n\t");
    for(int i=0; i<currentCityCount; i++)
        printf("\t%s\t",cities[i]);
    printf("\n");
    for(int i=0; i<currentCityCount; i++)
    {
        printf("%s\t\t",cities[i]);
        for(int j=0; j<currentCityCount; j++)
            printf("%d\t\t",distance[i][j]);

        printf("\n");

    }

}

void manageVehicles(char vehicleType[3][20],int capacity[3], float ratePerKm[3], float avgSpeed[3], float fuelEfficiency[3])
{
    int choice;
    do
    {
        printf("\n--- Vehicle Management ---\n");
        printf("1.View vehicle details\n");
        printf("2.Back to main\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayVehicles(vehicleType,capacity,ratePerKm,avgSpeed,fuelEfficiency);
            break;
        case 2:
            break;
        default:
            printf("Invalid number\n");
        }
    }
    while (choice != 2);
}

void displayVehicles(char vehicleType[3][20], int capacity[3], float ratePerKm[3], float avgSpeed[3], float fuelEfficiency[3])
{
    printf("\n---Vehicle Types---\nType\tCapacity(kg)\tRate/km(LKR)\tSpeed(km/h)\tFuelEff(km/l)\n");
    for(int i = 0; i < 3; i++)
        printf("%d.%s\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n",i+1,vehicleType[i],capacity[i],ratePerKm[i],avgSpeed[i],fuelEfficiency[i]);
}
void handleDeliveries(Delivery deliveries[], int *deliveryCount, int currentCityCount,
                      int capacity[], char cities[][50], char vehicleType[][20],
                      int distances[][MAX_CITIES], float ratePerKm[], float avgSpeed[], float fuelEfficiency[]) {
    int choice;

    do {
        printf("\n--- Delivery Request Handling ---\n");
        printf("1. Create New Delivery Request\n");
        printf("2. View All Deliveries\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                createDelivery(deliveries, deliveryCount, currentCityCount, capacity, cities, vehicleType, distances, ratePerKm, avgSpeed, fuelEfficiency);
              break;
            case 2:
                displayDeliveries(deliveries,*deliveryCount,cities,vehicleType);
            break;
            case 3:
                printf("Returning to main");
                break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 3);
}

void createDelivery(Delivery deliveries[], int *deliveryCount, int currentCityCount, int capacity[], char cities[][50], char vehicleType[][20], int distances[][MAX_CITIES], float ratePerKm[], float avgSpeed[], float fuelEfficiency[]){
    if(currentCityCount<2){
        printf("Please add at least two cities first.\n");
        return;
    }
    if(*deliveryCount>=MAX_DELIVERIES){
        printf("Delivery record limit reached.\n");
        return;
    }

    int s,d;
    printf("Enter source city number: ");
    scanf("%d",&s);
    printf("Enter destination city number: ");
    scanf("%d",&d);
    if(s==d) {
        printf("Source and destination cannot be the same.\n");
        return;
    }


    if(s < 1 || s > currentCityCount|| d < 1 || d > currentCityCount) {
        printf("Invalid city numbers.\n");
        return;
    }

    displayVehicles(vehicleType,capacity,ratePerKm,avgSpeed,fuelEfficiency);
    int v;
    printf("Select vehicle type: ");
    scanf("%d", &v);
    if(v < 1 || v > 3) {
        printf("Invalid vehicle type.\n");
        return;
    }

    float weight;
    printf("Enter weight (kg): ");
    scanf("%f", &weight);
    if(weight > capacity[v-1]) {
        printf("Weight exceeds vehicle capacity of %d kg.\n", capacity[v-1]);
        return;
    }

    deliveries[*deliveryCount].source = s - 1;
    deliveries[*deliveryCount].destination = d - 1;
    deliveries[*deliveryCount].vehicleType = v - 1;
    deliveries[*deliveryCount].weight = weight;
    (*deliveryCount)++;

    printf("\nDelivery order added successfully!\n");

}

void displayDeliveries(Delivery deliveries[], int deliveryCount, char cities[][50], char vehicleType[][20]){
    if(deliveryCount == 0) {
        printf("No deliveries yet.\n");
        return;
    }
    printf("\n--- Delivery Records ---\n");
    for(int i = 0; i < deliveryCount; i++) {
        printf("%d. From %s to %s | Vehicle: %s | Weight: %.2f kg\n",
               i + 1, cities[deliveries[i].source], cities[deliveries[i].destination],vehicleType[deliveries[i].vehicleType], deliveries[i].weight);
    }
}






