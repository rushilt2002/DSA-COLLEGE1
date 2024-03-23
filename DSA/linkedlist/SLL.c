#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addAtBeg(struct node **head, int);
void addAtEnd(struct node **head, int);
int deleteAtBeg(struct node **head);
int deleteAtEnd(struct node **head);
void display(struct node *);

void saveToFile(struct node *head);
struct node *readFromFile();

int main() {
    struct node *head = NULL;
    int e, ch;

    head = readFromFile(); // Read data from file

    while (1) {
        printf("1.add at beg\n");
        printf("2.add at end\n");
        printf("3.delete at beg\n");
        printf("4.delete at end\n");
        printf("5.display\n");
        printf("6.save to file\n");
        printf("7.exit\n");

        printf("enter choice\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("enter e\n");
                scanf("%d", &e);
                addAtBeg(&head, e);
                break;

            case 2:
                printf("enter e\n");
                scanf("%d", &e);
                addAtEnd(&head, e);
                break;

            case 3:
                if (head == NULL) {
                    printf("list empty");
                    break;
                }
                e = deleteAtBeg(&head);
                printf("%d\n", e);
                break;

            case 4:
                if (head == NULL) {
                    printf("list empty");
                    break;
                }
                e = deleteAtEnd(&head);
                printf("%d\n", e);
                break;

            case 5:
                if (head == NULL) {
                    printf("list empty");
                    break;
                }
                display(head);
                break;

            case 6:
                saveToFile(head);
                printf("Data saved to file.\n");
                break;

            case 7:
                saveToFile(head); // Save data before exit
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void addAtBeg(struct node **head, int e) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = e;
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(struct node **head, int e) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = e;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int deleteAtBeg(struct node **head) {
    int e;
    struct node *temp = *head;

    e = temp->data;
    *head = temp->next;
    free(temp);
    return e;
}

int deleteAtEnd(struct node **head) {
    int e;
    struct node *temp = *head;
    struct node *prev = NULL;

    if (temp->next == NULL) {
        e = temp->data;
        free(temp);
        *head = NULL;
        return e;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    e = temp->data;
    prev->next = NULL;
    free(temp);
    return e;
}

void display(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void saveToFile(struct node *head) {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct node *current = head;
    while (current != NULL) {
        fprintf(file, "%d\n", current->data);
        current = current->next;
    }

    fclose(file);
}

struct node *readFromFile() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("File not found or unable to open!\n");
        return NULL;
    }

    struct node *head = NULL;
    int value;
    while (fscanf(file, "%d", &value) != EOF) {
        addAtEnd(&head, value);
    }

    fclose(file);
    return head;
}
