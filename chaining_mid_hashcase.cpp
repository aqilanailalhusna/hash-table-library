#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Menampilkan menu
void menu(){
    system("cls");
    puts("Menu:");
    puts("1. Insert");
    puts("2. Search");
    puts("3. Display");
    puts("4. Exit");
    printf(">> ");
}

void ENTER(){
    printf("Tekan ENTER untuk melanjutkan...");
    getchar();
}

// Node linked-list (Chaining)
struct Node{
    char key[50];
    char value[100];
    struct Node* next;
};

Node* hashTable[TABLE_SIZE];

// Hash function mid-square
int hash(const char* key){
    int total=0;
    for(int i=0;key[i]!='\0';i++) // string to ASCII
        total+=key[i]*(i + 1);

    long square = (long)total * total; // pangkat 2

    char str[20];
    sprintf(str, "%ld", square);
    int len = strlen(str);
    int mid = len / 2;

    // if(midVal>=2){
    //     (str[mid-1]-'0')*10+(str[mid]-'0');
    // }else{
    //     (str[0] - '0')
    // }
    int midVal=(len>=2) ? (str[mid-1]-'0')*10+(str[mid]-'0') : (str[0]-'0');

    return midVal % TABLE_SIZE;
}

// Insert key-value ke hash table
void insert(const char* key, const char* value){
    int index = hash(key);
    Node* newNode=(Node*)malloc(sizeof(Node));
    strcpy(newNode->key,key);
    strcpy(newNode->value,value);
    newNode->next = hashTable[index];
    hashTable[index]=newNode;
}

// Search key
void search(const char* key) {
    int index = hash(key);
    Node* current = hashTable[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            printf("Key \"%s\" ditemukan dengan value: %s\n", key, current->value);
            return;
        }
        current = current->next;
    }
    printf("Key \"%s\" tidak ditemukan.\n", key);
}

// Display isi tabel
void display(){
    printf("\nIsi Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        if (current) {
            printf("[%d]: ", i);
            while (current) {
                printf("(%s: %s) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

// Menu saat input data
void inputData(){
    char key[50], value[100];
    printf("Masukkan key: ");
    scanf("%[^\n]",key);getchar();

    printf("Masukkan value: ");
    scanf("%[^\n]",value);getchar();

    insert(key, value);

    puts("Input berhasil");
}

int main(){
    int pilihan;
    char key[50], value[100];
    do{
        menu();
        scanf("%d", &pilihan);
        getchar();
        switch (pilihan) {
            case 1:
                inputData();
                ENTER();
                break;
            case 2:
                printf("Masukkan key yang dicari: ");
                scanf("%[^\n]",key);getchar();
                search(key);
                ENTER();
                break;
            case 3:
                display();
                ENTER();
                break;
            case 4:
                printf("Tekan ENTER untuk keluar...");
                getchar();
                break;
            default:
                printf("Input tidak valid.\nCoba lagi...");
                getchar();
        }

    } while (pilihan != 4);

    return 0;
}
