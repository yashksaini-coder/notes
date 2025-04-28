---
tags:
  - mongo
---
---
# Error handling

Right now, the server crashes if you sign up using duplicate email

How can you fix this?

### Approach #1 - Try catch

In JavaScript, a try...catch block is used for handling exceptions and errors that occur during the execution of code. It allows you to write code that can manage errors gracefully rather than crashing the application or causing unexpected behavior.

JavaScript

Copy

try { // Attempt to execute this code let result = riskyFunction(); // This function might throw an error console.log('Result:', result); } catch (error) { // Handle the error if one is thrown console.error('An error occurred:', error.message); } finally { // This block will always execute console.log('Cleanup code or final steps.'); }

​

Updated signin function

JavaScript

Copy

app.post("/signup", async function(req, res) { try { const email = req.body.email; const password = req.body.password; const name = req.body.name; const hasedPassword = await bcrypt.hash(password, 10); await UserModel.create({ email: email, password: hasedPassword, name: name }); res.json({ message: "You are signed up" }) } catch(e) { res.status(500).json({ message: "Error while signing up" }) } });