# include <stdio.h>

#define LOW 1                            //Symbolic constant defined at start of file
#define HIGH 50


int main(void)
{
    for (int i = LOW; i <= HIGH; ++i)
        printf("%d\n", i);

    return 0;
}
