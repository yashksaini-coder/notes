---
tags:
  - auth
---
# Creating an authenticated EP

Let’s create an endpoint (`/me` ) that returns the user their information only if they send their `token`

```jsx
app.get("/me", (req, res) => {
    const token = req.headers.token;
    let user = null;
    for(let i=0; i < users.length; i++){
        if(users[i].token === token){
            user = users[i];
            break;
        }
    }
  
    if (user) {
        res.send({
            username: user.username
        })
    } else {
        res.status(401).send({
            message: "Unauthorized"
        })
    }
});
```