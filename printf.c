#include <stdio.h>
#include "libft.h" // Assuming your ft_printf is part of libft or a separate header

int main(void) {
    // Test variable setup for edge cases.
    int int_max = 2147483647;
    int int_min = -2147483648;
    unsigned int uint_max = 4294967295;
    long long_max = 9223372036854775807L;
    long long_min = -9223372036854775807L-1;
    double d_max = 1.7E+308;
    double d_min = -1.7E+308;

    // Extreme test case:
    // Combine different formats with extreme values
    
    // Using standard printf
    printf("Standard printf:\n");
    printf(
        "Extreme Test Case:\n"
        "%%d (INT MAX): %d\n"
        "%%d (INT MIN): %d\n"
        "%%u (UINT MAX): %u\n"
        "%%lx (LONG MAX as HEX): %lx\n"
        "%%ld (LONG MIN): %ld\n"
        "%%f (DOUBLE MAX): %f\n"
        "%%f (DOUBLE MIN): %f\n"
        "%%.25f (High Precision Double): %.25f\n"
        "%%s (Large String): %s\n"
        "%%c (Escape Characters): %% %c %c\n"
        "Escaped Percent: %%\n",
        int_max,
        int_min,
        uint_max,
        long_max,
        long_min,
        d_max,
        d_min,
        3.1415926535897932384626433, // example high precision float
        "A very long string to test the limits of printf's string handling capabilities.",
        '\n', '\t'
    );

    // Using custom ft_printf
    ft_printf("Custom ft_printf:\n");
    ft_printf(
        "Extreme Test Case:\n"
        "%%d (INT MAX): %d\n"
        "%%d (INT MIN): %d\n"
        "%%u (UINT MAX): %u\n"
        "%%lx (LONG MAX as HEX): %lx\n"
        "%%ld (LONG MIN): %ld\n"
        "%%f (DOUBLE MAX): %f\n"
        "%%f (DOUBLE MIN): %f\n"
        "%%.25f (High Precision Double): %.25f\n"
        "%%s (Large String): %s\n"
        "%%c (Escape Characters): %% %c %c\n"
        "Escaped Percent: %%\n",
        int_max,
        int_min,
        uint_max,
        long_max,
        long_min,
        d_max,
        d_min,
        3.1415926535897932384626433, // example high precision float
        "A very long string to test the limits of ft_printf's string handling capabilities.",
        '\n', '\t'
    );

    return 0;
}
