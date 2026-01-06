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

The GCC compiler is the best and most popular C compilers which is supplied with Linux but is available for many other platforms. It is similar to using the traditional UNIX cc compiler. 

```
gcc program.c -o program
```

---

## General Form of a Simple Program

A simple C program can be written and structured as:- 

```C
directives

int main(void){
	statements
}
```

A simple template that can be found anywhere. C relies on 3 key features; ***Directives*** (editing commands that modify the program prior to compilation), ***Functions*** (named blocks of executable code, of which main is an example), and ***Statements*** (commands to be performed when the program is run).

---

##### **Directives:-** Before compiling, a C program is edited by the **preprocessor**, which handles **directives** (commands starting with `#`). 

The line `#include <stdio.h>` tells the preprocessor to insert the contents of the standard I/O header **stdio.h** into the program.

This header provides functions for input/output, since C has no built-in “read” or “write” commands.

##### **Functions:-** A **function** is a named block of statements; a C program is essentially a collection of functions.

- **Two kinds**:  
  – *Library functions* (supplied by C)  
  – *Programmer-written* (we’ll write these later)

- **main** is the **mandatory** function; it’s called automatically when the program starts.  
  – `int main(void)` means “returns an int, takes no arguments.”  
  – `return 0;` ends main and signals normal termination to the OS; omitting it may trigger a compiler warning.

##### **Statements:-** It is a command executed when the program runs.  
pun.c uses two kinds:  
- **return**  
- **function call**—e.g., [[printf(...)]]  

Every statement must end with a **semicolon**, except compound statements (covered later).  
Directives differ: they’re single-line, no semicolon.

---

## Comments

Purpose  
- Human documentation: what the file/module does, who wrote it, when, why, and any non-obvious assumptions or hazards.  
- Temporary de-activation of code (“commenting out”).  
- Generated documentation extraction (doxygen, etc.).

Two grammars (C99 and later)  
1. `/* … */` – classic, multi-line, **cannot be nested**.  
2. `// …` – C99/C++ style, ends at the **newline**.

Placement  
- Block (box) at the top of every source file.  
- Short “winged” comment on the same line when the code is non-obvious.  
- Above a function, not inside it, unless a one-liner is crystal-clear.

Typical professional header (use doxygen tags if your team does):
```
/******************************************************************************
 *  File:     pun.c
 *  Author:   K. N. King  (king@example.edu)
 *  Date:     2024-05-17
 *  License:  MIT
 *  Brief:    Prints a Shakespeare-flavoured C pun to stdout.
 *  Note:     Intended as a teaching example; no input validation needed.
 ******************************************************************************/
```

Inside the body prefer `//` because it is immune to the “run-away” problem:
```c
int main(void)
{
    // The newline escape is required; stdout is line-buffered on POSIX.
    printf("To C, or not to C: that is the question.\n");
    return 0;          // 0 == EXIT_SUCCESS
}
```

Commenting-out strategy  
- One or two lines: prefix with `//`.  
- Large block: `#if 0 … #endif` instead of `/* … */`—guaranteed nestable and searchable.

What **not** to do  
```
counter++;  /* increment counter */   // useless
```
```
/* open file */                       // obvious
fopen(…);
```

### Rule of thumb:  
If the code can be made self-explanatory by renaming a variable or splitting a function, do that **before** adding a comment.