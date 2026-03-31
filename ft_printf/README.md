*This project has been created as part of the 42 curriculum by  sarzuman*

# ft_printf
![enter image description here](https://github.com/sarzuman-tech/ft_printf/blob/main/assets/ft_printf.png?raw=true)
## Description
The **ft_printf** project is a custom implementation of the standard C library function `printf`. The primary goal of this project is to learn how to handle variadic functions in C using the `stdarg.h` library. 

This implementation recreates the basic functionality of `printf`, processing a format string and printing the output to the standard output. It handles the following conversions:
* `%c` Prints a single character.
* `%s` Prints a string.
* `%p` Prints a void * pointer argument in hexadecimal format.
* `%d` / `%i` Prints a decimal (base 10) number.
* `%u` Prints an unsigned decimal (base 10) number.
* `%x` Prints a number in hexadecimal (base 16) lowercase format.
* `%X` Prints a number in hexadecimal (base 16) uppercase format.
* `%%` Prints a percent sign.

## Instructions

### Compilation
To compile the library, navigate to the project root and run:
```bash
make
```
This will produce the `libftprintf.a` library file.

### Usage

To use `ft_printf` in your own C project, include the header and link the library during compilation:

1.  Include the header in your code: `#include "ft_printf.h"`
    
2.  Compile your program: cc main.c libftprintf.a

## Algorithm and Data Structure

### Data Structure

For this project, I used a **procedural approach** without complex data structures, as the mandatory part focuses on immediate processing. Each time a `%` is encountered, the program identifies the specifier and calls the corresponding printing function.

### Algorithm

The core logic follows these steps:

1.  **Iteration:** The program iterates through the format string character by character.
    
2.  **Detection:** If a regular character is found, it is printed directly. If a `%` is detected, the program looks at the next character to determine the type.
    
3.  **Variadic Handling:** Using `va_start`, `va_arg`, and `va_end`, the program retrieves arguments of different types (int, char *, etc.) from the stack.
    
4.  **Conversion:** Based on the specifier, the data is converted into a string/character format and written to the standard output.
    
5.  **Count:** The total number of printed characters is tracked and returned at the end.

### 📚 Resources

1.  **Man 3 printf** – Official documentation for the standard `printf` function.
    
2.  **Variadic Functions in C** – Guide on using `stdarg.h` for handling functions with a variable number of arguments.
    
3.  **YouTube Tutorial – Building a Mini printf Function**  
    A detailed video tutorial explaining how to implement a custom `printf`, including handling format specifiers and variadic arguments:  
    [https://www.youtube.com/watch?v=byRw36Y3Hjs](https://www.youtube.com/watch?v=byRw36Y3Hjs&utm_source=chatgpt.com)

### AI Usage

-   **Task:** I used AI (Gemini/ChatGPT) to explain the internal mechanics of the `va_list` pointer and how it moves through the stack.
    
-   **Parts:** AI was also used to generate edge-case test ideas (e.g., printing the minimum value of an integer or a NULL pointer)