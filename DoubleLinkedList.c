//Deklarasi Library
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Deklarasi Tipe Variabel Struct
struct Node
{
    //data
    int data;

    //struct pointer
    struct Node *next;
    struct Node *prev;
};

//Fungsi masukkan data dari depan
void insertHead(struct Node **head, struct Node **tail, int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
    }
}

//Fungsi masukkan data dari belakang
void insertTail(struct Node **head, struct Node **tail, int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*head==NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

//Fungsi hapus data dari depan
void deleteHead(struct Node **head)
{
    if(*head == NULL)
    {
        printf("there is no data...!\n");
        return;
    }
    else
    {
        if((*head)->next!=NULL)
        {
            (*head)->next->prev = NULL;
        }
        struct Node *ptr = *head;
        *head=ptr->next;
        free(ptr);
    }
    printf("Hapus data berhasil...!\n");
}

//Fungsi hapus data dari belakang
void deleteTail(struct Node **tail)
{
    if(*tail == NULL)
    {
        printf("there is no data...!\n");
        return;
    }
    else
    {
        if((*tail)->prev!=NULL)
        {
            (*tail)->prev->next = NULL;
        }
        struct Node *ptr = *tail;
        *tail=ptr->prev;
        free(ptr);
    }
    printf("Hapus data berhasil...!\n");
}

//Fungsi lihat data
void view(struct Node **head)
{
    struct Node *ptr = *head;
    while(ptr!=NULL)
    {
        printf("| %d | -> ", ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

//Fungsi Utama
int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int num;

    int input;
    do
    {
        system("cls");
        printf("Menu Double Linked List\n");
        printf("=======================\n");
        printf("1. View Data\n");
        printf("2. Input Head\n");
        printf("3. Input Tail\n");
        printf("4. Delete Head\n");
        printf("5. Delete Tail\n");
        printf("6. Exit\n");
        printf("Input >> ");
        scanf("%d", &input);

        switch(input)
        {
            case 1:
                view(&head);
                printf("Press any button to continue...\n");
                getch();
                break;
            case 2:
                printf("Masukkan angka : ");
                scanf("%d", &num);
                insertHead(&head,&tail,num);
                printf("Press any button to continue...\n");
                getch();
                break;
            case 3:
                printf("Masukkan angka : ");
                scanf("%d", &num);
                insertTail(&head,&tail,num);
                printf("Press any button to continue...\n");
                getch();
                break;
            case 4:
                deleteHead(&head);
                printf("Press any button to continue...\n");
                getch();
                break;
            case 5:
                deleteTail(&tail);
                if(tail==NULL)
                {
                    head=tail;
                }
                printf("Press any button to continue...\n");
                getch();
                break;
            case 6:
                printf("Thanks for using this program!\n");
                getch();
                break;
            default:
                printf("Invalid input...!\n");
                getch();
                break;
        }
    } while(input!=6);

    return 0;
}
