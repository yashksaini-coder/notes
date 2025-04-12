It should have 4 routes:-

- [http://localhost:3000/multiply?a=1&b=2](http://localhost:3000/multiply?a=1&b=2)
- [http://localhost:3000/add?a=1&b=2](http://localhost:3000/add?a=1&b=2)
- [http://localhost:3000/divide?a=1&b=2](http://localhost:3000/divide?a=1&b=2)
- [http://localhost:3000/subtract?a=1&b=2](http://localhost:3000/subtract?a=1&b=2)

Inputs given at the end after `?` are known as query *parameters* (usually used in GET requests)

The way to get them in an HTTP route is by extracting them from the `req` argument ***(req.query.a , req.query.b)***

### Initialize Node `npm` project:-

- Initialize node project
	`npm init -y`

- Install Dependencies
	`npm install express`

- Create index.js
	`echo index.js`

- Code to create 4 points:
```javascript
const express = require("express");
const app = express(); 

app.get("/sum", function(req, res) {
const a = req.query.a;
const b = req.query.b;
res.json({ ans: a + b })
});

app.get("/multiply", function(req, res) {
const a = req.query.a;
const b = req.query.b;
res.json({ ans: a * b }) 
}); 

app.get("/divide", function(req, res) {
const a = req.query.a;
const b = req.query.b;
res.json({ ans: a / b })
});

app.get("/subtract", function(req, res) {
const a = req.query.a;
const b = req.query.b;
res.json({ ans: a - b })
});

app.listen(3000);
```

- Original Working code:-
```javascript
const express = require("express");

const app = express();

app.get("/sum", function(req, res) {
const a = parseInt(req.query.a);
const b = parseInt(req.query.b);
res.json({ ans: a + b })
}); 

app.get("/multiply", function(req, res) {
const a = req.query.a;
const b = req.query.b;

res.json({ ans: a * b })
});

app.get("/divide", function(req, res) {
const a = req.query.a;
const b = req.query.b;

res.json({ ans: a / b })
});

app.get("/subtract", function(req, res) {
const a = parseInt(req.query.a);
const b = parseInt(req.query.b);

res.json({ ans: a - b })
});

app.listen(3000);
```

