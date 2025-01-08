#include <stdio.h>

unsigned long long modularExponentiation(unsigned long long Base, unsigned long long Number, unsigned long long Modulus)
{
    unsigned long long result = 1;
    Base = Base % Modulus;

    if (Base == 0)
        return 0;

    while (Number > 0)
    {

        if (Number % 2 == 1)
            result = (result * Base) % Modulus;

        Number = Number / 2;
        Base = (Base * Base) % Modulus;
    }
    return result;
}

int main()
{
    unsigned long long Base, Number, Modulus;

    printf("Enter the base: ");
    if (scanf("%llu", &Base) != 1 || Base < 0)
    {
        printf("Error: Base must be a positive integer.\n");
        return 1;
    }

    printf("Enter the exponent: ");
    if (scanf("%llu", &Number) != 1 || Number < 0)
    {
        printf("Error: Exponent must be a positive integer.\n");
        return 1;
    }

    printf("Enter the modulus: ");
    if (scanf("%llu", &Modulus) != 1 || Modulus <= 1)
    {
        printf("Error: Modulus must be greater than 1.\n");
        return 1;
    }

    unsigned long long result = modularExponentiation(Base, Number, Modulus);

    printf("Result: %llu\n", result);

    return 0;
}
