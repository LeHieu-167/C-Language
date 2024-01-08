#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ð?nh nghia c?u trúc c?a m?t ph?n t? trong danh sách liên k?t
struct Node {
    int key;
    struct Node *next;
};

// Hàm d? t?o m?t ph?n t? m?i v?i khóa k
struct Node* createNode(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = k;
    newNode->next = NULL;
    return newNode;
}

// Hàm d? in danh sách liên k?t
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}

int exists(struct Node *head, int k) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->key == k) {
            return 1; // Ph?n t? t?n t?i
        }
        current = current->next;
    }
    return 0; // Ph?n t? không t?n t?i
}

// Hàm d? thêm m?t ph?n t? vào d?u danh sách
void addFirst(struct Node **head, int k) {
    if (!exists(*head, k)){
    struct Node *newNode = createNode(k);
    newNode->next = *head;
    *head = newNode;
    }
}

// Hàm d? thêm m?t ph?n t? vào cu?i danh sách
void addLast(struct Node **head, int k) {
    if(!exists(*head, k)){
    struct Node *newNode = createNode(k);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    }
}

// Hàm d? thêm m?t ph?n t? vào sau m?t ph?n t? khác trong danh sách
void addAfter(struct Node *head, int k, int after) {
    if (!exists(head, k) && exists(head, after)){
    struct Node *current = head;
    while (current != NULL && current->key != after) {
        current = current->next;
    }
    if (current != NULL) {
        struct Node *newNode = createNode(k);
        newNode->next = current->next;
        current->next = newNode;
    }
    }
}

// Hàm d? thêm m?t ph?n t? vào tru?c m?t ph?n t? khác trong danh sách
void addBefore(struct Node **head, int k, int before) {
    if (!exists(*head, k) && exists(*head, before)){
    if (*head == NULL) {
        return;
    }
    if ((*head)->key == before) {
        addFirst(head, k);
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL && current->next->key != before) {
        current = current->next;
    }
    if (current->next != NULL) {
        struct Node *newNode = createNode(k);
        newNode->next = current->next;
        current->next = newNode;
    }
    }
}

// Hàm d? lo?i b? m?t ph?n t? kh?i danh sách
void removeNode(struct Node **head, int k) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->key == k) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL && current->next->key != k) {
        current = current->next;
    }
    if (current->next != NULL) {
        struct Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

// Hàm d? d?o ngu?c danh sách liên k?t
void reverseList(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Node *head = NULL;
    
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        addLast(&head, key);
    }
    
    char command[20];
    int k, after, before;
    
    while (1) {
        scanf("%s", command);
        
        if (strcmp(command, "addlast") == 0) {
            scanf("%d", &k);
            addLast(&head, k);
        } else if (strcmp(command, "addfirst") == 0) {
            scanf("%d", &k);
            addFirst(&head, k);
        } else if (strcmp(command, "addafter") == 0) {
            scanf("%d %d", &k, &after);
            addAfter(head, k, after);
        } else if (strcmp(command, "addbefore") == 0) {
            scanf("%d %d", &k, &before);
            addBefore(&head, k, before);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &k);
            removeNode(&head, k);
        } else if (strcmp(command, "reverse") == 0) {
            reverseList(&head);
        } else if (strcmp(command, "#") == 0) {
            break;
        }
    }
    
    printList(head);
    
    return 0;
}
