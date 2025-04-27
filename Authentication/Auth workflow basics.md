---
tags:
  - auth
---
Authentication is ==the process of verifying a user's identity to determine if they are who they claim to be before granting access to a system or resource==. It's a crucial security measure that ensures only authorized individuals can access sensitive data or resources. 

![[main-authentication.png]]
1. User comes to the website (100xdev.com)
2. User sends a **request** to `/sign-in` with their ***username*** & ***password***
3. The user gets back a `token`
4. In every subsequent request, the user sends the token to identify it self to the backend.

===Think of the token like a secret that the server has given you. You send that secret back to the server in every request so that the server knows who you are.===
