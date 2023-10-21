#include <stdio.h>
#include <string.h>
#include <math.h>

int num[5];
void numbers(int );

int main (void) {
    int words[100];
    int accumulator;
    printf("***  Welcome to Simpletron!  ***\n");
    printf("***  Please enter your program one instruction  ***\n");
    printf("***  (or data word) at a time. I will type the  ***\n");
    printf("***  location number and a question mark (?).  ***\n");
    printf("***  You then type the word for that location.  ***\n");
    printf("***  Type the sentinel -99999 to stop entering  ***\n");
    printf("***  your program.  ***\n\n");

    for (int i=00; i<100; i++) {
     //   printf("enter your command(must be a positive value): ");
        printf("%d  ?  ", i);
        scanf("%d", &words[i]);
        numbers(words[i]);
        //READ 10
        if (num[3]==1 && num[2]==0) {
            //printf("enter value for your word(can be positive or negative): ");
            scanf("%d", &words[num[4]]);
        }
        //WRITE 11
        else if (num[3]==1 && num[2]==1) {
            printf("%d\n", words[num[4]]);
        }
        //LOAD 20
        else if (num[3]==2 && num[2]==0) {
            accumulator=words[num[4]];
        }
        //STORE 21
        else if (num[3]==2 && num[2]==1) {
            words[num[4]]= accumulator;
        }
        //ADD 30
        else if (num[3]==3 && num[2]==0) {
            accumulator+=words[num[4]];
        }
        //SUBTRACT 31
        else if (num[3]==3 && num[2]==1) {
            accumulator-=words[num[4]];;
        }
        //DIVIDE 32
        else if (num[3]==3 && num[2]==2) {
            accumulator/=words[num[4]];
        }
        //MULTIPLY 33
        else if (num[3]==3 && num[2]==3) {
            accumulator*=words[num[4]];
        }
        //BRANCH 40
        else if (num[3]==4 && num[2]==0) {
            accumulator=words[num[4]];
         /*   int *wordsi= &words[i];
            int *num1= &num[4];
            *wordsi=*num1; */
        }
        //BRANCHNEG 41
        else if (num[3]==4 && num[2]==1) {
            if (accumulator<0) {
                accumulator=words[num[4]];
            }
        }
        //BRANCHZERO 42
        else if (num[3]==4 && num[2]==2) {
            if (accumulator==0) {
                accumulator=words[num[4]];
            }
        }
        //HALT 43
        else if (num[3]==4 && num[2]==3) {
          //  words[i]=0, num[1]=0, num[2]=0, num[3]=0, num[4]=0, 
          accumulator=0;  
        }
        else if (num[3]==0) {
            printf("ENTER A VALID COMMAND(YOUR COMMAND IS OUT OF BOUNDS) \n");
            printf("ONLY FOUR DIGIT NUMBERS ARE ALLOWED! \n\n");
        }
        else {
            printf("***  Program loading completed  ***\n");
            printf("***  Program execution begins  ***\n");
            break;
        }
    }    
}

void numbers (int words) {
    int number=words;
    num[0]= number%10;
    num[1]= ((number%100)-num[0])/10;
    num[2]= ((number%1000)-num[1]-num[0])/100;
    num[3]= ((number%10000)-num[2]-num[1]-num[0])/1000;
    num[4]= (num[1]*10) + num[0];
    //printf("%d   %d   %d   %d   %d\n", num[0], num[1], num[2], num[3], num[4]); //WAS HERE FOR TESTS
}


