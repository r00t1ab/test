#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//time_t t = time(NULL);
//struct tm tm = *localtime(&t);

typedef struct{
    int barcode;
    char name[20];
    char catagory[20];
    int location;
    int available_count;
    int borrowers[10];
    char return_date[10];
}BOOK;

void user_action(BOOK *book){
    printf("\n------------------------------------------------------------------\n[+]\tBOOK DETAIL\n------------------------------------------------------------------\n\n");
    printf("%10s : %d\n","Barcode",book->barcode);
    printf("\n%10s : %s\n","Name",book->name);
    printf("\n%10s : %s\n","Catagory",book->catagory);
    printf("\n%10s : %d\n","Location",book->location);
    int available = book->available_count-sizeof(book->borrowers)/sizeof(int);
    printf("\n%10s : %d/%d\n","Available",available,book->available_count);

    printf("\n------------------------------------------------------------------\n\n");
    printf("[+]\tAre you want to borrow (y/N) : ");

    char buff[3];
    long int id;
    scanf("%s",buff);
    if(strcmp(buff,"y")==0){
        printf("[+]\tEnter Your ID Number : ");
        scanf("%ld",id);
        if(available>0){
            printf("[+]\tBook is borrowed\n");
            //ook->borrowers[book->borrowers)] = ;
            printf("%ld",book->borrowers[0]);
        }else{
            printf("[+]\tPlease Wait Until book will return\n");
        }
    }

}

int main()
{
    //create book records
    BOOK b1;
    b1.barcode=114;
    b1.available_count=10;
    //b1.borrowers[0][20]="dd";
    b1.borrowers[0]=23223233;
    BOOK b2;
    BOOK b3;

    BOOK books[]={b1,b2,b3};

    while(1){
        char in_buffer[20];
        printf("\n\n------------------------------------------------------------------\n\t(-:\tWELCOME TO THE LIBRARY BOOK CHECKER\t:-)\t\n------------------------------------------------------------------\n\n");
        start:
        printf("\n[+]\tEnter the Book Name or Barcode : ");
        fgets(in_buffer,20,stdin);

        int book_record_count = sizeof(books)/sizeof(BOOK);

;       if(strlen(in_buffer)==1){
            printf("\n[-]\tPlease Enter the Valid Book Name\n[-]\t(if you want to exit press 'q' and enter)\n");
            goto start;
            continue;
        }
        if(strcmp(in_buffer,"q\n")==0){
            printf("\n[+]\t.....THANK YOU FOR USING LIBRARY.....\n");
            break;
        }

        if(atoi(in_buffer)){
            int book_i = -1;
            for(int i = 0;i<book_record_count;i++){
                if(books[i].barcode==atoi(in_buffer)){
                    book_i = i;
                }
            }
            (book_i == -1)?printf("[-]\tSORRY! UNREGISTERED BARCODE.\n"):user_action(&books[book_i]);
        }else{
            int book_i = -1;
            for(int i = 0;i<book_record_count;i++){
                if(strcmp(books[i].name,in_buffer)==0){
                    book_i = i;
                }
            }
            (book_i == -1)?printf("[-]\tSORRY! BOOK NOT FOUND IN LIBRARY.\n"):user_action(&books[book_i]);
        }
    }

    return 0;
}
