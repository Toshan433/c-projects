#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string encrypt(string pt, int k);
bool numric(string s);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    key = key%26;

    if (!numric(argv[1]))
    {
        printf("Error: key must be digit.\n");
        return 1;
    }

    string ptext = get_string("Plaintext: ");

    string ctext = encrypt(ptext, key);

    printf("Ciphertext: %s\n", ctext);

}

string encrypt(string pt, int k)
{
    int length = strlen(pt);

    for(int i = 0; i < length; i++)
    {
        if(isupper(pt[i]))
        {
             pt[i] = ((pt[i]-'A' + k)%26) + 'A';
        }

        else if(islower(pt[i]))
        {
            pt[i] = ((pt[i]-'a' + k)%26) + 'a';
        }

    }

    return pt;
}

bool numric(string s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

