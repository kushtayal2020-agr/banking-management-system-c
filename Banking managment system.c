#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/* Global variables */
int totalamount = 1000, amount, amo, totaldeposite = 0, totalwith = 0;
int account_created = 0;

struct banking {
    char name[30], fname[30];
    int DOB_dd, DOB_mm, DOB_yy;
    char adhar_no[13], mob_no[10], pan_no[11];
    char street[20], post[20], police_station[20], district[20], state[20], pincode[6];
    char acc_no[11], costumer_id[6];
};

struct banking bank;

/* Clear screen */
void clrscr() {
    printf("\033[2J\033[H");
}

/* Function declarations */
void login();
void mainmenu();
void acc_open();
void details();
void deposit();
void withdraw();
void update();
int verify_account();

/* MAIN */
void main() {

    /* Assume user already has an old account */
    strcpy(bank.acc_no, "ITM2025001");
    strcpy(bank.costumer_id, "C1001");
    account_created = 1;

    clrscr();
    printf("\n\n\t\t\tWelcome To The Banking Management System");
    printf("\n\n\t\t\tPress any key to continue.....");
    getch();
    login();
}

/* LOGIN */
void login() {
    char user[25], pass[25];
    clrscr();

    printf("\n\n\t\t\tEnter The Username : ");
    gets(user);
    printf("\n\t\t\tEnter The Password : ");
    gets(pass);

    if (strcmp(user, "Bank123") == 0 && strcmp(pass, "Bank@2341") == 0) {
        printf("\n\n\t\t\tLogin Successfull");
        printf("\n\t\t\tPress any key to continue.....");
        getch();
        mainmenu();
    } else {
        printf("\n\n\t\t\tInvalid Username or Password");
        printf("\n\t\t\tPress any key to continue.....");
        getch();
    }
}

/* MAIN MENU */
void mainmenu() {
    int choice;

lineno47:
    clrscr();
    printf("\n\n\t\t\t=== MAIN MENU ===");
    printf("\n\n\t\t\t1. Account opening");
    printf("\n\t\t\t2. Details of Account");
    printf("\n\t\t\t3. Update Account");
    printf("\n\t\t\t4. Withdraw");
    printf("\n\t\t\t5. Deposit");
    printf("\n\t\t\t6. Exit");
    printf("\n\n\t\t\tYou have entered : ");
    scanf("%d", &choice);
    while (getchar() != '\n');

    switch (choice) {
        case 1: acc_open(); goto lineno47;
        case 2: details(); goto lineno47;
        case 3: update(); goto lineno47;
        case 4: withdraw(); goto lineno47;
        case 5: deposit(); goto lineno47;
        case 6:
            printf("\n\n\t\t\tThanks For Visiting");
            getch();
            exit(0);
        default:
            printf("\n\n\t\t\tInvalid choice!");
            getch();
            goto lineno47;
    }
}

/* ACCOUNT OPEN */
void acc_open() {

    if (account_created == 1) {
        clrscr();
        printf("\n\n\t\t\tAccount already exists!");
        printf("\n\t\t\tAccount Number : %s", bank.acc_no);
        printf("\n\t\t\tCustomer ID    : %s", bank.costumer_id);
        printf("\n\n\t\t\tPress any key to continue...");
        getch();
        return;
    }

    clrscr();
    printf("\n\n\t\t\t=== ACCOUNT OPENING FORM ===");

    printf("\nEnter Name : ");
    gets(bank.name);
    printf("\nEnter Father's Name : ");
    gets(bank.fname);

    strcpy(bank.acc_no, "ITM2025001");
    strcpy(bank.costumer_id, "C1001");

    account_created = 1;

    printf("\n\n\t\t\tAccount Created Successfully!");
    printf("\n\t\t\tAccount Number : %s", bank.acc_no);
    printf("\n\t\t\tCustomer ID    : %s", bank.costumer_id);
    getch();
}

/* DETAILS */
void details() {
    clrscr();
    if (account_created == 0) {
        printf("\n\n\t\t\tNo account details available!");
        getch();
        return;
    }

    printf("\n\n\t\t\tAccount Number : %s", bank.acc_no);
    printf("\n\t\t\tCustomer ID    : %s", bank.costumer_id);
    printf("\n\t\t\tTotal Amount   : %d", totalamount);
    printf("\n\t\t\tDeposited Amt  : %d", totaldeposite);
    printf("\n\t\t\tWithdrawn Amt  : %d", totalwith);
    getch();
}

/* UPDATE */
void update() {
    clrscr();
    printf("\n\n\t\t\tUpdate feature coming soon...");
    getch();
}

/* VERIFY ACCOUNT */
int verify_account() {
    char acc[11], cid[6];

    if (account_created == 0) {
        printf("\n\n\t\t\tNo account found!");
        getch();
        return 0;
    }

    clrscr();
    printf("\n\n\t\t\tACCOUNT VERIFICATION");

    printf("\n\n\t\t\tEnter Account Number : ");
    scanf("%10s", acc);

    printf("\n\t\t\tEnter Customer ID   : ");
    scanf("%5s", cid);

    if (strcmp(acc, bank.acc_no) == 0 && strcmp(cid, bank.costumer_id) == 0)
        return 1;

    printf("\n\n\t\t\tInvalid Account Number or Customer ID!");
    getch();
    return 0;
}

/* WITHDRAW */
void withdraw() {
    if (!verify_account()) return;

    printf("\n\n\t\t\tEnter amount to withdraw : ");
    scanf("%d", &amo);

    if (amo <= totalamount) {
        totalamount -= amo;
        totalwith += amo;
        printf("\n\n\t\t\tWithdrawal SuccessfuLl!");
    } else {
        printf("\n\n\t\t\tInsufficient Balance!");
    }
    getch();
}

/* DEPOSIT */
void deposit() {
    if (!verify_account()) return;

    printf("\n\n\t\t\tEnter amount to deposit : ");
    scanf("%d", &amount);

    totalamount += amount;
    totaldeposite += amount;

    printf("\n\n\t\t\tDeposit Successful!");
    getch();
}



