---
tags:
  - mongo
  - typescript
---
---
# Input validation

In TypeScript, Zod is a library used for schema validation and parsing. It's designed to help developers define, validate, and manage data structures in a type-safe manner.

Docs - [https://zod.dev/](https://zod.dev/)

**Why use Zod for Input Validation?**

* **Type Safety:** Zod integrates seamlessly with TypeScript's type system.  This means you get compile-time type checking, catching errors before runtime.  This significantly reduces bugs and improves developer experience.
* **Early Error Detection:** Validation happens as soon as data is received, not later in the application flow.  This prevents invalid data from propagating and causing problems downstream.
* **Improved Code Readability:** Zod schemas clearly define the expected data structure, making your code easier to understand and maintain.
* **Comprehensive Validation:** Zod supports a wide range of validation rules, including data types, formats, lengths, and custom validation functions.
* **Easy to Use:** Zod provides a straightforward and intuitive API for defining schemas.

**Example Scenarios and Zod Schemas:**

Let's illustrate with examples using different data types and validation rules:

**1. Simple User Input:**

```typescript
import { z } from 'zod';

// Define a schema for user input
const userSchema = z.object({
  name: z.string().min(3, { message: 'Name must be at least 3 characters' }),
  age: z.number().min(0).max(120),
  email: z.string().email({ message: 'Invalid email address' }),
});

// Example usage:
const userInput = { name: 'Ab', age: -5, email: 'invalid-email' };

try {
  const validatedData = userSchema.parse(userInput);
  console.log('Validated data:', validatedData); // This line will not be reached due to the errors
} catch (error) {
  // Error handling - access error details from ZodError
  if (error instanceof z.ZodError) {
    console.error('Validation errors:', error.issues);
  } else {
    console.error('An unexpected error occurred:', error);
  }
}

const validUserInput = { name: 'Alice', age: 30, email: 'alice@example.com' };

try {
  const validatedData = userSchema.parse(validUserInput);
  console.log('Validated data:', validatedData); // This will successfully parse and log the data
} catch (error) {
  console.error('Validation error:', error); //This will not be reached
}
```

**2. Complex Object:**

```typescript
import { z } from 'zod';

const addressSchema = z.object({
  street: z.string(),
  city: z.string(),
  zip: z.string().regex(/^\d{5}(-\d{4})?$/i, { message: 'Invalid zip code format' }),
});

const userWithAddressSchema = z.object({
  name: z.string(),
  age: z.number().int().positive(),
  address: addressSchema,
});

// Example usage
const userData = {
  name: 'Bob',
  age: 25,
  address: { street: '123 Main St', city: 'Anytown', zip: '12345-6789' },
};

const validatedUserData = userWithAddressSchema.parse(userData);
console.log(validatedUserData);
```

**3. Array of Objects:**

```typescript
import { z } from 'zod';

const productSchema = z.object({
  name: z.string(),
  price: z.number().positive(),
});

const shoppingCartSchema = z.array(productSchema);

const cartData = [
  { name: 'Shirt', price: 25 },
  { name: 'Pants', price: 50 },
];

const validatedCart = shoppingCartSchema.parse(cartData);
console.log(validatedCart);
```


**Error Handling:**

Zod provides detailed error messages, making debugging easier.  The `catch` block in the examples shows how to handle `z.ZodError` to extract and display specific error information to the user.

**Installation:**

You'll need to install Zod:

```bash
npm install zod
# or
yarn add zod
```

These examples demonstrate the power and flexibility of Zod for validating various input types in a type-safe way.  Remember to always handle potential errors gracefully in your application.  The official Zod documentation provides much more detailed information on all the available features and validation options.
