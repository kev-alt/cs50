#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float dollars;
    int cents;

    do
    {
        dollars = get_float("change owned: ");
    }
    while (dollars <= 0);
    cents = round(dollars);

    int coins = 0;

    while (cents >= 25)
    {
        coins += cents / 25;
        cents %= 25;
    }

    while (cents >= 10)
    {
        coins += cents / 10;
        cents %= 10;
    }

    while (cents >= 5)
    {
        coins += cents / 5;
        cents %= 5;
    }

    while (cents >= 1)
    {
        coins += cents / 1;
        cents %= 1;
    }

    printf("%d\n", coins);
}
