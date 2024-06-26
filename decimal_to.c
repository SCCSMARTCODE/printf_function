
#include "printf.h"

/**
 * decimal_to - Converts an integer to a string representation in a specified base
 * @num: The integer to convert
 * @base: The base to convert to (between 2 and 16)
 * Return: A string representation of the number in the specified base
 */
char *decimal_to(int num, int base) {
    char rem_str[2] = {'\0', '\0'};
    int rem;
    size_t x = 0;
    size_t index = 0;
    char *output_str = malloc(sizeof(char) * 33);
    char *output_str_inv = malloc(sizeof(char) * 33);

    
    if (base < 2 || base > 16) {
        return NULL; 
    }

    if (output_str == NULL || output_str_inv == NULL) {
        free(output_str);
        free(output_str_inv);
        return NULL;
    }
    

    if (num == 0) {
        strcpy(output_str, "0");
    } else {
        while (num > 0) {
            rem = num % base;
            num /= base;
            if (rem > 9) {
                rem_str[0] = 'a' + (rem - 10);
            } else {
                rem_str[0] = '0' + rem;
            }
            strcat(output_str, rem_str);
        }
    }

    index = strlen(output_str);
    for (x = 0; x < index; x++) {
        output_str_inv[x] = output_str[index - x - 1];
    }
    output_str_inv[x] = '\0'; 

    free(output_str);
    return output_str_inv;
}

/**
 * cap_hex_str - capitalize hexadecimal string
 * @hex_str: The hex string to capitalize
 * Return: cap_hex_str
 */
char *cap_hex_str(char *hex_str)
{
    size_t i;
    char *cap_hex_str = malloc(sizeof(char) * 33);
    
    if (cap_hex_str == NULL)
    {
        return (NULL);
    }
    
    for (i = 0; i < strlen(hex_str); i++)
        {
            if (hex_str[i] >= 'a' && hex_str[i] <= 'f')
            {
                cap_hex_str[i] = hex_str[i] - 32;
            }
            else{
                cap_hex_str[i] = hex_str[i];
            }
        }
    return (cap_hex_str);
}
