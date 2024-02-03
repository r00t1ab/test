#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char names[20][20] = {"Amali","Tashitha","Dasun","Thilina","Upeksha","Sasuni","Kalana","Dhanuka","Apsara","Vikum","Shenuri","Uditha","Deshan","Taniya","Anuradha","Anuththra","Sandaru","Rex","Manuka","Lasith"};

const int book_borrow_code = 777;
const int year = 2024;
const int month = 1;
const int day = 24;

typedef struct{
    int d,m,y;
}DATE;

typedef struct{
    int borrowed;
    char name[20];
    int y;
    int m;
    int d;
}BORROW;

typedef struct{
    int barcode;
    char name[20];
    int location;
    int available_count;
    BORROW borrower[10];
}BOOK;

DATE date_gen(int k){
    DATE date;
    date.d = day;
    date.m = month;
    date.y = year;

    if(k){
        date.d += rand() % 14;
    }else{
        date.d += 14;
    }
    if(date.d > 31){
        date.d -= 30;
        date.m++;
        if(date.m > 13){
            date.y++;
        }
    }
    return date;
}

int borrower_counter(BOOK book){
    int count = 0;
    for(int i = 0;i<10;i++){
        if(book.borrower[i].borrowed==book_borrow_code){
            count++;
        }
    }
    return count;
}

void user_action(BOOK *book){
    printf("\n------------------------------------------------------------------\n[+]\tBOOK DETAIL\n------------------------------------------------------------------\n\n");
    printf("\n %-10s : %d\n","Barcode",book->barcode);
    printf("\n %-10s : %s\n","Name",book->name);
    printf("\n %-10s : %d\n","Location",book->location);
    int available = book->available_count-borrower_counter(*book);
    printf("\n %-10s : %d / %d\n","Available",available,book->available_count);

    printf("\n------------------------------------------------------------------\n");
    printf("[+]\tAre you want to borrow (y/N) : ");

    char buff[3];
    scanf("%s",buff);
    if(strcmp(buff,"y")==0){

        if(available>0){
            printf("[+]\tEnter Your Name : ");
            scanf("%s",book->borrower[book->available_count-available].name);
            book->borrower[book->available_count-available].borrowed = book_borrow_code;
            DATE date2 = date_gen(0);
            book->borrower[book->available_count-available].y = date2.y;
            book->borrower[book->available_count-available].m = date2.m;
            book->borrower[book->available_count-available].d = date2.d;
            printf("[+]\tBook is borrowed\n");
        }else{
            printf("\n-----------------------------------------------------------------\n");
            printf("| %-30.30s| %-30.30s |","BORROWER","RETURN DATE");
            printf("\n-----------------------------------------------------------------\n");
            for(int i = 0;i<book->available_count-available;i++){
                printf("| %-30.30s| %02d / %02d / %4d %15s |\n",book->borrower[i].name,book->borrower[i].d,book->borrower[i].m,book->borrower[i].y,"");
            }
            printf("\n-----------------------------------------------------------------\n");
            printf("[+]\tPlease Contact or Wait Until book will return\n");
        }
    }

}

int main()
{
    //create book records
    BOOK b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19,b20;
    BOOK books[20]={b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19,b20};

    strcpy(books[0].name,"Treasure_Island");
    strcpy(books[1].name,"Jane_Eyre");
    strcpy(books[2].name,"Moby_Dick");
    strcpy(books[3].name,"Little_Women");
    strcpy(books[4].name,"Oliver_Twist");
    strcpy(books[5].name,"Dracula");
    strcpy(books[6].name,"Brave_New_World");
    strcpy(books[7].name,"War_and_Peace");
    strcpy(books[8].name,"The_Wizard_of_Oz");
    strcpy(books[9].name,"Les_Misérables");
    strcpy(books[10].name,"Animal_Farm");
    strcpy(books[11].name,"The_Little_Prince");
    strcpy(books[12].name,"Anna_Karenina");
    strcpy(books[13].name,"Heidi");
    strcpy(books[14].name,"Ulysses");
    strcpy(books[15].name,"Pinocchio");
    strcpy(books[16].name,"Ivanhoe");
    strcpy(books[17].name,"Black_Beauty");
    strcpy(books[18].name,"Peter_Pan");
    strcpy(books[19].name,"Lord_of_the_Flies");

    for(int i = 0; i < 20;i++){
        books[i].barcode = 4*i+1000;
    }

    for(int i = 0;i<20;i++){
        books[i].available_count = (rand() % 4) + 7;
        books[i].location = rand() % 1000;
        int k = rand()%9;
        for(int j = 0;j<k;j++){
            strcpy(books[i].borrower[j].name,names[rand()%20]);
            DATE date1 = date_gen(1);
            books[i].borrower[j].borrowed = book_borrow_code;
            books[i].borrower[j].y = date1.y;
            books[i].borrower[j].m = date1.m;
            books[i].borrower[j].d = date1.d;
        }
    }


    while(1){
        char in_buffer[20];
        printf("\n\n------------------------------------------------------------------\n\t(-:\tWELCOME TO THE LIBRARY BOOK CHECKER\t:-)\t\n------------------------------------------------------------------\n\n");
        printf("[+]\tEnter the Book Name or Barcode : ");
        scanf("%s",in_buffer);

        //check the book record count
        int book_record_count = 20;

        if(strcmp(in_buffer,"q")==0){
            printf("\n[+]\t.....THANK YOU FOR USING LIBRARY.....\n\n");
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
