#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head = NULL;

int count = 0;

void preinsert() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    temp->data = num;
    temp->next=head;
    head=temp;
    ++count;
}

void del_beg() {
    if (count > 0) {
        struct node *temp = head;
        head = temp->next;
        free(temp);
        --count;
    } else {
        printf("No elements to delete.\n");
    }
}

void traversal() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search() {
    int num, i = 1, j = 0;
    printf("Enter an element to search: ");
    scanf("%d", &num);
    struct node *temp = head;
    while (temp != NULL) {
        if (num == temp->data) {
            printf("%d is found in the position %d\n", temp->data, i);
            j = 1;
        }
        temp = temp->next;
        i++;
    }
    if (j == 0)
        printf("Entered element is not in the list.\n");
}
int main() {
    int ch;
    do {
        printf("\n0. EXIT\n1.PUSH\n");
        printf("2. POP\n3. TRAVISAL\n");
        printf("4. SEARCH\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                preinsert();
                break;
            case 2:
                del_beg();
                break;
            case 3:
                traversal();
                break;
            case 4:
                search();
                break;
            case 0:
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (ch != 0);

    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
