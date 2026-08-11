#include <cs50.h>
#include <stdio.h>

bool validity_check(long long card_number);
int length_check(long long n);
bool checksum(long long card_number);
void print_cc_brand(long long ccn);

int main(void)
{
    long long cc_number;
    do
    {
        // Prompt user for Credit Card number
        cc_number = get_long_long("Number: ");
    }
    while (cc_number < 0);

    if (validity_check(cc_number) == true)
    {
        print_cc_brand(cc_number);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool validity_check(long long card_number)
{
    int len = length_check(card_number);
    if ((len == 13 || len == 15 || len == 16) && checksum(card_number) == true)
        return true;
    else
        return false;
}

int length_check(long long n)
{
    int len = 0;
    for (int i = 0; n != 0; n /= 10)
    {
        len++;
    }
    return len;
}

bool checksum(long long card_number)
{
    int sum = 0;
    for (int i = 0; card_number != 0; i++, card_number /= 10)
    {
        if (i % 2 == 0)
            sum += card_number % 10;
        else
        {
            int digit = 2 * (card_number % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 0;
}

void print_cc_brand(long long ccn)
{
    if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))
        printf("AMEX\n");
    else if (ccn >= 51e14 && ccn < 56e14)
        printf("MASTERCARD\n");
    else if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
        printf("VISA\n");
    else
        printf("INVALID\n");
}
