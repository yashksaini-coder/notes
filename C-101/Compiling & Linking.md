---
tags:
  - c
---
---

*Compiling and Linking* Despite its brevity, getting pun.c to run is more involved than you might expect. First, we need to create a file named pun.c containing the program (any text editor will do). The name of the file doesn’t matter, but the .c extension is often required by compilers. Next, we’ve got to convert the program to a form that the machine can 
execute. For a C program, that usually involves three steps:-

- **Preprocessing**: The program is first given to a preprocessor, which obeys commands that begin with # (known as directives). A preprocessor is a bit like an editor; it can add things to the program and make modifications. 

- **Compiling**: The modified program now goes to a compiler, which translates it into machine instructions (object code). The program isn’t quite ready to run yet, however.

- **Linking**: In the final step, a linker combines the object code produced by the compiler with any additional code needed to yield a complete executable pro- gram. This additional code includes library functions (like printf) that are used in the program.