/*
 *Author: Jorge Sirias
 *Professor Caryl Rahn
 *COP 4338
 *
 *Purpose: To develop a C program that converts an int to its binary representation 
 *and allows the iser to set or clear the bit via the use of bitwise operations
 *
 * I affirm that I wrote this program myself without help from people or the internet
 **/

#include <stdio.h>
#include <stdlib.h>

//Function that converts a decimal number to a binary number 
char* decToBin(int numToDivide)
{

  char* newBinNum = (char*)malloc(32+1);

  int val, index;

  int counter = 0; 

  for(index = 31; index >=0; index--)
  {
   
    val = numToDivide >> index; //Shifts right the number that was passed from user by index amount 

    if(val & 1) 
    {
      *(newBinNum + counter) = 1 + '0';  //Stores 1 bit in designated index of char array
    }
    else
    {
      *(newBinNum + counter) = 0 + '0';
    } 

    counter++;

  }  

  //printf("Exiting decToBin function\n");

  *(newBinNum + counter) = '\0';

  return newBinNum;

}

//Function that sets or clears a bit
char* setClearBit(char* binNum, char chr, int index)
{
  //printf("\nInside setClearBit function\n");
  if(chr == 's')
  {
    *(binNum + index) = 1 + '0'; 
  }
  else if(chr == 'c')
  {
    *(binNum + index) = 0 + '0';
  }

  return binNum;

}

int main()
{

  char chrInput = 'Y'; //Variable that holds the char value to keep the program running
  char* binNum;       //char array that represents a binary number up to 32 bits

  unsigned int userInput; //Variable that holds integer value provided by user 

  printf("Hello and welcome to the bitops program\n");

  //While loop that keeps running until user enters any other key that is not Y or y
  while( chrInput == 'Y' || chrInput == 'y'  )
  {

    printf("Please choose a number within 1 to 1000 inclusively:\n");
    scanf("%d", &userInput);
    getchar();

    if( userInput >= 1 && userInput <= 1000  )
    {

      //Call method to convert number to binary 
      binNum = decToBin(userInput);

      printf("%d is %s in binary.\nWould you like to set a bit enter [s] or clear a bit enter [c]\n", userInput, binNum);
      scanf("%c", &chrInput);
      getchar();

      if( (chrInput == 'c') || (chrInput == 's') )
      {
        printf("Please specify which bit you would like to set or clear using integer value from 0 to 31.\n");
        scanf("%d", &userInput);
        getchar();      
      
        binNum = setClearBit(binNum, chrInput, userInput);
        printf("After setting/clearing a bit:\n\t%s\n", binNum);

      }
      else
      {
        printf("Please choose either [c] or [s]\n");
      }

    }
    else  //Program ends if int is outside of range
    {
      printf("Please choose a number between 1 & 1000 inclusively and try again.\n");
      exit(0);
    }

    //printf("%s", binNum);
    printf("Would you like to keep going? Press [Y] or [y], otherwise hit any key to exit:\n");
    scanf(" %c", &chrInput);
    getchar();
 
    //Valifates if user wants to keep running th eprogram.
    if( !((chrInput != 'Y') || (chrInput != 'y')) )
    {
      chrInput = 0;
    }

  }//End of while loop

  free(binNum);
  return 0; 

}
