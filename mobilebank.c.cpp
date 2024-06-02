#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct employee {
    char id[50];
    char password[50];
};

struct user {
    char phone[50];
    char ac[50];
    char name[100];
    char password[50];
    float balance;
};


void payBill(struct user *usr) {
    char meterNumber[50];
    int units;
    float billAmount;

    printf("\nEnter your meter number: ");
    scanf("%s", meterNumber);

    printf("Enter the units consumed: ");
    scanf("%d", &units);

    billAmount = 8.97 * units;

    if (billAmount > usr->balance) {
        printf("Insufficient balance to pay the bill.\n");
    } else {
        usr->balance -= billAmount;
        printf("Electricity bill of Rs.%.2f for meter number %s has been successfully paid. Your new balance is Rs.%.2f\n", billAmount, meterNumber, usr->balance);
    }
}

void payElectricityBill(struct user *usr) {
    // Code to handle electricity bill payments
    payBill(usr);
}

void mobileTopUp(struct user *usr) {
    char phone[50];
    float topupAmount;

    printf("\nEnter the phone number to top-up: ");
    scanf("%s", phone);
    printf("Enter the amount to top-up: ");
    scanf("%f", &topupAmount);

    usr->balance += topupAmount;
    printf("Mobile top-up of Rs.%.2f for phone number %s successful. Your new balance is Rs.%.2f\n", topupAmount, phone, usr->balance);
}

void loadESewa(struct user *usr) {
    char esewaNumber[50];
    float loadAmount;

    printf("\nEnter your eSewa number: ");
    scanf("%s", esewaNumber);

    printf("Enter the amount to load: ");
    scanf("%f", &loadAmount);

    usr->balance -= loadAmount;
    printf("Amount Rs.%.2f successfully transferred from your account to eSewa number %s. Your new balance is Rs.%.2f\n", loadAmount, esewaNumber, usr->balance);
}

void meroShareRenew(struct user *usr) {
    char meroShareID[50];
    float depositAmount;

    printf("\nEnter your MERO SHARE ID: ");
    scanf("%s", meroShareID);

    printf("Enter the amount to deposit for renewal: ");
    scanf("%f", &depositAmount);

    usr->balance += depositAmount;
    printf("Successfully renewed MERO SHARE ID %s. Amount Rs.%.2f deposited. Your new balance is Rs.%.2f\n", meroShareID, depositAmount, usr->balance);
}

void darazOnlineShopping(struct user *usr) {
    char orderNumber[50];
    float totalAmount;

    printf("\nEnter your order number: ");
    scanf("%s", orderNumber);

    printf("Enter the total amount of your order: ");
    scanf("%f", &totalAmount);

    if (totalAmount > usr->balance) {
        printf("Insufficient balance to pay the bill.\n");
    } else {
        usr->balance -= totalAmount;
        printf("Daraz online shopping bill of Rs.%.2f for order number %s has been successfully paid. Your new balance is Rs.%.2f\n", totalAmount, orderNumber, usr->balance);
    }
}

void movieTickets(struct user *usr) {
    char movieName[50];
    int seats;
    float ticketPrice;

    printf("\nAvailable Movies:\n");
    printf("1. Ratsasan - Rs.299 per seat\n");
    printf("2. Openheimer - Rs.499 per seat\n");
    printf("3. Brahmastra - Rs.299 per seat\n");
    printf("4. Dangal - Rs.299 per seat\n");
    printf("5. Pushpa - Rs.299 per seat\n");
    printf("6. Bahubali - Rs.299 per seat\n");
    printf("7. Barbie - Rs.299 per seat\n");
    printf("8. Kabaddi- Rs.199 per seat\n");
    printf("9. Inception - Rs.499 per seat\n");
    printf("10. Kantara - Rs.499 per seat\n");

    printf("\nEnter the movie name: ");
    scanf("%s", movieName);

    printf("Enter the number of seats to book: ");
    scanf("%d", &seats);
    if (strcmp(movieName, "Ratsasan") == 0 || strcmp(movieName, "Brahmastra") == 0 || strcmp(movieName, "Dangal") == 0 ||
        strcmp(movieName, "Pushpa") == 0 || strcmp(movieName, "Bahubali") == 0 || strcmp(movieName, "Kabaddi") == 0 || strcmp(movieName, "Barbie") == 0 ){
        ticketPrice = 299.0;
    } else if (strcmp(movieName, "Openheimer") == 0 || strcmp(movieName, "Spiderman") == 0|| strcmp(movieName,"Inception") || strcmp(movieName,"Kantara")){
        ticketPrice = 499.0;
    } else {
        printf("Invalid movie name. Please try again.\n");
        return;
    }

    float amount = ticketPrice * seats;

    if (amount > usr->balance) {
      printf("\nInsufficient balance");
    } else {
        usr->balance -= amount;
        printf("Successfully booked %d seats for %s movie. Total amount paid: Rs.%.2f. Your new balance is Rs.%.2f\n", seats, movieName, amount, usr->balance);
    }
}
int main() {
	 printf("###############################################################\n");
    printf("#                                                             #\n");
    printf("#             WELCOME TO NIC ASIA BANK LIMITED                #\n");
    printf("#                                                             #\n");
    printf("###############################################################\n\n");
    struct user usr, usr1;
    FILE *fp;
    char filename[50], phone[50], pword[50], emp_id[50], emp_pword[50];
    int opt, choice;
    char cont = 'y' ;
    float amount;

    struct employee employees[2]; // Define an array to store two employees' data


    strcpy(employees[0].id, "Sankalpa");
    strcpy(employees[0].password, "sankalpa123");

    strcpy(employees[1].id, "Sujan");
    strcpy(employees[1].password, "sujan123");
a:
	getche();
	system("cls");
	printf("\nWhat do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\nYour choice:\t");
    scanf("%d", &opt);

    if (opt == 1) {
        printf("\nEnter Employee ID:\t");
        scanf("%s", emp_id);
        printf("Enter Employee Password:\t");
        scanf("%s", emp_pword);

        int i;
        int found_employee = 0;
        for (i = 0; i < 2; i++) {
            if (strcmp(emp_id, employees[i].id) == 0 && strcmp(emp_pword, employees[i].password) == 0) {
                found_employee = 1;
                printf("Welcome %s ,Here you can register customers account",emp_id);
                break;
            }
        }

        if (!found_employee) {
            printf("Invalid employee credentials. Only employees have rights to register accounts.\n");
            return 0;
        }

        system("cls");
        printf("\n-----------------------------------------------------------");
        printf("\nThis is the registration form for the mobile banking system");
        printf("\n------------------------------------------------------------");
        printf("\nEnter your name:\t");
        getchar(); // Clear the input buffer                                                  **
        fgets(usr.name, sizeof(usr.name), stdin);
        usr.name[strcspn(usr.name, "\n")] = '\0'; // Remove the newline character
        printf("Enter your account number:\t");
        scanf("%s", usr.ac);
        printf("Enter your phone number:\t");
        scanf("%s", usr.phone);
        printf("Enter your new password:\t");
        scanf("%s", usr.password);
        usr.balance = 0;
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w+b");
        if (fp == NULL) {
            printf("\nError opening file. Please try again.");
            return 0;
        }
        fwrite(&usr, sizeof(struct user), 1, fp);                                     // *
        printf("\n\nAccount successfully registered");
        fclose(fp);
        goto a;
    }

    if (opt == 2) {
        system("cls");
        printf("\nPhone number:\t");
        scanf("%s", phone);
        printf("Password:\t");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r+b");
        if (fp == NULL) {
            printf("\nAccount number not registered");
        } else {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            system("cls");
            if (strcmp(pword, usr.password) == 0) {
                printf("\n\t\tWelcome %s", usr.name);
                while (cont == 'y' || 'Y') {
                	system("cls");
                	printf("\nHow can we serve you?");
                    printf("\n\nPress 1 for balance inquiry");
                    printf("\nPress 2 for depositing cash");
                    printf("\nPress 3 for cash withdrawal");
                    printf("\nPress 4 for online transfer");
                    printf("\nPress 5 for password change");
                    printf("\nPress 6 for paying water bill");
                    printf("\nPress 7 for paying electricity bill");
                    printf("\nPress 8 for mobile top-up");
                    printf("\nPress 9 for loading eSewa");
                    printf("\nPress 10 for Movie Tickets");
                    printf("\nPress 11 for Mero SHare Renew");
                    printf("\nPress 12 for Daraz Online Shopping");
                    printf("\nPress 13 for Customer Care");
                    printf("\nPress 14 for logout");
                    printf("\n\nYour choice:\t");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("\nYour current balance is Rs.%.2f", usr.balance);
                            break;
                        case 2:
                            printf("\nEnter the amount:\t");
                            scanf("%f", &amount);
                            usr.balance += amount;
                            fp = fopen(filename, "r+b");
                            if (fp == NULL) {
                                printf("\nError updating balance. Please try again.");
                                return 0;
                            }
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            fclose(fp);
                            printf("\nSuccessfully deposited.");
                            break;
                        case 3:
                            printf("\nEnter the amount:\t");
                            scanf("%f", &amount);
                            if (amount > usr.balance) {
                                printf("\nInsufficient balance");
                            } else {
                                usr.balance -= amount;
                                fp = fopen(filename, "r+b");
                                if (fp == NULL) {
                                    printf("\nError updating balance. Please try again.");
                                    return 0;
                                }
                                fwrite(&usr, sizeof(struct user), 1, fp);
                                fclose(fp);
                                printf("\nYou have withdrawn Rs.%.2f", amount);
                            }
                            break;
                        case 4:
                            printf("\nPlease enter the phone number to transfer the balance:\t");
                            scanf("%s", phone);
                            printf("\nPlease enter the amount to transfer:\t");
                            scanf("%f", &amount);
                            strcpy(filename, phone);
                            fp = fopen(strcat(filename, ".dat"), "r+b");
                            if (fp == NULL) {
                                printf("\nAccount number not registered");
                            } else {
                                fread(&usr1, sizeof(struct user), 1, fp);
                                fclose(fp);
                                if (amount > usr.balance) {
                                    printf("\nInsufficient balance");
                                } else {
                                    usr.balance -= amount;
                                    usr1.balance += amount;
                                    fp = fopen(filename, "r+b");
                                    if (fp == NULL) {
                                        printf("\nError updating balance. Please try again.");
                                        return 0;
                                    }
                                    fwrite(&usr1, sizeof(struct user), 1, fp);
                                    fclose(fp);

                                    strcpy(filename, usr.phone);
                                    fp = fopen(strcat(filename, ".dat"), "r+b");
                                    if (fp == NULL) {
                                        printf("\nError updating balance. Please try again.");
                                        return 0;
                                    }
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    fclose(fp);

                                    printf("\nYou have successfully transferred Rs.%.2f to %s", amount, phone);
                                }
                            }
                            break;
                        case 5:
                            printf("\nPlease enter your new password:\t");
                            scanf("%s", pword);
                            strcpy(usr.password, pword);
                            fp = fopen(filename, "r+b");
                            if (fp == NULL) {
                                printf("\nError updating password. Please try again.");
                                return 0;
                            }
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            fclose(fp);
                            printf("\nPassword successfully changed");
                            break;
                        case 6:
                            payBill(&usr);
                            // Code to save updated user data to file (if necessary)
                            break;
                        case 7:
                            payElectricityBill(&usr);
                            // Code to save updated user data to file (if necessary)
                            break;
                        case 8:
                            mobileTopUp(&usr);
                            // Code to save updated user data to file (if necessary)
                            break;
                        case 9:
                            loadESewa(&usr);
                            break;
                        case 10:
                        	movieTickets(&usr);
                        	break;
                        case 11:
                        	meroShareRenew(&usr);
                        	break;
                        case 12:
                			darazOnlineShopping(&usr);
                			break;
                		case 13:
                			printf("---------------------------------------------------------------\n");
                			printf("NIC ASIA BANK Mobile Banking Customer Care Support\n\n");
                			printf("---------------------------------------------------------------\n\n");
                			printf("- Customer Care Hotline: NIC ASIA BANK Customer Care Number\n");
							printf("- Email Support: NIC ASIA BANK Customer Care Email Address\n");
							printf("- Live Chat: Available on our official website during business hours\n\n");
							printf("Operating Hours:\n");
							printf("- Monday to Friday: 10 am to 3pm\n");
							printf("- Saturday: 11am to 2pm\n");
							printf("- Sunday: Closed\n\n");
							printf("How to Get Support:\n");
							printf("1. Customer Care Hotline:1652138682\n");
							printf("   - Dial NIC ASIA BANK Customer Care Number:3478234926834.\n");
							printf("   EMAIL:_nicasialimited@gmail.com\n\n");
							printf("Never share your password or personal information with anyone, including our customer care representatives.\n\n");
							printf("Thank you for choosing NIC ASIA BANK Mobile Banking. We value your trust and are committed to serving you with excellence. Your satisfaction is our priority.\n\n");
							printf("Sincerely,\n");
							printf("NIC ASIA BANK Customer Care Team\n");
							break;
                		case 14:
                			goto a;

                        default:
                            printf("\nInvalid option");
                    }

                    printf("\nDo you want to continue the transaction [y/n]\t");
                    scanf(" %c", &cont);
                }
            } else {
                printf("\nInvalid password");
            }
        }
    }
    printf("\n###############################################################\n");
    printf("#                                                               #\n");
    printf("#        Thank you for visiting NIC ASIA BANK LIMITED.          #\n");
    printf("#        We value your trust and are committed to               #\n");
    printf("#        serving you with excellence. Your satisfaction is      #\n");
    printf("#        our priority.                                          #\n");
    printf("#                                                               #\n");
    printf("#################################################################\n");

    return 0;
    }
