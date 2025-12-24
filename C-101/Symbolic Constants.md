---
tags:
  - c
---

A ***Symbolic Constant*** is a identifier (special keyword reserved in ever programming language). It is used to represent a fixed value, so we can instead use that instead of hard-coding values in the program. This effectively improves code quality and also is a best practice to follow in developer community.

Think of it as: _“give this value a meaningful name, and don’t let it change.”_

## Why use symbolic constants?

- ✅ Improves **readability**
- ✅ Easier **maintenance** (change in one place)
- ✅ Prevents **magic numbers**
- ✅ Safer than raw literals

---

## Ways to define symbolic constants

### 1️⃣ Using `#define` (C & C++)

```c
#define PI 3.14159
#define MAX_USERS 100
```

Usage:

```c
float area = PI * r * r;
```

📌 Notes:

- Handled by the **preprocessor**
- No type checking
- Simple text substitution   

---

### 2️⃣ Using `const` (Recommended in C++)

```cpp
const int MAX_USERS = 100;
const double PI = 3.14159;
```

Usage:

```cpp
int arr[MAX_USERS];
```

✅ Advantages:

- Type-safe
- Respects scope rules
- Debugger-friendly

---

### 3️⃣ Using `constexpr` (Modern C++)

```cpp
constexpr int MAX_USERS = 100;
constexpr double PI = 3.14159;
```

📌 Best when:

- Value is known at **compile time**  
- Used in templates or array sizes

---

### 4️⃣ Using `enum` (for related constants)

```cpp
enum Status {
    SUCCESS = 0,
    ERROR = -1
};
```

Usage:

```cpp
Status s = SUCCESS;
```

---

## Quick comparison

| Method      | Type-safe | Scope  | Compile-time |
| ----------- | --------- | ------ | ------------ |
| `#define`   | ❌ No      | Global | Yes          |
| `const`     | ✅ Yes     | Scoped | Sometimes    |
| `constexpr` | ✅ Yes     | Scoped | Always       |
| `enum`      | ✅ Yes     | Scoped | Yes          |

---

## Best practice (modern C++)

👉 Prefer **`constexpr`** or **`const`**, avoid `#define` unless needed for macros.

---

### TL;DR

A symbolic constant is **a named fixed value** used instead of raw numbers or strings to make code **cleaner, safer, and easier to maintain**.

If you want, I can also explain **when NOT to use `#define`**, or show **real-world examples from system-level or competitive programming**.