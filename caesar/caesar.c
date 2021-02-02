#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



// main function - k must be a non-negative integer.
int main(int argc, string argv[])
{

    //Initialising variables for plaintext  and ciphertext
    string p;

    // Test to check output of params and variables are correct.
    //printf("argc =  %i, argv = %s, k = %i\n", argc, argv[1], k);

    // Checks that 2 arguments are passed for the parameters and returns an error if there is more or less than required.
    // Also checks that k is an int
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    if (argc == 2) // && isdigit(*argv[1]))
    {
        // If user inputs correctly, Success is printed.
        printf("Success\n");

        // Using atoi function - converts a numeric string.
        int k = atoi(argv[1]);

        // Requests message from user and stores in variable p
        p = get_string("Plaintext: ");

        // For loop to loop through each character and move it one place to begin
        char c[strlen(p)];

        printf("ciphertext:"); // start print statement for result

        for (int i = 0, n = strlen(p); i < n; i++)
        {

            // checks for leter in alphabet
            if (isalpha(p[i]))
            {
                char a = 'A'; // Uses ASCII code for Uppercase A

                if islower(p[i])
                {
                    a = 'a'; // Uses ASCII code for lowercase a
                }
                // uses formula to check the new character and then adds to c array
                c[i] = ((((p[i] - a) + k) % 26) + a);
                printf("%c", c[i]);
            }
            else
            {
                // If not in alphabet, add char to c array
                c[i] = p[i];
                printf("%c", c[i]);
            }
        }


        printf("\n");

        return 0;
    }
    else
    {
        // Error message - instructs correct use of program.
        printf("Usage: ./caesar key\n");
        // returns 1 to note an error.
        return 1;
    }

}
