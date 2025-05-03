---
tags:
  - backend
---
**Router** falls under the category of **Backend Web Development**. Specifically, it is part of **API Development** using **Node.js** and the **Express.js** framework. Here's why:

1. **Backend Development**: The code handles server-side logic, such as user authentication and database interactions.
2. **RESTful API**: It defines routes (`/signup` and `/login`) to handle HTTP requests for user-related operations.
3. **Authentication**: It uses **bcrypt** for password hashing and **jsonwebtoken (JWT)** for token-based authentication.
4. **Database Interaction**: It interacts with a database (likely MongoDB or a similar database) to store and retrieve user data.
5. **Error Handling**: It includes error handling for invalid inputs and server errors.

This approach is common in building secure and scalable backend systems for web applications.

yashksaini-coder: give me a proper doc note

GitHub Copilot: ### Documentation for the Course Selling Application

#### Overview
This application is a **Course Selling Platform** built using **Node.js**, **Express.js**, and **MongoDB**. It provides user authentication, course management, and purchase functionalities. Below is a detailed explanation of the key components and their roles.

---

### 1. **File Structure**
- **`index.js`**: Entry point of the application. Sets up the server, connects to the database, and defines routes.
- **`routes/user.js`**: Contains routes for user authentication (`/signup` and `/login`).
- **`db.js`**: Defines the MongoDB schemas and models for `user`, `courses`, `admin`, and `purchase`.
- **`config.js`**: Stores configuration values such as the JWT secret.

---

### 2. **Features**

#### a. User Authentication
- **Signup (`POST /signup`)**:
  - Accepts `username`, `password`, and `email` in the request body.
  - Hashes the password using **bcrypt** for security.
  - Checks for unique `email` and `username` before creating a new user.
  - Returns a success message upon successful user creation.

- **Login (`POST /login`)**:
  - Accepts `email` and `password` in the request body.
  - Verifies the user by checking the hashed password using **bcrypt**.
  - Generates a **JWT token** upon successful login.

#### b. Database Models
- **User Model**:
  - Fields: `username`, `email` (unique), `password`.
- **Courses Model**:
  - Fields: `title`, `description`, `creatorId`, `price`, `image`.
- **Admin Model**:
  - Fields: `username`, `email` (unique), `password`.
- **Purchase Model**:
  - Fields: `userId`, `courseId`.

#### c. Database Connection
- The application connects to a **MongoDB Atlas** cluster using the `mongoose` library.

#### d. JWT Authentication
- **JWT_SECRET** is stored in config.js and used to sign tokens for user authentication.

---

### 3. **Endpoints**

| Method | Endpoint       | Description                          |
|--------|----------------|--------------------------------------|
| POST   | `/signup`      | Registers a new user.               |
| POST   | `/login`       | Authenticates a user and returns a JWT token. |
| GET    | `/`            | Displays a welcome message.         |

---

### 4. **Technologies Used**
- **Node.js**: Backend runtime environment.
- **Express.js**: Web framework for building RESTful APIs.
- **MongoDB**: NoSQL database for storing user, course, and purchase data.
- **Mongoose**: ODM library for MongoDB.
- **bcrypt**: For hashing passwords.
- **jsonwebtoken (JWT)**: For token-based authentication.

---

### 5. **Setup Instructions**

1. **Install Dependencies**:
   ```bash
   npm install
   ```

2. **Run the Application**:
   ```bash
   node index.js
   ```

3. **Environment**:
   - Ensure MongoDB Atlas connection string is valid in index.js.
   - Use `JWT_SECRET` from config.js for token signing.

4. **Access the Application**:
   - Open `http://localhost:3000` in your browser.

---

### 6. **Security Notes**
- **Password Hashing**: Passwords are hashed using **bcrypt** before storing in the database.
- **JWT Secret**: Ensure the `JWT_SECRET` is kept secure and not exposed publicly.
- **Validation**: Input validation is implemented for required fields like `username`, `email`, and `password`.

---

### 7. **Future Improvements**
- Add role-based access control (e.g., Admin vs. User).
- Implement course creation and purchase endpoints.
- Add email validation and password strength checks.
- Use environment variables for sensitive data like `JWT_SECRET` and database connection strings.

---

This documentation provides a comprehensive overview of the application and its components.

yashksaini-coder: no like for backend study and guide on how to use router and creating them implementing them properly

GitHub Copilot: ### Backend Study Guide: Using and Implementing Routers in Express.js

#### Overview
In **Express.js**, routers are used to organize and modularize your application by grouping related routes together. This makes your code more maintainable and scalable, especially for larger applications.

---

### 1. **What is a Router?**
A **Router** in Express.js is a mini application that can handle a subset of routes. It allows you to define routes and middleware for specific parts of your application and then mount them in the main application.

---

### 2. **Why Use Routers?**
- **Modularity**: Separate routes into different files for better organization.
- **Reusability**: Reuse routers across different parts of the application.
- **Scalability**: Makes it easier to manage large applications by grouping related routes.

---

### 3. **Steps to Create and Use Routers**

#### a. **Create a Router**
Use `express.Router()` to create a new router instance. Define routes on this router.

```javascript
const { Router } = require('express');
const router = Router();

// Define routes
router.get('/example', (req, res) => {
  res.send('This is an example route');
});

module.exports = router;
```

#### b. **Use the Router in the Main Application**
Import the router and use it in the main application file (`index.js`).

```javascript
const express = require('express');
const exampleRouter = require('./routes/example.js'); // Import the router

const app = express();

app.use('/example', exampleRouter); // Mount the router at the '/example' path

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});
```

---

### 4. **Best Practices for Using Routers**

#### a. **Group Related Routes**
Group routes that share a common purpose or resource. For example:
- **`user.js`**: Handles user-related routes like `/signup` and `/login`.
- **`course.js`**: Handles course-related routes like `/create` and `/list`.

#### b. **Use Middleware in Routers**
Apply middleware (e.g., authentication, validation) to specific routers.

```javascript
const { Router } = require('express');
const router = Router();

// Middleware for authentication
router.use((req, res, next) => {
  console.log('Middleware applied to this router');
  next();
});

// Define routes
router.get('/protected', (req, res) => {
  res.send('This route is protected');
});

module.exports = router;
```

#### c. **Error Handling**
Handle errors gracefully within routers.

```javascript
router.get('/example', async (req, res) => {
  try {
    // Your logic here
    res.send('Success');
  } catch (error) {
    res.status(500).json({ message: 'An error occurred', error });
  }
});
```

---

### 5. **Example: User Router**

Below is an example of a **User Router** (`user.js`) that handles user signup and login.

```javascript
const { Router } = require('express');
const { user } = require('../db.js');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');
const { JWT_SECRET } = require('../config.js');

const userRouter = Router();

// Signup Route
userRouter.post('/signup', async (req, res) => {
  const { username, email, password } = req.body;

  if (!username || !email || !password) {
    return res.status(400).json({ message: 'All fields are required' });
  }

  try {
    const hashedPassword = await bcrypt.hash(password, 10);

    if (await user.findOne({ email })) {
      return res.status(400).json({ message: 'Email already exists' });
    }

    await user.create({ username, email, password: hashedPassword });
    res.status(201).json({ message: 'User created successfully' });
  } catch (error) {
    res.status(500).json({ message: 'Error creating user', error });
  }
});

// Login Route
userRouter.post('/login', async (req, res) => {
  const { email, password } = req.body;

  if (!email || !password) {
    return res.status(400).json({ message: 'All fields are required' });
  }

  try {
    const foundUser = await user.findOne({ email });
    if (!foundUser) {
      return res.status(404).json({ message: 'User not found' });
    }

    const isPasswordValid = await bcrypt.compare(password, foundUser.password);
    if (!isPasswordValid) {
      return res.status(400).json({ message: 'Invalid credentials' });
    }

    const token = jwt.sign({ id: foundUser._id }, JWT_SECRET);
    res.json({ token });
  } catch (error) {
    res.status(500).json({ message: 'Error logging in', error });
  }
});

module.exports = { userRouter };
```

---

### 6. **Mounting the Router**

In your main application file (`index.js`), mount the `userRouter`.

```javascript
const express = require('express');
const { userRouter } = require('./routes/user.js');

const app = express();
app.use(express.json()); // Middleware to parse JSON

app.use('/user', userRouter); // Mount the user router at '/user'

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});
```

---

### 7. **Benefits of Using Routers**
- **Separation of Concerns**: Keeps route logic separate from the main application logic.
- **Improved Readability**: Makes the codebase easier to navigate.
- **Easier Debugging**: Errors are isolated to specific routers.

By following these practices, you can effectively use and implement routers in your backend applications.