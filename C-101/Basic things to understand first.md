---
tags:
  - c
---
---

Starting with its [[History]]. Started as a simple language compatible for UNIX OS system 

- First program that every developer is supposed to write [[Hello World]]
- Main programming practice to solve any problem, applies to every programming language, [[Algorithms]]
- Basic constants that help us define values and not hard code them in programs [[Symbolic Constants]]

---

Next we will go and see how to Write a simple program and behind its process:

Compare to other languages ***C programs*** require little boilerplate - a complete program can be very written in few lines.

Starting with `Print` :-

```C
#include <stdio.h>

int main(void){
	printf("To C, or not to C: that is the question \n")
	return 0;
}
```

- `include <stdio.h>` is necessary as it tells the program to include the basic Input/Output library. The program executable code goes in `main()` which represents the main program.
- The only line inside `main()` is a command to display the desired message.
- `printf` is a function from the standard I/O library that can produce nicely formatted output. 
- The `\n` is for advancing to the next line after printing the message.
- `return 0;` indicates that the program "returns" the value 0 to the operating system when it terminates.

> [!NOTE]
>The internal process of main program to become executable is called **[[Compiling & Linking]]**


