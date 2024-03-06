//Include Library
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//Define Size
#define size 3

//Deklarasi Struct
struct Barang
{
    char idItem[6];
    int stock;
};

//Prototype Function
void view(struct Barang *ptr);
void sell(struct Barang *ptr);
void add(struct Barang *ptr);


//Function Utama
int main()
{
    //Deklarasi Barang
    struct Barang arr[3];

    strcpy(arr[0].idItem, "ID001");
    arr[0].stock = 6;

    strcpy(arr[1].idItem, "ID002");
    arr[1].stock = 10;

    strcpy(arr[2].idItem, "ID003");
    arr[2].stock = 15;

    //Deklarasi var.input
    int input;

    //Menu Driven
    do
    {
        system("cls");
        printf("Menu\n");
        printf("====\n");
        printf("1. View Item\n");
        printf("2. Sell\n");
        printf("3. Add Stock\n");
        printf("4. Exit\n");
        printf("Input : ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                view(arr);
                printf("Press any button to continue...\n");
                getch();
                break;
            case 2:
                sell(arr);
                printf("Press any button to continue...\n");
                getch();
                break;
            case 3:
                add(arr);
                printf("Press any button to continue...\n");
                getch();
                break;
            case 4:
                printf("Thank You for Using This Program...\n");
                getch();
                break;
            default:
                printf("Invalid Input !\n");
                getch();
                break;
        }
    } while(input!=4);

    return 0;
}

void view(struct Barang *ptr)
{
    system("cls");
    printf("Nama Barang | Stock |\n");
    printf("======================\n");
    for(int i=0; i<size; i++)
    {
        printf("%-11s | %-5d |\n", ptr[i].idItem, ptr[i].stock);
        printf("======================\n");
    }
}

void sell(struct Barang *ptr)
{
    system("cls");
    char itemId[6];
    int quantity;

    printf("Enter the ID of the item to sell: ");
    scanf("%s", itemId);

    // Cari item dalam array
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(ptr[i].idItem, itemId) == 0)
        {
            index = i;
            break;
        }
    }

    //Kalau Item tidak ditemukan
    if (index == -1)
    {
        printf("Item not found!\n");
    }

    //Kalau item ditemukan
    else
    {
        printf("Enter the quantity to sell: ");
        scanf("%d", &quantity);

        if (quantity > ptr[index].stock)
        {
            printf("Not enough stock available!\n");
        }
        else
        {
            ptr[index].stock -= quantity;
            printf("Sold %d units of %s. New stock: %d\n", quantity, ptr[index].idItem, ptr[index].stock);
        }
    }
}

void add(struct Barang *ptr)
{
    system("cls");
    char itemId[6];
    int quantity;

    printf("Enter the ID of the item to add stock: ");
    scanf("%s", itemId);

    // Cari item dalam array
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(ptr[i].idItem, itemId) == 0)
        {
            index = i;
            break;
        }
    }

    //Kalau Item tidak ditemukan
    if (index == -1)
    {
        printf("Item not found!\n");
    }
    //Kalau item ditemukan
    else
    {
        printf("Enter the quantity to add stock: ");
        scanf("%d", &quantity);
        ptr[index].stock += quantity;
        printf("Add %d units of %s. New stock: %d\n", quantity, ptr[index].idItem, ptr[index].stock);
    }
}
