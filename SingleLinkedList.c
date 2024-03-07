#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menampilkan isi linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fungsi untuk menambahkan node di awal linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi Memori Gagal.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Fungsi untuk menambahkan node di tengah linked list
void insertInMiddle(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi Memori Gagal.\n");
        exit(1);
    }
    newNode->data = data;
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Posisi invalid.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Fungsi untuk menambahkan node di akhir linked list
void insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Fungsi untuk menghapus node di awal linked list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Linked list Kosong.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Fungsi untuk menghapus node di akhir linked list
void deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("Linked list Kosong.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prevNode = NULL;
    while (temp->next != NULL) {
        prevNode = temp;
        temp = temp->next;
    }
    if (prevNode != NULL) {
        prevNode->next = NULL;
        free(temp);
    } else {
        free(head);
        head = NULL;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert in middle\n");
        printf("3. Insert at end\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert in middle: ");
                scanf("%d", &data);
                printf("Enter position to insert in middle: ");
                scanf("%d", &position);
                insertInMiddle(head, data, position);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(head, data);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                deleteAtEnd(head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
