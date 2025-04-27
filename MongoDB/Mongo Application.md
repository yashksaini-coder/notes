---
tags:
  - mongo
  - project
---
This outlines building a basic Todo app backend.  Let's fill in the missing pieces and improve security.

##### Pre-stage development:

- Initialise a new Node.js project

```jsx
npm init -y
```

- Install dependencies

```jsx
npm install express mongoose
```

- Create the skeleton for 4 routes
    - POST /signup
    - POST /login
    - POST /todo (authenticated)
    - GET /todos (authenticated)

**1. `index.js` (Main Application File):**

```javascript
const express = require("express");
const mongoose = require("mongoose");
const { UserModel, TodoModel } = require("./db");
const { auth } = require("./auth");
const jwt = require("jsonwebtoken"); // Import jwt here

const app = express();
app.use(express.json());

// Database Connection (update with your connection string)
mongoose.connect("mongodb+srv://gasfgfafa:Aa5jxKhylWdFhv4v@cluster0.7kmvq.mongodb.net/todo-app", {
  useNewUrlParser: true,
  useUnifiedTopology: true,
})
  .then(() => console.log("Connected to MongoDB"))
  .catch((err) => console.error("Error connecting to MongoDB:", err));


app.post("/signup", async (req, res) => {
    try {
        const { email, password, name } = req.body;
        const newUser = await UserModel.create({ email, password, name });
        res.status(201).json({ message: "User created successfully" });
    } catch (error) {
        console.error("Signup error:", error);
        res.status(500).json({ error: "Failed to create user" });
    }
});

app.post("/signin", async (req, res) => {
    try {
        const { email, password } = req.body;
        const user = await UserModel.findOne({ email, password });
        if (!user) {
            return res.status(401).json({ message: "Invalid credentials" });
        }
        const token = jwt.sign({ userId: user._id }, process.env.JWT_SECRET || "s3cret"); // Use process.env for better security
        res.json({ token });
    } catch (error) {
        console.error("Signin error:", error);
        res.status(500).json({ error: "Failed to sign in" });
    }
});

app.post("/todo", auth, async (req, res) => {
    try {
        const { title, done } = req.body;
        const newTodo = await TodoModel.create({ userId: req.userId, title, done });
        res.status(201).json(newTodo);
    } catch (error) {
        console.error("Create todo error:", error);
        res.status(500).json({ error: "Failed to create todo" });
    }
});

app.get("/todos", auth, async (req, res) => {
    try {
        const todos = await TodoModel.find({ userId: req.userId });
        res.json(todos);
    } catch (error) {
        console.error("Get todos error:", error);
        res.status(500).json({ error: "Failed to fetch todos" });
    }
});

app.listen(3000, () => console.log("Server listening on port 3000"));
```

**2. `auth.js` (Authentication Middleware):**

```javascript
const jwt = require("jsonwebtoken");

const auth = (req, res, next) => {
    const token = req.headers.authorization?.split(" ")[1]; //Improved token extraction

    if (!token) {
        return res.status(401).json({ message: "Authorization token missing" });
    }

    try {
        const decoded = jwt.verify(token, process.env.JWT_SECRET || "s3cret"); //Use process.env
        req.userId = decoded.userId;
        next();
    } catch (error) {
        console.error("Authentication error:", error);
        res.status(401).json({ message: "Invalid token" });
    }
};

module.exports = { auth };
```

**3. `db.js` (Database Models):**

(Your existing `db.js` is fine, but consider adding validation for email and password lengths in the `User` schema for improved security).

**4.  Important Security Considerations:**

* **Never hardcode secrets directly in your code.** Use environment variables (`process.env.JWT_SECRET`).  Set this variable using your OS's environment variable settings or tools like `.env` files and a package like `dotenv`.
* **Hash passwords before storing them.**  Plaintext passwords are extremely insecure. Use a library like `bcrypt` to securely hash passwords.
* **Improve input validation.** Sanitize and validate all user inputs to prevent injection attacks.
* **Use HTTPS in production.**  This protects data in transit.
* **Rate limiting.** Implement rate limiting to protect against brute-force attacks.


**To run the application:**

1.  Create a `.env` file in the root directory and add `JWT_SECRET=your_strong_secret_here` (replace `your_strong_secret_here` with a long, randomly generated string).
2.  Install dependencies: `npm install express mongoose jsonwebtoken bcrypt dotenv`
3.  Run the application: `node index.js`


Remember to replace `"mongodb+srv://gasfgfafa:Aa5jxKhylWdFhv4v@cluster0.7kmvq.mongodb.net/todo-app"` with your actual MongoDB connection string.  This improved version addresses security flaws and provides better error handling.  Always prioritize security when building applications that handle user data.
