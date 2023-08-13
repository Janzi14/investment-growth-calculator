#include <stdio.h>
#include <math.h>

int calculate_growth_time(int initial_investment, int end_value, int interest_rate);
int get_size_input(int min_value, char message[50]);

int main(void)
{
    int initial_investment = get_size_input(1, "How big is the initial investment? ");
    int interest_rate = get_size_input(0, "At what interest rate (in percent)? ");
    int end_value = get_size_input(initial_investment, "How big should the investment's value be? ");
    int years = calculate_growth_time(initial_investment, end_value, interest_rate);
    printf("Years: %i\n", years);
}

int get_size_input(int min_value, char message[50])
{
    int size;

    printf("%s ", message);
    while (1)
    {
        if (scanf("%d", &size) == 1)
        {
            if (size > min_value)
            {
                break;
            }
        };
        while (getchar() != '\n')
            ;
        printf("Please enter a number bigger than %i: ", min_value);
    };
    return size;
}

int calculate_growth_time(int initial_investment, int end_value, int interest_rate)
{
    return (log((double)end_value / initial_investment)) / (log(1 + (double)interest_rate / 100));
}