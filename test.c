#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 1;
    char str[12]; // Buffer for integer string (handles up to 10 digits + sign + null)

    while (1) // Infinite loop
    {
        snprintf(str, sizeof(str), "%d", i); // Convert i to string
        printf("%d\n", atoi(str) * 1000000); // Convert back to int with atoi and multiply by 10
        i++;
        // Optional: Add a small delay or break condition to avoid overwhelming output
        // if (i > 1000) break; // Uncomment to limit output for testing
    }

    return 0;
}
