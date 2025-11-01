---
tags:
  - project
  - auth
---
---
#### Creating a simple Auth Backend and connecting it with Frontend side
- Proper required resources to begin with:
```js
const express = require('express');
const app = express;
const jwt = require('jsonwebtoken');

const users = [];
const secret = 'abc';
```


- A `post` req for signup operation

```js
app.post("/signup", function(req, res){
	user = req.body.username;
	pass = req.body.password;

	users.push({
		username:username,
		password:password
	})

	res.json({
	message:"user signed up successfully"
	user:{
		username:username,
		password:password
		}
	})
	if(res.status(200)){
		console.log(user signed up successfully)
	}
	else{
		console.log(user signup failed)
	}
}
```

- Another `post` signin request to login to application
```js
app.post('/signin', (req, res) => {
	let founduser = null;
	
	const username = body.req.username;
	const password = body.req.password;
	
	for(let i=0; i< users.length(); i++){
		if (users[i].username === username && users[i].password ===password){
			founduser = users[i];
		}
	}

	if(founduser){
		const token = jwt.sign({
			username:founduser.username}
		,secret)

	founduser.token=token;
	res.json(
		message:"sign in successful";
		token:token
	)
	} else {
	res.status(401){
		message:"invalid username or password"
		}
	}
});
```

- Also an authenticated function:- 

```js

function auth(req, res, next) {
	const token = req.headers.token;
	
	if(token){
	
		jwt.verify(token, secret (err, decoded){
			if(err){
				res.status(401){
				message:"unauthorized";
				}
			} else {
				req.user = decoded;
				next();
			}
		})
		res.headers.token = token;
	} else {
	res.status(401){
		message:"unauthorized"
		}
	}
}
```

- Authenticate route that uses the `auth` function live:- 

```js
app.get("/me", auth, (req, res) => {
	const user = req.user;

	res.send({
		username = user.username
	})
}
```

## Main HTML file code

```html
<html>
    <head>
        <title>Auth website</title>
    </head>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/axios/1.7.7/axios.min.js"></script>
    <script>
        async function signup() {
            const username = document.getElementById("signup-username").value;
            const password = document.getElementById("signup-password").value;
  
            await axios.post("http://localhost:3000/signup", {
                username: username,
                password: password
            });
            alert("You are signed in");
        }
        async function signin() {
            const username = document.getElementById("signin-username").value;
            const password = document.getElementById("signin-password").value;
            const response = await axios.post("http://localhost:3000/signin", {
                username: username,
                password: password
            });
  
            localStorage.setItem("token", response.data.token);
  
            alert("You are signed in");
        }
        async function getUserInformation() {
            const response = await axios.get("http://localhost:3000/me", {
                headers: {
                    token: localStorage.getItem("token")
                }
            })
            document.etElementById("information").innerHTML = "Username: " + response.data.username + " Password: " + response.data.password
        }
        getUserInformation();
    </script>
    <style>
        body{
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            height: 100vh;
            background-color: #000000;
            color: #ffffff;
        }
    </style>
    <body>
        <div>
            Signup
            <input id=signup-username" type="text" name="username" placeholder="Username">
            <input id=signup-password" type="password" name="password" placeholder="Password">
            <button onclick="signup()">Submit</button>
        </div>
        <div>
            Signin
            <input id=signin-username" type="text" name="username" placeholder="Username">
            <input id=signin-password" type="password" name="password" placeholder="Password">
            <button onclick="signin()">Submit</button>
        </div>
        <div>
            User information:
            <div id="information"></div>
        </div>
        <div>
            <button onclick="logout()">Logout</button>
        </div>
    </body>
  
</html>
```
