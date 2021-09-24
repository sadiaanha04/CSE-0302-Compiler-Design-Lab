#include <stdio.h>
#include <stdlib.h>

FILE *fp , *fp2;

void check_comment(char a)
{
    char x;

    if( a == '/')   //checking if the character starts with '/', it will be a comment
    {
        if((x=fgetc(fp))=='*')
         check_block_comment();

        else if( x == '/')   // else if the next character '/', it is the beginning of single line comment
        {
          check_single_comment();

        }
        else
        {
            // when both the cases fail then it is not a comment
            fputc(a,fp2);
            fputc(x,fp2);
        }
    }

    // when all the conditions are false, add the character as it is in the new file.
    else
        fputc(a,fp2);
}


// function for block comments
void check_block_comment()
{

 char x,y;

    while((x=fgetc(fp))!=EOF)   // the block comment has started
    {

        if(x=='*')
        {
            y=fgetc(fp);  // check if it ends

            if(y=='/')
                return;
        }
   }

}


// function for single line comments
void check_single_comment()
{
 char x,y;

    while((x=fgetc(fp))!=EOF)
    {

        if(x=='\n')
            return;  // if the comment ends return from the function

    }

}


int main(void)
{
    char c;

    fp = fopen ("testfile.txt","r") ;   // first file in read mode
    fp2 = fopen ("solved.txt","w") ;    // second file in write mode

    while(
          (c=fgetc(fp))!=EOF)
        check_comment(c);   // checking for the beginning of a comment

     //  closing both files
    fclose(fp);
    fclose(fp2);

    return 0;
}
