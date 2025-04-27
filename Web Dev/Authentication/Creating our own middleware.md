---
tags:
  - auth
---
---
- Creating our own middleware function `auth`:

```js
const JWT_SECRET = 'some value';

function auth (req, res, next){
	const token = req.body.token || authorization;
	if(token){
		jwt.verify(token, JWT_SECRET (err, decode) => {
			if (err) {
				res.status(401).send({
					message: "Unauthorized"
				})
			} else {
				req.user = decoded;
				next();
			}
		)
	} else {
		res.status(401).send({
			message: "Unauthorized"
		})
	}
}

```

- Using it within the `/me` API endpoint:

```js
app.get("/me", auth, (req, res) => {
    const user = req.user;
  
    res.send({
        username: user.username
    })
})
```
