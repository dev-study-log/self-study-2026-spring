#include <stdio.h>

/* Status Definitions */
enum STATUS
{
    HIGH_TEMPERATURE,     /* 1200°C or higher */
    MODERATE_TEMPERATURE, /* 800°C to less than 1200°C */
    LOW_TEMPERATURE,      /* 0°C to less than 800°C */
    INVALID_TEMPERATURE   /* Negative values (except -1) */
};

int getTemperature(void);
enum STATUS getStatus(int);
void showMessage(enum STATUS);

/* Steel temperature monitoring / line control simulator

- Repeatedly accept "current steel temperature (integer)" from the user.
- Display a status message based on the input temperature.
- Exit the program when "-1" is entered or invalid input (e.g., string) is given.
*/
int main(void)
{
    int count = 0;
    int temperature;
    temperature = getTemperature();
    while (temperature != -1)
    {
        count++;
        printf("[Measurement #%d]\n", count);
        printf("Current Temperature: %d [°C]\n", temperature);

        enum STATUS currentStatus;
        currentStatus = getStatus(temperature);
        showMessage(currentStatus);

        temperature = getTemperature();
    }

    return 0;
}

/* Get temperature from standard input */
int getTemperature(void)
{
    int temperature;
    printf("Enter temperature (-1 to exit): ");

    /* Exit immediately if input is not an integer */
    if (scanf("%d", &temperature) != 1)
    {
        printf("Please enter an integer value.\n");
        return -1;
    }
    return temperature;
}

enum STATUS getStatus(int temperature)
{
    if (temperature >= 1200)
    {
        return HIGH_TEMPERATURE;
    }
    if (temperature >= 800)
    {
        return MODERATE_TEMPERATURE;
    }
    if (temperature >= 0)
    {
        return LOW_TEMPERATURE;
    }
    return INVALID_TEMPERATURE;
}

/* Display message based on status */
void showMessage(enum STATUS status)
{
    switch (status)
    {
    case HIGH_TEMPERATURE:
        printf("[Warning] Temperature is too high! Activate the cooling fan.\n");
        break;
    case MODERATE_TEMPERATURE:
        printf("[Normal] Optimal temperature. Continue rolling process.\n");
        break;
    case LOW_TEMPERATURE:
        printf("[Warning] Temperature is dropping! Reheating is required.\n");
        break;
    default:
        printf("[Error] Invalid value. Please re-enter.\n");
    }
}
