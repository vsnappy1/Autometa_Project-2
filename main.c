#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Vishal B16101182 Assignment-2
//Objective: Write a program which takes a valid Alphabet input and a string and check whether string is accepted for Alphabet or not

char firstChar(char A[]){                       //This returns the first character of a string
    return A[0];
}
int main()
{
    int i=0,j,k,l,n,lengthS,isTrue=1,check1=1;
    char str1[50], temp[10], firstCharOfString, firstCharOfLetter;

    printf("Enter Valid Alphabet = { ");
	scanf("%s",str1);					        //this takes string input Alphabet seperated by ,
	int count=1;

	for( j=0;j<strlen(str1);j++){		        //This counts the number of elements in Alphabet
		if(str1[j]==','){
			count++;
		}
	}
	n=count;

	// Returns first token
    char* token = strtok(str1, ",");

  	char *A[n];
    while (token != NULL) { 				    //This fills the array with elements
    	A[i]=(char*)malloc(10);
    	strcpy (A[i], token);
        token = strtok(NULL, ",");
        i++;
    }

    printf("\nEnter Valid String : ");          //Take string input
    scanf("%s",str1);
    printf("\nTokens : ");
    for(i=0;i<strlen(str1) ;)                   //This is the main loop which run till length of string
        {
            firstCharOfString=str1[i];          //firstCharOfString contains first character of token
            for( j=0;j<n;){                     //This loop searches for letters in Alphabet which appears in string

                if(firstCharOfString==firstChar(A[j])){     /*when first character of string and letter matches, that letter/Token is selected
                                                                and it is processed for further operations*/
                    check1=0;                               //this 'check1' is to ensure that infinity loop should not occur
                    strcpy (temp, A[j]);                    //this copies the selected letter into temp variable
                    for( k=0;k<strlen(A[j]);k++){           //This confirms that letter present in string is complete(equal to selected token) or not
                        if(str1[i]!=temp[k]){
                            isTrue=0;           //isTrue = 0 means that letter of string is not present in Alphabet
                             break;
                        }
                        i++;
                        printf("%c",temp[k]);   //This breaks the string into tokens and print it
                    }
                    printf(" ");
                    j++;
                }
                else{                           //this else statement runs when character of string is not found in Alphabet
                    j++;                        //since condition is failed we have to check other letters of Alphabet
                    if(j==n && check1==1){      //when all letters are compared and none matched than this statement will run
                        isTrue=0;
                        break;
                    }
                }
            }
            check1=1;
            if(isTrue==0)
                break;
        }

    printf("\n\n");                            //For Printing the result
    if(isTrue==1)
        printf("Valid String");
    else
        printf("Invalid String");
    printf("\n\n");



    return 0;
}
