// An implementation of the Ceaser Cipher's Encryption Algorithm. 
/* Replaces each letter in a message with another 
   letter that is at a fixed number of positions 
   from that letter in the Alphabet. . . For example; A ~> D (three shifts)*/

#include"myheader.h"

void ceaser(char message[], char shift_amount)
{
printf("Encrypted Message:\n");
for(int i=0;i< strlen(message);i++)
{ 
    /*Converts each character to ASCII 
    by subtracting it from 'A'(uppercase) or 'a' 
    You could as well run this..  { char c; 
                                    printf("%d",c);
    to see the ASCII representation of each letter. } 
    Then add 'A' or 'a' after conversion*/

    if(message[i]>='A' && message[i]<='Z')
    {
        printf("%c", ((message[i]-'A')+shift_amount) %26 +'A');  
    }
    else if (message[i]>='a' && message[i]<='z')
    {
        printf("%c", ((message[i]-'a')+shift_amount) %26 +'a');

    }
    else 
    printf("%c", message[i]);
}
}

int main( int argv, char **argc)
{
    char ch, message[100]= {0};
    int shift_amount;
    printf("Enter the message to be encrypted\n");
    for(int i=0; (ch = getchar())!='\n' && i<90;i++ ) 
    {
        message[i]=ch;
    }
    printf("Enter shift amount\n");
    scanf("%d", &shift_amount);

    ceaser(message, shift_amount);
return 0;
}
