---
tags:
  - auth
---

We can add the `token` in the JSON body and still get the proper authenticated response. But it is not designed for that. Instead we can pass it using Request Headers creating a new header value called `token` and from there we can identify and get the user from the db.

![[auth-headers.png]]