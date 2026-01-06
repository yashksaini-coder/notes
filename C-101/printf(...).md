---
tags:
  - c
---
---
`printf` is the standard C function for formatted output.  
So far we’ve only passed it a *string literal*—text enclosed in `" "`.  
The quotes are **not** printed; they only delimit the text.

Line control is **explicit**:  
- `printf` does **not** automatically move the cursor to the next line.  
- To terminate the current line you must embed the **new-line escape character** `\n`.  
  - `\n` moves subsequent output to the beginning of the **next** line.  
  - You can put **any number** of `\n`'s in one string to create blank lines or vertical spacing.

Examples  
Original single call  
```c
printf("To C, or not to C: that is the question.\n");
```

Equivalent split calls  
```c
printf("To C, or not to C: ");
printf("that is the question.\n");
```
The user sees identical output; only the source code changes.

Multi-line output  
```c
printf("Brevity is the soul of wit.\n --Shakespeare\n");
```
prints  
```
Brevity is the soul of wit.
 --Shakespeare
```
and leaves the cursor at the start of the next line.

Other common escape characters you will meet in Chapter 3  
- `\t`  horizontal tab  
- `\\`  literal backslash  
- `\"`  literal double quote inside a string  
- `\0`  null character (end-of-string marker)

Remember: every `printf` call just sends characters to *stdout*; formatting and spacing are entirely up to the string you supply.