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

void position() {
    int num, pos;
    printf("Enter the position (%d is the max count): ", count);
    scanf("%d", &pos);
    if (pos <= 0 || pos > count + 1) {
        printf("Invalid position.\n");
        return;
    }

    if (head == NULL || pos == 1) {
        preinsert();
    } 
    else if (count >= pos) {
        printf("Enter the number: ");
        scanf("%d", &num);
        struct node *temp = head;
        while (temp->next != NULL && pos - 1 > 1) {
            temp = temp->next;
            pos--;
        }
        struct node *cur = (struct node*)malloc(sizeof(struct node));
        if (cur == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        cur->data = num;
        cur->next = temp->next;
        temp->next = cur;
        ++count;
    }
}
void postinsert() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    struct node *cur = (struct node*)malloc(sizeof(struct node));
    if (cur == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    cur->data = num;
    cur->next = NULL;
    struct node *temp=head;
   while(temp->next!=NULL)
	temp=temp->next;
    temp->next=cur;
    ++count;
}

void del_end() {
    if (count > 0) {
        if (head->next==NULL) {
        struct node*temp=head;   
	 head =NULL;
	 free(temp);
           
        } else {
            struct node *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
	    struct node* ctr;	
            ctr = temp->next;
            temp->next = NULL;
	    free(ctr);
        }
        --count;
    } else {
        printf("Insufficient elements to perform this operation.\n");
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
void del_pos(){
 int  pos;
    printf("Enter the position (%d is the max count): ", count);
    scanf("%d", &pos);
    if (pos <= 0 || pos > count + 1) {
        printf("Invalid position.\n");
        return;
    }

    if (head == NULL) {
        printf("\n No element to delete\n ");
    } 
    else if (count >= pos) {
        struct node *temp = head;
        while (temp->next->next != NULL && pos - 1 > 1) {
            temp = temp->next;
            pos--;
        }
        struct node *cur = temp->next;
        temp->next = temp->next->next;
        free(cur);
        --count;
    }
}
int main() {
    int ch;
    do {
        printf("\n0. EXIT\n1. Add element at the beginning\n");
        printf("2. Add element at the end\n3. Add elements in a position\n");
        printf("4. Traversal\n5. Search an element in the list\n");
        printf("6. Delete from beginning\n7. Delete from the end\n8.Delete from position\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                preinsert();
                break;
            case 2:
                postinsert();
                break;
            case 3:
                position();
                break;
            case 4:
                traversal();
                break;
            case 5:
                search();
                break;
            case 6:
                del_beg();
                break;
            case 7:
                del_end();
                break;
            case 8:
                del_pos();
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

