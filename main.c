#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <conio.h>

#include <time.h>

#include <math.h>

#define ENTER 13
#define TAB 9
#define SPACE 32
#define BKSP 8

int main() {
  char from[30], to[30];
  int i = 0, k, z, amount, c = 0, q;

  struct passengers
  //declaration of structure and by "passengers" name it will be known
  {
    char firstname[100], lastname[100], gender[10], m_no[40], seat[50];
    int seat_, bookedseats;
    //these variables holds first name ,last name, gender, mobile number, seat, booked seats

  };
  FILE * fp;
  char FullName[60];
  char MobileNo[60];
  char Password[60], CPassword[60];
  char choice1[60], choice2[60], choice3[60], choice4[60];
  char Mno[60], Passw[60];
  char AdMno[60], AdPassw[60], choice0[10];
  char busN[5][50] = {"AIRAVAT EXPRESS","FLYBUS EXPRESS","SATHAVAHANA EXPRESS","SRI NAVADURGA EXPRESS","VOLVO CLUB CLASS EXPRESS"};
  char bn[5][20] = {"7032","5689","8631","7562","6442"};
  int AA, AK = 1, ASD = 1;
  char Adwords[1000][50];
  int M, T, A, K = 1;
  int count = 0, Mob, wor;
  char words[1000][50];
  int value;
  char ch;
  char account_holder_name[100];
  char Acc_No[100];
  char Branch_Name[100];
  char IFSE_Code[100];
  int bus7032[50], bus5689[50], bus8631[50], bus7562[50], bus6442[50];
  int B1 = 0, B2 = 0, B3 = 0, B4 = 0, B5 = 0;
  int a;
  while (1) {
    while (1) {
      system("cls");
      printf("\n                                 WELCOME TO THE CS BUS TRAVELS\n\n");
      //output will pop up at the start with "welcome to the cs bus travels"
      while (2) {
        printf("   1  =>  LOGIN\n\n   2  =>  SIGNUP\n\n   3  =>  ADMIN LOGIN\n\n");
        //need to select choice out of login ,signup, admin login for further booking
        printf("ENTER YOUR CHOICE:\n");
        fgets(choice1, 60, stdin);
        if (strcmp(choice1, "1\n") == 0 || strcmp(choice1, "2\n") == 0 || strcmp(choice1, "3\n") == 0) {
          break;
        } else {
          printf("Enter valid choice\n");
        }
      }
      if (strcmp(choice1, "1\n") == 0) {
        fp = fopen("data.txt", "r");
        while (3) {
          A = 1;
          printf("Mobile No :");
          fgets(Mno, 60, stdin);
          Mno[strcspn(Mno, "\n")] = 0;
          count = 0;
          fseek(fp, 0, SEEK_SET);
          while (fscanf(fp, "%s", words[count]) > 0) {
            if (strcmp(words[count], Mno) == 0) {
              break;
            } else
              count++;
          }
          for (i = 0; Passw[i] != '\0'; i++) {
            strcpy( & Passw[i], "\0");
          }
          printf("Password  :");
          i = 0;
          while (4) {
            ch = getch();
            if (ch == ENTER) {
              Passw[i] = '\0';
              break;
            } else if (ch == BKSP) {
              if (i > 0) {
                i--;
                printf("\b \b");
              }
            } else if (ch == TAB || ch == SPACE) {
              continue;
            } else {
              Passw[i] = ch;
              i++;
              printf("*");
            }
          }
          if (strcmp(Passw, words[count - 1]) == 0) {
            K = 0;
            break;
          } else {
            printf("\nIncorrect Username or Password\nTry Again!!!\n\n");
            while (5) {
              printf("   1  =>  Back to main page\n\n   2  =>  Try logging in again\n\n");
              printf("ENTER YOUR CHOICE:\n");
              fgets(choice2, 60, stdin);
              if (strcmp(choice2, "1\n") == 0 || strcmp(choice2, "2\n") == 0) {
                break;
              } else {
                printf("Enter valid choice\n");
              }
            }
            //if(strcmp(choice2,"2\n")==0);
            if (strcmp(choice2, "1\n") == 0) {
              A = 0;
              break;
            }
          }
        }
        fclose(fp);
        if (A == 0) {
          continue;

        }
        break;
      } else if (strcmp(choice1, "2\n") == 0) {
        printf("\nEnter Full Name :");
        fgets(FullName, 60, stdin);
        FullName[strcspn(FullName, "\n")] = 0;
        while (6) {
          M = 1, T = 1;
          printf("Enter your Mobile No.");
          fgets(MobileNo, 60, stdin);
          MobileNo[strcspn(MobileNo, "\n")] = 0;
          if (strlen(MobileNo) == 10 && MobileNo[0] >= 54 && MobileNo[0] <= 57) {
            for (i = 0; MobileNo[i] != '\0'; i++) {
              if (MobileNo[i] >= 48 && MobileNo[i] <= 57);
              else {
                printf("Invalid Mobile Number\n");
                break;
              }
            }
          } else {
            printf("Invalid Mobile Number\n");
            continue;
          }
          //type mobile number
          if (i == 10) {
            printf("\nMobile Number Verified\n\n");
            FILE * fp = fopen("data.txt", "r");
            count = 0;
            sscanf(MobileNo, "%d", & Mob);
            while (fscanf(fp, "%s", words[count]) > 0) {
              sscanf(words[count], "%d", & wor);
              if (wor == Mob) {
                printf("Mobile number is already registered\n\n");
                M = 0;
                break;
              } else {
                count++;
              }
            }
            //need to choose another mobile number which is not registered
            fclose(fp);
            if (M == 1) {
              break;
            }
          }
          if (M == 0) {
            while (7) {
              printf("   1  =>  Continue registering with another mobile number\n\n   2  =>  Back to main page\n\n");
              printf("ENTER YOUR CHOICE:\n");
              fgets(choice3, 60, stdin);
              if (strcmp(choice3, "1\n") == 0 || strcmp(choice3, "2\n") == 0) {
                break;
              } else {
                printf("Enter valid choice\n");
              }
            }
            //if(strcmp(choice3,"1\n")==0);
            if (strcmp(choice3, "2\n") == 0) {
              T = 0;
              break;
            }
          }
        }
        if (T == 0) {
          continue;
        }
        while (8) {
          printf("Create Password :");
          fgets(Password, 60, stdin);
          Password[strcspn(Password, "\n")] = 0;
          count = 0;
          for (i = 0; Password[i] != '\0'; i++) {
            if (Password[i] == ' ') {
              count++;
            }
          }
          if (count == 0) {
            if (strlen(Password) >= 4) {
              printf("Confirm Password :");
              fgets(CPassword, 60, stdin);
              CPassword[strcspn(CPassword, "\n")] = 0;
              value = strcmp(Password, CPassword);
              if (value == 0) {
                break;
              } else {
                printf("Password did not match\n\n");
              }
            }
            //need to create password ,confirm password and both should be same
            else {
              printf("Password should contain minimum of 4 characters and Spaces are not allowed\n\n");
            }
          } else {
            printf("Spaces are not allowed in password and should contain minimum of 4 characters\n\n");
          }
        }
      }
      //condition for creating password it must be min of four characters and spaces are not allowed
      else if (strcmp(choice1, "3\n") == 0) {
        fp = fopen("Admin.txt", "r");
        while (3) {
          AA = 1;
          printf("Username :");
          fgets(AdMno, 60, stdin);
          AdMno[strcspn(AdMno, "\n")] = 0;
          count = 0;
          fseek(fp, 0, SEEK_SET);
          while (fscanf(fp, "%s", Adwords[count]) > 0) {
            if (strcmp(AdMno, Adwords[count]) == 0) {
              //sscanf(Adwords[count-1],"%s",Adpass);
              break;
            } else
              count++;
          }
          for (i = 0; AdPassw[i] != '\0'; i++) {
            strcpy( & AdPassw[i], "\0");
          }
          printf("Password :");
          i = 0;
          while (4) {
            ch = getch();
            if (ch == ENTER) {
              AdPassw[i] = '\0';
              break;
            } else if (ch == BKSP) {
              if (i > 0) {
                i--;
                printf("\b \b");
              }
            } else if (ch == TAB || ch == SPACE) {
              continue;
            } else {
              AdPassw[i] = ch;
              i++;
              printf("*");
            }
          }
          if (strcmp(AdPassw, Adwords[count - 1]) == 0) {
            AK = 0;
            break;
          } else {
            printf("\nIncorrect Username or Password\nTry Again!!!\n\n");
            // if user types incorrect username or password ,needs to retype it again
            while (5) {
              printf("   1  =>  Back to main page\n\n   2  =>  Try logging in again\n\n");
              printf("ENTER YOUR CHOICE:\n");
              fgets(choice0, 60, stdin);
              if (strcmp(choice0, "1\n") == 0 || strcmp(choice0, "2\n") == 0) {
                break;
              } else {
                printf("Enter valid choice\n");
              }
            }
            //if(strcmp(choice2,"2\n")==0);
            if (strcmp(choice0, "1\n") == 0) {
              AA = 0;
              break;
            }
          }
        }
        fclose(fp);
        if (AA == 0) {
          continue;
        }
        if (AK == 0) {
          printf("\n\n                             LOGIN SUCCESSFUL\n\n");
        }
        char admin[50];
        int bsm[36], s_n, kchoice;
        char choice1[60], number[60], sn[60], choice9[60];
        // need to select the choice among five buses
        int i, ichoice, a = 11, jchoice, p;
        // it now allows admin to book seats and tickets
        while (1) {
          system("cls");
          printf("\n\n          *******************WELCOME ADMIN***************\n\n");
          printf("\n\n===================SELECT ONE OF THE FOLLOWING OPTIONS===================\n\n");
          printf("    1.RESERVING SEATS\n\n    2.FREE ALL THE RESERVED SEATS\n\n    3.FREE ALL BOOKED SEATS\n\n    4.RATINGS\n\n    5.LOGOUT\n\n");
          printf("ENTER YOUR CHOICE:\n");
          fgets(admin, 49, stdin);
          if (strlen(admin) == 2) {
            if (admin[0] == 49 || admin[0] == 50 || admin[0] == 51 || admin[0] == 52 || admin[0] == 53) {
              system("cls");
              if (admin[0] == 49) {
                while (1) {
                  printf("Select Bus :\n");
                  printf("   1  =>  %s\n\n", busN[0]);
                  printf("   2  =>  %s\n\n", busN[1]);
                  printf("   3  =>  %s\n\n", busN[2]);
                  printf("   4  =>  %s\n\n", busN[3]);
                  printf("   5  =>  %s\n\n", busN[4]);
                  while (1) {
                    printf("ENTER YOUR CHOICE\n");
                    fgets(choice1, 60, stdin);
                    if (strcmp(choice1, "1\n") == 0 || strcmp(choice1, "2\n") == 0 || strcmp(choice1, "3\n") == 0 || strcmp(choice1, "4\n") == 0 || strcmp(choice1, "5\n") == 0) {
                      sscanf(choice1, "%d", & ichoice);
                      break;
                    } else {
                      printf("Enter valid choice\n");
                    }
                  }
                  if (ichoice == 1) {
                    a = 0;
                  }
                  if (ichoice == 2) {
                    a = 1;
                  }
                  if (ichoice == 3) {
                    a = 2;
                  }
                  if (ichoice == 4) {
                    a = 3;
                  }
                  if (ichoice == 5) {
                    a = 4;
                  }
                  printf("\n********************SEAT MATRIX****************\n\n");
                  for (int i = 0; i < 36; i++) {
                    bsm[i] = 0;
                  }
                  if (a == 0) {
                    fp = fopen("Bus1.txt", "r");
                  }
                  if (a == 1) {
                    fp = fopen("Bus2.txt", "r");
                  }
                  if (a == 2) {
                    fp = fopen("Bus3.txt", "r");
                  }
                  if (a == 3) {
                    fp = fopen("Bus4.txt", "r");
                  }
                  if (a == 4) {
                    fp = fopen("Bus5.txt", "r");
                  }
                  while (fscanf(fp, "%d", & p) != EOF) {
                    bsm[p - 1] = 2;
                  }
                  fclose(fp);
                  if (a == 0) {
                    fp = fopen("Booking1.txt", "r");
                  }
                  if (a == 1) {
                    fp = fopen("Booking2.txt", "r");
                  }
                  if (a == 2) {
                    fp = fopen("Booking3.txt", "r");
                  }
                  if (a == 3) {
                    fp = fopen("Booking4.txt", "r");
                  }
                  if (a == 4) {
                    fp = fopen("Booking5.txt", "r");
                  }
                  int t1;
                  while (fscanf(fp, "%d", & t1) != EOF) {
                    bsm[t1 - 1] = 1;
                  }
                  fclose(fp);
                  for (int i = 0; i < 36; i++) {
                    if (bsm[i] == 0 && i < 9) {
                      printf("%d . FREE\t", i + 1);
                    }
                    if (bsm[i] == 0 && i >= 9) {
                      printf("%d. FREE\t", i + 1);
                    }
                    if (bsm[i] == 1 && i < 9) {
                      printf("%d . BOOKED\t", i + 1);
                    }
                    if (bsm[i] == 1 && i >= 9) {
                      printf("%d. BOOKED\t", i + 1);
                    }
                    if (bsm[i] == 2 && i < 9) {
                      printf("%d . RESERVED\t", i + 1);
                    }
                    if (bsm[i] == 2 && i >= 9) {
                      printf("%d. RESERVED\t", i + 1);
                    }
                    if ((i + 1) % 2 == 0) {
                      printf("\t");
                    }
                    if ((i + 1) % 4 == 0) {
                      printf("\n");
                    }
                  }
                  //either seats are booked ,free ,or reserved
                  while (2) {
                    printf("\nNOTE : The seat number entered will only be reserved\nPreviously reserved seats will no longer remain reserved if nor entered again\n");
                    printf("\nEnter the number of seats to be reserved :");
                    fgets(number, 60, stdin);
                    sscanf(number, "%d", & jchoice);
                    if (jchoice >= 1 && jchoice <= 36) {
                      break;
                    } else {
                      printf("Invalid Number\n");
                    }
                  }
                  FILE * fpointer;
                  if (a == 0) {
                    fpointer = fopen("Bus1.txt", "w");
                  }
                  if (a == 1) {
                    fpointer = fopen("Bus2.txt", "w");
                  }
                  if (a == 2) {
                    fpointer = fopen("Bus3.txt", "w");
                  }
                  if (a == 3) {
                    fpointer = fopen("Bus4.txt", "w");
                  }
                  if (a == 4) {
                    fpointer = fopen("Bus5.txt", "w");
                  }
                  // admin use "w" mode to write the bus name and seat number
                  for (i = 0; i < jchoice; i++) {
                    while (3) {
                      printf("Enter seat number : ");
                      fgets(sn, 60, stdin);
                      sscanf(sn, "%d", & s_n);
                      if (s_n >= 1 && s_n <= 36) {
                        fprintf(fpointer, "%d ", s_n);
                        break;
                      } else {
                        printf("Invalid Number\n");
                      }
                    }
                  }
                  fclose(fpointer);
                  printf("\nSelected seats are Reserved Successfully\n");
                  printf("\nEnter any key to go to main page\n");
                  getch();
                  break;
                }
              }
              if (admin[0] == 50 || admin[0] == 51) {
                printf("Select Bus :\n");
                printf("   1  =>  %s\n\n", busN[0]);
                printf("   2  =>  %s\n\n", busN[1]);
                printf("   3  =>  %s\n\n", busN[2]);
                printf("   4  =>  %s\n\n", busN[3]);
                printf("   5  =>  %s\n\n", busN[4]);
                while (1) {
                  printf("ENTER YOUR CHOICE\n");
                  fgets(choice9, 60, stdin);
                  if (strcmp(choice9, "1\n") == 0 || strcmp(choice9, "2\n") == 0 || strcmp(choice9, "3\n") == 0 || strcmp(choice9, "4\n") == 0 || strcmp(choice9, "5\n") == 0) {
                    sscanf(choice9, "%d", & kchoice);
                    break;
                  } else {
                    printf("Enter valid choice\n");
                  }
                }
                if (kchoice == 1) {
                  a = 0;
                }
                if (kchoice == 2) {
                  a = 1;
                }
                if (kchoice == 3) {
                  a = 2;
                }
                if (kchoice == 4) {
                  a = 3;
                }
                if (kchoice == 5) {
                  a = 4;
                }
                if(admin[0] == 50) {
                FILE * fpointer;
                if (a == 0) {
                  fpointer = fopen("Bus1.txt", "w");
                }
                if (a == 1) {
                  fpointer = fopen("Bus2.txt", "w");
                }
                if (a == 2) {
                  fpointer = fopen("Bus3.txt", "w");
                }
                if (a == 3) {
                  fpointer = fopen("Bus4.txt", "w");
                }
                if (a == 4) {
                  fpointer = fopen("Bus5.txt", "w");
                }
                fprintf(fpointer, " ");
                fclose(fpointer);
                printf("\nAll Reserved seats are Freed Successfully\n");
                printf("\nEnter any key to go to main page\n");
                getch();
              }
              if(admin[0] == 51) {
                FILE * fpointer;
                if (a == 0) {
                  fpointer = fopen("Booking1.txt", "w");
                }
                if (a == 1) {
                  fpointer = fopen("Booking2.txt", "w");
                }
                if (a == 2) {
                  fpointer = fopen("Booking3.txt", "w");
                }
                if (a == 3) {
                  fpointer = fopen("Booking4.txt", "w");
                }
                if (a == 4) {
                  fpointer = fopen("Booking5.txt", "w");
                }
                fprintf(fpointer, " ");
                fclose(fpointer);
                printf("\nAll Booked seats are Freed Successfully\n");
                printf("\nEnter any key to go to main page\n");
                getch();
              }
              }
              if (admin[0] == 52) {
                FILE * fp;
                fp = fopen("Review.txt", "r");
                char line[100];
                while (fgets(line, 99, fp) != NULL) {
                  printf("%s\n", line);
                }
                fclose(fp);
                printf("\nEnter any key to go to main page\n");
                getch();
              }
              if (admin[0] == 53) {
                ASD = 0;
                break;
              }
            } else {
              printf("ENTER A VALID OPTION\n\n");
            }
          } else {
            printf("ENTER A VALID OPTION\n\n");
          }
        }
      }
      if (ASD == 0) {
        continue;
      }
      while (9) {
        printf("\nConfirm your details\n\n");
        printf("Full Name: %s\n", FullName);
        printf("Mobile Number : %s\n\n", MobileNo);
        printf("   1  =>  Confirm\n\n   2  =>  Return to main page and Sign up again\n\n");
        printf("ENTER YOUR CHOICE:\n");
        printf("Press the required DIGIT to continue : \n");
        fgets(choice4, 60, stdin);
        if (strcmp(choice4, "1\n") == 0 || strcmp(choice4, "2\n") == 0) {
          break;
        } else {
          printf("Enter valid choice\n");
        }
      }
      if (strcmp(choice4, "1\n") == 0) {
        fp = fopen("data.txt", "a");
        fprintf(fp, "\n");
        fprintf(fp, "%s %s %s", CPassword, MobileNo, FullName);
        fclose(fp);
        break;
      }
      //if(strcmp(choice4,"2\n")==0);
    }
    if (K == 0) {
      printf("\n                        LOGIN SUCCESSFUL!!!\n");
    }
    while (1) {
      system("cls");
      char choos[50];
      printf("\n\n         ================SELECT ONE OF THE FOLLOWING OPTIONS==============\n\n");
      printf("    1.TICKET BOOKING\n\n    2.CANCELLATION\n\n    3.LOGOUT\n\n");
      while (1) {
        fgets(choos, 60, stdin);
        if (strcmp(choos, "1\n") == 0 || strcmp(choos, "2\n") == 0 || strcmp(choos, "3\n") == 0) {
          break;
        } else {
          printf("Enter valid choice\n");
        }
      }
      if (strcmp(choos, "1\n") == 0) {
        printf("\n\nEnter the following:\n\n");
        while (1) {
          printf("1.From:\n Enter one of the following places in capitals:\n 1.BANGALORE \n 2.DHARWAD\n 3.BALLARI\n 4.MYSORE\n 5.KOLAR\n 6.RAICHUR\n 7.YADGIR\n");
          fgets(from, 30, stdin);
          if (strcmp(from, "BANGALORE\n") == 0) {
            while (1) {
              printf("2.Destination:\n Enter one of the following places in capitals:\n 1.DHARWAD\n 2.BALLARI\n 3.MYSORE\n 4.KOLAR\n 5.RAICHUR\n 6.YADGIR\n");
              // in our system there are five destination of journey other than this no bus destination is available
              fgets(to, 30, stdin);
              if (strcmp(to, "YADGIR\n") == 0) {
                k = 642;
                break;
              } else if (strcmp(to, "DHARWAD\n") == 0) {
                k = 568;
                break;
              } else if (strcmp(to, "BALLARI\n") == 0) {
                k = 413;
                break;
              } else if (strcmp(to, "MYSORE\n") == 0) {
                k = 189;
                break;
              } else if (strcmp(to, "KOLAR\n") == 0) {
                k = 90;
                break;
              } else if (strcmp(to, "RAICHUR\n") == 0) {
                k = 543;
                break;
              } else {
                printf("BUS TO THIS PLACE IS NOT AVAILABLE.PLEASE TRY ENTERING ONE OF THE MENTIONED PLACES\n");
              }
            }
            break;
          } else if (strcmp(from, "DHARWAD\n") == 0) {
            while (1) {
              printf("2.Destination:\n Enter one of the following places in capitals:\n 1.BANGALORE\n 2.BALLARI\n 3.MYSORE\n 4.KOLAR\n 5.RAICHUR\n 6.YADGIR\n");
              fgets(to, 30, stdin);
              if (strcmp(to, "YADGIR\n") == 0) {
                k = 442;
                break;
              } else if (strcmp(to, "BANGALORE\n") == 0) {
                k = 568;
                break;
              } else if (strcmp(to, "BALLARI\n") == 0) {
                k = 304;
                break;
              } else if (strcmp(to, "MYSORE\n") == 0) {
                k = 678;
                break;
              } else if (strcmp(to, "KOLAR\n") == 0) {
                k = 651;
                break;
              } else if (strcmp(to, "RAICHUR\n") == 0) {
                k = 426;
                break;
              } else {
                printf("BUS TO THIS PLACE IS NOT AVAILABLE.PLEASE TRY ENTERING ONE OF THE MENTIONED PLACES\n");
              }
            }
            break;
          } else if (strcmp(from, "BALLARI\n") == 0) {
            while (1) {
              printf("2.Destination:\n Enter one of the following places in capitals:\n 1.DHARWAD\n 2.BANGALORE\n 3.MYSORE\n 4.KOLAR\n 5.RAICHUR\n 6.YADGIR\n");
              fgets(to, 30, stdin);
              if (strcmp(to, "YADGIR\n") == 0) {
                k = 294;
                break;
              } else if (strcmp(to, "DHARWAD\n") == 0) {
                k = 304;
                break;
              } else if (strcmp(to, "BANGALORE\n") == 0) {
                k = 413;
                break;
              } else if (strcmp(to, "MYSORE\n") == 0) {
                k = 513;
                break;
              } else if (strcmp(to, "KOLAR\n") == 0) {
                k = 423;
                break;
              } else if (strcmp(to, "RAICHUR\n") == 0) {
                k = 196;
                break;
              } else {
                printf("BUS TO THIS PLACE IS NOT AVAILABLE.PLEASE TRY ENTERING ONE OF THE MENTIONED PLACES\n");
              }
            }
            break;
          } else if (strcmp(from, "MYSORE\n") == 0) {
            while (1) {
              printf("2.Destination:\n Enter one of the following places in capitals:\n 1.DHARWAD\n 2.BALLARI\n 3.BANGALORE\n 4.KOLAR\n 5.RAICHUR\n 6.YADGIR\n");
              fgets(to, 30, stdin);
              if (strcmp(to, "YADGIR\n") == 0) {
                k = 842;
                break;
              } else if (strcmp(to, "DHARWAD\n") == 0) {
                k = 678;
                break;
              } else if (strcmp(to, "BALLARI\n") == 0) {
                k = 513;
                break;
              } else if (strcmp(to, "BANGALORE\n") == 0) {
                k = 189;
                break;
              } else if (strcmp(to, "KOLAR\n") == 0) {
                k = 331;
                break;
              } else if (strcmp(to, "RAICHUR\n") == 0) {
                k = 708;
                break;
              } else {
                printf("BUS TO THIS PLACE IS NOT AVAILABLE.PLEASE TRY ENTERING ONE OF THE MENTIONED PLACES\n");
              }
            }
            break;
          } else if (strcmp(from, "KOLAR\n") == 0) {
            while (1) {
              printf("2.Destination:\n Enter one of the following places in capitals:\n 1.DHARWAD\n 2.BALLARI\n 3.MYSORE\n 4.BANGALORE\n 5.RAICHUR\n 6.YADGIR\n");
              fgets(to, 30, stdin);
              if (strcmp(to, "YADGIR\n") == 0) {
                k = 659;
                break;
              } else if (strcmp(to, "DHARWAD\n") == 0) {
                k = 651;
                break;
              } else if (strcmp(to, "BALLARI\n") == 0) {
                k = 423;
                break;
              } else if (strcmp(to, "MYSORE\n") == 0) {
                k = 331;
                break;
              } else if (strcmp(to, "BANGALORE\n") == 0) {
                k = 90;
                break;
              } else if (strcmp(to, "RAICHUR\n") == 0) {
                k = 556;
                break;
              } else {
                printf("BUS TO THIS PLACE IS NOT AVAILABLE.PLEASE TRY ENTERING ONE OF THE MENTIONED PLACES\n");
              }
              //admin needs to type valid place for booking
            }
            break;
          } else if (strcmp(from, "RAICHUR\n") == 0) {
            while (1) {
              printf("2.Destination:\n Enter one of the following places in capitals:\n 1.DHARWAD\n 2.BALLARI\n 3.MYSORE\n 4.KOLAR\n 5.BANGALORE\n 6.YADGIR\n");
              fgets(to, 30, stdin);
              if (strcmp(to, "YADGIR\n") == 0) {
                k = 103;
                break;
              } else if (strcmp(to, "DHARWAD\n") == 0) {
                k = 426;
                break;
              } else if (strcmp(to, "BALLARI\n") == 0) {
                k = 196;
                break;
              } else if (strcmp(to, "MYSORE\n") == 0) {
                k = 708;
                break;
              } else if (strcmp(to, "KOLAR\n") == 0) {
                k = 556;
                break;
              } else if (strcmp(to, "BANGALORE\n") == 0) {
                k = 543;
                break;
              } else {
                printf("BUS TO THIS PLACE IS NOT AVAILABLE.PLEASE TRY ENTERING ONE OF THE MENTIONED PLACES\n");
              }
            }
            break;
          } else if (strcmp(from, "YADGIR\n") == 0) {
            while (1) {
              printf("2.Destination:\n Enter one of the following places in capitals:\n 1.DHARWAD\n 2.BALLARI\n 3.MYSORE\n 4.KOLAR\n 5.RAICHUR\n 6.BANGALORE\n");
              fgets(to, 30, stdin);
              if (strcmp(to, "BANGALORE\n") == 0) {
                k = 642;
                break;
              } else if (strcmp(to, "DHARWAD\n") == 0) {
                k = 442;
                break;
              } else if (strcmp(to, "BALLARI\n") == 0) {
                k = 294;
                break;
              } else if (strcmp(to, "MYSORE\n") == 0) {
                k = 842;
                break;
              } else if (strcmp(to, "KOLAR\n") == 0) {
                k = 659;
                break;
              } else if (strcmp(to, "RAICHUR\n") == 0) {
                k = 103;
                break;
              } else {
                printf("BUS TO THIS PLACE IS NOT AVAILABLE.PLEASE TRY ENTERING ONE OF THE MENTIONED PLACES\n");
              }
            }
            break;
          } else {
            printf("BUS FROM THIS PLACE IS NOT AVAILABLE.PLEASE TRY ENTERING ONE OF THE PLACES MENTIONED\n");
          }
        }
        int year, month, day, iday, imonth, iyear;
        char date[20], s1[3], s2[3], s3[5], s4[2] = "", s5[2] = "";
        time_t my_time = time(NULL);
        struct tm tm = * localtime( & my_time);
        day = tm.tm_mday;
        month = tm.tm_mon + 1;
        year = tm.tm_year + 1900;
        while (1) {
          printf("3.Date of journey(in dd/mm/yyyy format):\n");
          scanf("%s", date);
          strncpy(s1, date, 2);
          sscanf(s1, "%d", & iday);
          strncpy(s2, date + 3, 2);
          sscanf(s2, "%d", & imonth);
          strncpy(s3, date + 6, 4);
          sscanf(s3, "%d", & iyear);
          strncpy(s4, date + 2, 1);
          strncpy(s5, date + 5, 1);
          if (strlen(date) != 10 || strcmp(s4, "/") != 0 || strcmp(s5, "/") != 0 || imonth > 12 || imonth < 1 || iday < 1 || iday > 31) {
            printf("ENTER A VALID DATE ACCORDING TO THE FORMAT\n");
          } else if (imonth == 4 && iday > 30) {
            printf("ENTER A VALID DATE ACCORDING TO THE FORMAT\n");
          } else if (imonth == 6 && iday > 30) {
            printf("ENTER A VALID DATE ACCORDING TO THE FORMAT\n");
          } else if (imonth == 9 && iday > 30) {
            printf("ENTER A VALID DATE ACCORDING TO THE FORMAT\n");
          } else if (imonth == 11 && iday > 30) {
            printf("ENTER A VALID DATE ACCORDING TO THE FORMAT\n");
          } else if (imonth == 2 && iyear % 4 != 0 && iday > 28) {
            printf("ENTER A VALID DATE ACCORDING TO THE FORMAT\n");
          } else if (imonth == 2 && iyear % 4 == 0 && iday > 29) {
            printf("ENTER A VALID DATE ACCORDING TO THE FORMAT\n");
          } else {
            if (iyear < year) {
              printf("ENTER A VALID DATE \n");
            } else if (iyear == year) {
              if (imonth < month) {
                printf("ENTER A VALID DATE \n");
              }
              if (imonth == month) {
                if (iday < day) {
                  printf("ENTER A VALID DATE \n");
                }
                if (iday == day) {
                  printf("BOOKING MUST BE DONE ATLEAST A DAY BEFORE.ENTER ANOTHER DATE\n");
                }
                //booking must be done atleast a day  before bus scheduled
                if (iday > day) {
                  break;
                }
              }
              if (imonth > month) {
                break;
              }
            } else if (iyear == year + 1) {
              if (month >= 6) {
                break;
              }
              if (month < 6) {
                printf("BOOKING FOR THIS DATE IS NOT YET AVAILABLE.TRY AFTER FEW DAYS\n");
              }
            } else if (iyear > year + 1) {
              printf("BOOKING FOR THIS DATE IS NOT YET AVAILABLE.TRY AFTER FEW DAYS\n");
            }
          }
        }

        char choice[50];
        int bsm[36];
        int i, Book = 0, ichoice, B = 7, l, b_n, t, Reserv = 0;
        system("cls");
        printf("PLEASE ENTER THE CORRESPONDING BUS NUMBER TO SELECT THE BUS:\n\n");
        printf("   1.AIRAVAT EXPRESS\n   2.FLYBUS EXPRESS\n   3.SATHAVAHANA EXPRESS\n   4.SRI NAVADURGA EXPRESS\n   5.VOLVO CLUB CLASS EXPRESS\n\n");
        int flag = 1;
        while (1) {
          printf("ENTER VALID CHOICE : ");
          if (flag == 1) {
            char ch1 = getchar();
            flag++;
          }
          fgets(choice, 60, stdin);
          if (strcmp(choice, "1\n") == 0 || strcmp(choice, "2\n") == 0 || strcmp(choice, "3\n") == 0 || strcmp(choice, "4\n") == 0 || strcmp(choice, "5\n") == 0) {
            sscanf(choice, "%d", & ichoice);
            break;
          } else {
            printf("Enter valid choice\n");
          }
        }
        if (ichoice == 1) {
          printf("\n\n================AIRAVAT EXPRESS================\n");
          B = 0;
        }
        if (ichoice == 2) {
          printf("\n\n================FLYBUS EXPRESS================\n");
          B = 1;
        }
        if (ichoice == 3) {
          printf("\n\n================SATHAVAHANA EXPRESS================\n");
          B = 2;
        }
        if (ichoice == 4) {
          printf("\n\n================SRI NAVADURGA EXPRESS================\n");
          B = 3;
        }
        if (ichoice == 5) {
          printf("\n\n================VOLVO CLUB CLASS EXPRESS================\n");
          B = 4;
        }
        printf("\n***SEAT MATRIX**\n\n");
        //Default seat matrix//
        for (i = 0; i < 36; i++) {
          bsm[i] = 0;
        }
        FILE * fp;
        if (B == 0) {
          fp = fopen("Bus1.txt", "r");
        }
        if (B == 1) {
          fp = fopen("Bus2.txt", "r");
        }
        if (B == 2) {
          fp = fopen("Bus3.txt", "r");
        }
        if (B == 3) {
          fp = fopen("Bus4.txt", "r");
        }
        if (B == 4) {
          fp = fopen("Bus5.txt", "r");
        }
        Reserv = 0;
        while (fscanf(fp, "%d", & l) != EOF) {
          bsm[l - 1] = 2;
          Reserv++;
        }
        fclose(fp);
        //opening file and extracting seat numbers which are booked for specific bus number//
        if (B == 0) {
          fp = fopen("Booking1.txt", "r");
        }
        if (B == 1) {
          fp = fopen("Booking2.txt", "r");
        }
        if (B == 2) {
          fp = fopen("Booking3.txt", "r");
        }
        if (B == 3) {
          fp = fopen("Booking4.txt", "r");
        }
        if (B == 4) {
          fp = fopen("Booking5.txt", "r");
        }
        Book = 0;
        while (fscanf(fp, "%d", & t) != EOF) {
          bsm[t - 1] = 1;
          Book++;
        }
        fclose(fp);
        for (int i = 0; i < 36; i++) {
          if (bsm[i] == 0 && i < 9) {
            printf("%d . FREE\t", i + 1);
          }
          if (bsm[i] == 0 && i >= 9) {
            printf("%d. FREE\t", i + 1);
          }
          if (bsm[i] == 1 && i < 9) {
            printf("%d . BOOKED\t", i + 1);
          }
          if (bsm[i] == 1 && i >= 9) {
            printf("%d. BOOKED\t", i + 1);
          }
          if (bsm[i] == 2 && i < 9) {
            printf("%d . RESERVED\t", i + 1);
          }
          if (bsm[i] == 2 && i >= 9) {
            printf("%d. RESERVED\t", i + 1);
          }
          if ((i + 1) % 2 == 0) {
            printf("\t");
          }
          if ((i + 1) % 4 == 0) {
            printf("\n");
          }
        }
        char nop[50];
        int nop_, F;
        int b = Book;
        while (1) {
          int test = 0;
          printf("\n\nPLEASE ENTER THE NUMBER OF PASSENGERS: ");
          fgets(nop, 49, stdin);
          if (strlen(nop) == 2) {
            if (nop[0] >= 48 && nop[0] <= 57) {
              sscanf(nop, "%d", & nop_);
              test = 55;
            } else {
              printf("ENTER VALID NUMBER\n");
            }
          }
          if (strlen(nop) == 3) {
            if (nop[0] >= 48 && nop[0] <= 57 && nop[1] >= 48 && nop[1] <= 57) {
              sscanf(nop, "%d", & nop_);
              test = 55;
            } else {
              printf("ENTER VALID NUMBER\n");
            }
          }
          if (strlen(nop) < 2 || strlen(nop) > 3) {
            printf("ENTER VALID NUMBER\n");
          }
          if (test == 55) {
            if (nop_ > (36 - b - Reserv)) {
              printf("\nAVAILABLE SEATS ARE ONLY :%d\n", 36 - b - Reserv);
            }
            if (nop_ < 1) {
              printf("\nPLEASE ENTER VALID NUMBER\n");
            }
            if (nop_ < (36 - b - Reserv) && nop_ > 0) {
              break;
            }
          }
        }
        amount = k * nop_;
        system("cls");
        struct passengers passenger[nop_];
        //booking confirmed and now need passenger details
        for (int z = 0; z < nop_; z++) {
          printf("Enter the details of passenger%d:\n", z + 1);
          printf("1.First name:\n ");
          fgets(passenger[z].firstname, 100, stdin);
          printf("2.Last name:\n ");
          fgets(passenger[z].lastname, 100, stdin);
          printf("3.Gender:\n ");
          fgets(passenger[z].gender, 10, stdin);
          while (c >= 0) {
            printf("4.Mobile Number:");
            fgets(passenger[z].m_no, 40, stdin);
            q = 0;
            if (strlen(passenger[z].m_no) == 11) {
              for (b = 0; passenger[z].m_no[b] != '\0'; b++) {
                if (passenger[z].m_no[b] >= 48 && passenger[z].m_no[b] <= 57) {
                  q++;
                  continue;
                }
              }
              if ((q + 1) == strlen(passenger[z].m_no)) {
                break;
              } else {
                printf("Invalid Mobile No.\n\n");
              }
            } else {
              printf("Invalid Mobile No.\n\n");
            }
          }

          while (1) {
            int test = 0;
            printf("PLEASE ENTER THE SEAT NUMBER: ");
            fgets(passenger[z].seat, 49, stdin);
            if (strlen(passenger[z].seat) == 2) {
              if (passenger[z].seat[0] >= 48 && passenger[z].seat[0] <= 57) {
                sscanf(passenger[z].seat, "%d", & passenger[z].seat_);
                test = 55;
              } else {
                printf("ENTER VALID NUMBER\n");
              }
            }
            if (strlen(passenger[z].seat) == 3) {
              if (passenger[z].seat[0] >= 48 && passenger[z].seat[0] <= 57 && passenger[z].seat[1] >= 48 && passenger[z].seat[1] <= 57) {
                sscanf(passenger[z].seat, "%d", & passenger[z].seat_);
                test = 55;
              } else {
                printf("ENTER VALID NUMBER\n");
              }
            }
            if (strlen(passenger[z].seat) < 2 || strlen(passenger[z].seat) > 3) {
              printf("ENTER VALID NUMBER\n");
            }
            if (test == 55) {
              if ((passenger[z].seat_) > 36 || (passenger[z].seat_) < 1) {
                printf("\nENTER A VALID SEAT NUMBER\n");
              } else {
                if (bsm[(passenger[z].seat_) - 1] == 2) {
                  printf("\nTHIS SEAT IS RESERVED\n");
                }
                if (bsm[(passenger[z].seat_) - 1] == 1) {
                  printf("\nTHIS SEAT IS ALREADY BOOKED\n");
                }
                if (bsm[(passenger[z].seat_) - 1] == 0) {
                  bsm[(passenger[z].seat_) - 1] = 1;
                  passenger[z].bookedseats = passenger[z].seat_;
                  b++;
                  break;
                }
              }

            }

          }
        }
        system("cls");
        printf("\n\n\n                                YOUR BOOKING IS CONFIRMED!!\n\n\n");
        sscanf(bn[B], "%d", & b_n);
        printf("            -----        BUS NUMBER : %d        ------\n", b_n);
        for (z = 0; z < nop_; z++) {
          printf("PASSENGER %d :\n", z + 1);
          printf("1.First Name      : %s", passenger[z].firstname);
          printf("2.Last Name       : %s", passenger[z].lastname);
          printf("3.Gender          : %s", passenger[z].gender);
          printf("4.Date of journey : %s\n", date);
          printf("5.Traveling from  : %s", from);
          printf("6.Destination     : %s", to);
          printf("7.Seat Booked     : %d\n", passenger[z].seat_);
          printf("8.Mobile Number   : %s\n", passenger[z].m_no);
          printf("\n");
        }
        printf("\n\n                                  Total amount to be paid is Rs.%d\n", amount);
        //it will show total amount to be paid by the customer
        int p, f, h = 0;
        char c_no[20], cvv[10];
        q = 0;
        while (1) {
          printf("PAYMENT OPTIONS:\n1--->CREDIT CARD\n2--->DEBIT CARD\n");
          //payment can be paid by debit and credit card also by entering card number and cvv code
          printf("Enter the digit corresponding to your option:\n");
          scanf("%d", & p);
          if (p == 1 || p == 2) {
            int flag = 0;
            while (1) {
              printf("Enter card number:\n");
              if (flag == 0) {
                char ch2 = getchar();
                flag++;
              }
              fgets(c_no, 20, stdin);
              if (strlen(c_no) == 17) {
                for (b = 0; c_no[b] != '\0'; b++) {
                  if (c_no[b] >= 48 && c_no[b] <= 57) {
                    q++;
                    continue;
                  }
                }
                if ((q + 1) == strlen(c_no)) {
                  break;
                } else {
                  printf("Invalid card number\n\n");
                }
              } else {
                printf("Invalid card number.\n\n");
              }
            }
            while (1) {
              printf("Enter cvv code:\n");
              fgets(cvv, 10, stdin);
              if (strlen(cvv) == 4) {
                for (b = 0; cvv[b] != '\0'; b++) {
                  if (cvv[b] >= 48 && cvv[b] <= 57) {
                    h++;
                    continue;
                  }
                }
                if ((h + 1) == strlen(cvv)) {
                  break;
                } else {
                  printf("Invalid cvv code.\n\n");
                }
              } else {
                printf("Invalid cvv code.\n\n");
              }
            }
            while (1) {
              printf("PAY Rs.%d\n", amount);
              printf("Enter 1 to confirm\n ");
              scanf("%d", & f);
              if (f == 1) {
                printf("                              PAYMENT SUCCESSFULL!!\n");
                FILE * pf = NULL;
                char userfile[255];
                if (strcmp(choice1, "1\n") == 0) {
                  sprintf(userfile, "%s.txt", Mno);
                  fp = fopen(userfile, "a");
                  for (z = 0; z < nop_; z++) {
                    fprintf(fp, "%d ", b_n);
                    F = passenger[z].seat_;
                    fprintf(fp, "%d ", F);
                    fprintf(fp, "\n");
                  }
                  fclose(fp);
                } else if (strcmp(choice1, "2\n") == 0) {
                  sprintf(userfile, "%s.txt", MobileNo);
                  fp = fopen(userfile, "a");
                  fprintf(fp, "%d ", b_n);
                  for (z = 0; z < nop_; z++) {
                    F = passenger[z].seat_;
                    fprintf(fp, "%d ", F);
                  }
                  fclose(fp);
                }
                if (B == 0) {
                  fp = fopen("Booking1.txt", "a");
                }
                if (B == 1) {
                  fp = fopen("Booking2.txt", "a");
                }
                if (B == 2) {
                  fp = fopen("Booking3.txt", "a");
                }
                if (B == 3) {
                  fp = fopen("Booking4.txt", "a");
                }
                if (B == 4) {
                  fp = fopen("Booking5.txt", "a");
                }
                for (z = 0; z < nop_; z++) {
                  F = passenger[z].seat_;
                  fprintf(fp, "%d ", F);
                }
                fclose(fp);
                break;
              } else {
                printf("PLEASE CONFIRM YOUR PAYMENT\n");
              }
            }
            break;
          } else {
            printf("Enter a valid digit\n");
          }
        }
        if (f == 1) {

          char r1[5];
          int r_;
          printf("                       Please rate us\n");
          // customers can rate as per their experience
          int flag1 = 0;
          while (1) {
            printf("Enter a number from 1 to 5 according to your experience\n");
            if (flag1 == 0) {
              char ch3 = getchar();
              flag1++;
            }
            fgets(r1, 4, stdin);
            if (strlen(r1) == 2) {
              if (r1[0] > 48 && r1[0] <= 53) {
                printf("THANK YOU FOR RATING US.\n");
                break;
              } else {
                printf("Invalid digit.\n\n");
              }
            } else {
              printf("Invalid digit.\n\n");
            }
          }
          sscanf(r1, "%d", & r_);
          FILE * my_file;
          my_file = fopen("Review.txt", "a");
          fprintf(my_file, "reviews %d\n", r_);
          fclose(my_file);

          char random[50];
          printf("PRESS ENTER TO CONTINUE");
          fgets(random, 49, stdin);
        }
      }
      if (strcmp(choos, "2\n") == 0) {
        printf("\n\n\n                        CANCELLATION\n\n\n");
        char cancel[50];
        char file[200];
        int L, S, aa, j;
        int count;
        printf("ENTER '1' TO CANCEL YOUR BOOKING OR PRESS ANOTHER KEY TO CONTINUE\n");
        //if user wants to cancel the booked tickets ,he/she can do so by giving bank details where refund will be done
        fgets(cancel, 49, stdin);
        if (cancel[0] == 49) {
          if (strcmp(choice1, "1\n") == 0) {
            sprintf(file, "%s.txt", Mno);
          } else if (strcmp(choice1, "2\n") == 0) {
            sprintf(file, "%s.txt", MobileNo);
          }
          fp = fopen(file, "r");
          int seats_c[36];
          printf("Available bookings : \n");
          int buses[50], index3 = 0;
          while (fscanf(fp, "%d", & L) != EOF) {
            count = (L == 0) ? 1 : log10(L) + 1;
            if (count == 4) {
              buses[index3++] = L;
            }
          }
          fclose(fp);
          for (int i = 0; i < index3; i++) {
            int j;
            for (j = 0; j < i; j++)
              if (buses[i] == buses[j])
                break;
            if (i == j)
              printf("Bus Number : %d \n", buses[i]);
          }
          if (buses[0] == '\0') {
            printf("\nNo Bookings Available\n");
            printf("\nPress any key to continue");
            getch();
            continue;
          }
          int cbus, index4 = 0, index5 = 0, index6 = 0, index7 = 0, index8 = 0, index0 = 0, GB = 1;
          B1 = 0, B2 = 0, B3 = 0, B4 = 0, B5 = 0;
          while (1) {
            printf("Select Bus Number : ");
            scanf("%d", & cbus);
            for (i = 0; i < index3; i++) {
              if (cbus == buses[i]) {
                GB = 0;
                break;
              }
            }
            if (GB == 0) {
              break;
            } else {
              printf("Enter valid bus number\n");
            }
          }
          fp = fopen(file, "r");
          while (fscanf(fp, "%d", & L) != EOF) {
            if (L == 7032) {
              B1 = 1;
            }
            count = (L == 0) ? 1 : log10(L) + 1;
            if (count == 4) {
              if (L != 7032) {
                B1 = 0;
                continue;
              }
            }
            if (B1 > 1) {
              count = (L == 0) ? 1 : log10(L) + 1;
              if (count == 4) {
                break;
              }
              bus7032[index4++] = L;
            }
            B1++;
          }
          fclose(fp);
          fp = fopen(file, "r");
          while (fscanf(fp, "%d", & L) != EOF) {
            if (L == 5689) {
              B2 = 1;
            }
            count = (L == 0) ? 1 : log10(L) + 1;
            if (count == 4) {
              if (L != 5689) {
                B2 = 0;
                continue;
              }
            }
            if (B2 > 1) {
              count = (L == 0) ? 1 : log10(L) + 1;
              if (count == 4) {
                break;
              }
              bus5689[index5++] = L;
            }
            B2++;
          }
          fclose(fp);
          fp = fopen(file, "r");
          while (fscanf(fp, "%d", & L) != EOF) {
            if (L == 8631) {
              B3 = 1;
            }
            if (count == 4) {
              if (L != 8631) {
                B3 = 0;
                continue;
              }
            }
            if (B3 > 1) {
              count = (L == 0) ? 1 : log10(L) + 1;
              if (count == 4) {
                break;
              }
              bus8631[index6++] = L;
            }
            B3++;
          }
          fp = fopen(file, "r");
          while (fscanf(fp, "%d", & L) != EOF) {
            if (L == 7562) {
              B4 = 1;
            }
            if (count == 4) {
              if (L != 7562) {
                B4 = 0;
                continue;
              }
            }
            if (B4 > 1) {
              count = (L == 0) ? 1 : log10(L) + 1;
              if (count == 4) {
                break;
              }
              bus7562[index7++] = L;
            }
            B4++;
          }
          fclose(fp);
          fp = fopen(file, "r");
          while (fscanf(fp, "%d", & L) != EOF) {
            if (L == 6442) {
              B5 = 1;
            }
            if (count == 4) {
              if (L != 6442) {
                B5 = 0;
                continue;
              }
            }
            if (B5 > 1) {
              count = (L == 0) ? 1 : log10(L) + 1;
              if (count == 4) {
                break;
              }
              bus6442[index8++] = L;
            }
            B5++;
          }
          fclose(fp);
          if (cbus == 7032) {
            S = 0;
            for (i = 0; i < index4; i++) {
              printf("Booked seat : %d\n", bus7032[i]);
              seats_c[i] = bus7032[i];
            }
            index0 = index4;
          }
          if (cbus == 5689) {
            S = 1;
            for (i = 0; i < index5; i++) {
              printf("Booked seat : %d\n", bus5689[i]);
              seats_c[i] = bus5689[i];
            }
            index0 = index5;
          }
          if (cbus == 8631) {
            S = 2;
            for (i = 0; i < index6; i++) {
              printf("Booked seat : %d\n", bus8631[i]);
              seats_c[i] = bus8631[i];
            }
            index0 = index6;
          }
          if (cbus == 7562) {
            S = 3;
            for (i = 0; i < index7; i++) {
              printf("Booked seat : %d\n", bus7562[i]);
              seats_c[i] = bus7562[i];
            }
            index0 = index7;
          }
          if (cbus == 6442) {
            S = 4;
            for (i = 0; i < index8; i++) {
              printf("Booked seat : %d\n", bus6442[i]);
              seats_c[i] = bus6442[i];
            }
            index0 = index8;
          }
          int v = 0, seats_u[36], found;
          while (1) {
            printf("Number of seats to be cancelled : ");
            scanf("%d", & v);
            if (v <= index0) {
              break;
            } else {
              printf("Enter valid number\n");
            }
          }
          for (i = 0; i < v; i++) {
            printf("Enter seat number :");
            scanf("%d", & seats_u[i]);
          }
          int updatedseats[36];
          int u = 0;
          for (i = 0; i < index0; i++) {
            aa = seats_c[i];
            found = 0;
            for (j = 0; j < v; j++) {
              if (aa == seats_u[j]) {
                found = 1;
                break;
              }
            }
            if (found == 0) {
              updatedseats[u] = aa;
              u++;
            }
          }
          if (cbus == 7032) {
            for (i = 0; i < index4; i++) {
              bus7032[i] = '\0';
            }
            for (i = 0; i < u; i++) {
              bus7032[i] = updatedseats[i];
            }
            index4 = u;
          }
          if (cbus == 5689) {
            for (i = 0; i < index5; i++) {
              bus5689[i] = '\0';
            }
            for (i = 0; i < u; i++) {
              bus5689[i] = updatedseats[i];
            }
            index5 = u;
          }
          if (cbus == 8631) {
            for (i = 0; i < index6; i++) {
              bus8631[i] = '\0';
            }
            for (i = 0; i < u; i++) {
              bus8631[i] = updatedseats[i];
            }
            index6 = u;
          }
          if (cbus == 7562) {
            for (i = 0; i < index7; i++) {
              bus7562[i] = '\0';
            }
            for (i = 0; i < u; i++) {
              bus7562[i] = updatedseats[i];
            }
            index7 = u;
          }
          if (cbus == 6442) {
            for (i = 0; i < index8; i++) {
              bus6442[i] = '\0';
            }
            for (i = 0; i < u; i++) {
              bus6442[i] = updatedseats[i];
            }
            index8 = u;
          }
          int booking[100], ind = 0;
          if (S == 0) {
            fp = fopen("Booking1.txt", "r");
          }
          if (S == 1) {
            fp = fopen("Booking2.txt", "r");
          }
          if (S == 2) {
            fp = fopen("Booking3.txt", "r");
          }
          if (S == 3) {
            fp = fopen("Booking4.txt", "r");
          }
          if (S == 4) {
            fp = fopen("Booking5.txt", "r");
          }
          while (fscanf(fp, "%d", & L) != EOF) {
            booking[ind++] = L;
          }
          printf("\n\n        *REFUND INFORMATION*\n\n");

          printf("Enter Account Holder Name :");
          char ch5 = getchar();
          fgets(account_holder_name, 100, stdin);
          int flag = 0;
          while (1) {
            printf("Enter Account No. :");
            if (flag == 0) {
              char ch4 = getchar();
              flag++;
            }
            fgets(Acc_No, 100, stdin);
            a = 0;
            for (i = 0; Acc_No[i] != '\0'; i++) {
              if (Acc_No[i] >= 48 && Acc_No[i] <= 57) {
                a++;
              }
            }
            if (strlen(Acc_No) == (a + 1)) {
              break;
            } else {
              printf("Enter valid Account No.\n");
            }
          }
          //by entering account holder name,account number,branch name ,IFSC code money will be refunded in respective bank
          printf("Branch Name :");
          fgets(Branch_Name, 100, stdin);
          printf("IFSE Code :");
          fgets(IFSE_Code, 100, stdin);
          int updatedbooking[50];
          int r = 0;
          for (i = 0; i < ind; i++) {
            aa = booking[i];
            found = 0;
            for (j = 0; j < v; j++) {
              if (aa == seats_u[j]) {
                found = 1;
                break;
              }
            }
            if (found == 0) {
              updatedbooking[r] = aa;
              r++;
            }
          }
          if (S == 0) {
            fp = fopen("Booking1.txt", "w");
          }
          if (S == 1) {
            fp = fopen("Booking2.txt", "w");
          }
          if (S == 2) {
            fp = fopen("Booking3.txt", "w");
          }
          if (S == 3) {
            fp = fopen("Booking4.txt", "w");
          }
          if (S == 4) {
            fp = fopen("Booking5.txt", "w");
          }
          for (i = 0; i < r; i++) {
            fprintf(fp, "%d ", updatedbooking[i]);
          }
          fclose(fp);
          if (strcmp(choice1, "1\n") == 0) {
            sprintf(file, "%s.txt", Mno);
          } else if (strcmp(choice1, "2\n") == 0) {
            sprintf(file, "%s.txt", MobileNo);
          }
          fp = fopen(file, "w");
          if (index4 > 0) {
            for (i = 0; i < index4; i++) {
              fprintf(fp, "7032 %d", bus7032[i]);
              fprintf(fp, "\n");
            }
          }
          if (index5 > 0) {
            for (i = 0; i < index5; i++) {
              fprintf(fp, "5689 %d", bus5689[i]);
              fprintf(fp, "\n");
            }
          }
          if (index6 > 0) {
            for (i = 0; i < index6; i++) {
              fprintf(fp, "8631 %d", bus8631[i]);
              fprintf(fp, "\n");
            }
          }
          if (index7 > 0) {
            for (i = 0; i < index7; i++) {
              fprintf(fp, "7562 %d", bus7562[i]);
              fprintf(fp, "\n");
            }
          }
          if (index8 > 0) {
            for (i = 0; i < index8; i++) {
              fprintf(fp, "6442 %d", bus6442[i]);
              fprintf(fp, "\n");
            }
          }
          fclose(fp);
          printf("AMOUNT WILL BE CREDITED IN YOUR BANK ACCOUNT IN 7 WORKING DAYS\n\n");
          //amount will be refunded within seven days of working
          printf("ENTER ANY KEY TO RETURN TO MAIN PAGE");
          getch();
        }
      }
      if (strcmp(choos, "3\n") == 0) {
        break;
      }
    }
  }
}
