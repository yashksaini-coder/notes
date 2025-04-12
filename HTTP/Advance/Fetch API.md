There are 2 high level ways a browser can send requests to an HTTP server:

![](https://petal-estimate-4e9.notion.site/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F90f9e2cf-45f0-4502-abb5-9a7c3543dbec%2FScreenshot_2024-08-31_at_6.59.39_PM.png?table=block&id=267c0225-7500-449b-b5fb-35bdf1036c78&spaceId=085e8ad8-528e-47d7-8922-a23dc4016453&width=1420&userId=&cache=v2)

From the browser URL (Default GET request):

When you type a URL into the browser’s address bar and press Enter, the browser sends an HTTP GET request to the server. This request is used to retrieve resources like HTML pages, images, or other content.

From an HTML form or JavaScript (Various request types):

HTML Forms: When a user submits a form on a webpage, the browser sends an HTTP request based on the form’s method attribute, which can be GET or POST. Forms with method="POST" typically send data to the server for processing (e.g., form submissions).

JavaScript (Fetch API): JavaScript running in the browser can make HTTP requests to a server using APIs the fetch API. These requests can be of various types (GET, POST, PUT, DELETE, etc.) and are commonly used for asynchronous data retrieval and manipulation (e.g., AJAX requests).

### Fetch request examples

Server to send the request to - [https://jsonplaceholder.typicode.com/posts/1](https://jsonplaceholder.typicode.com/posts/1) (GET request)

```javascript
<!DOCTYPE html>
<html>
<body>
<div id="posts"></div>
<script> async function fetchPosts() { 
const res = await fetch("https://jsonplaceholder.typicode.com/posts/1");
const json = await res.json(); document.getElementById("posts").innerHTML = json.title;
} fetchPosts(); 
</script> 
</body>
</html>
```
---

#### Using axios (external library)

```javascript
<!DOCTYPE html> 
<html>
<head>
<script src="https://cdnjs.cloudflare.com/ajax/libs/axios/1.7.6/axios.min.js"></script>
</head>
<body>
<div id="posts"></div> 
<script> async function fetchPosts() { const res = await axios.get("https://jsonplaceholder.typicode.com/posts/1"); document.getElementById("posts").innerHTML = res.data.title;
} 
fetchPosts(); 
</script> 
</body> 
</html>
```
