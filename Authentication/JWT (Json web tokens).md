---
tags:
  - auth
---
JSON Web Tokens (JWTs) are primarily used for ==authentication and authorization in applications, particularly web applications and APIs==They enable a secure and compact way to transmit information between parties, such as a client and a server.

- They are a compact and self-contained way to represent information between two parties. They are commonly used for authentication and information exchange in web applications.

- **JWTs are Stateless**: JWTs contain all the information needed to authenticate a request, so the server doesn’t need to store session data. All the `data` is stored in the token itself.

Here's a more detailed explanation:

- **Purpose:** Authentication aims to establish confidence in the identity of a user, device, or process.

- **Process:** It involves verifying credentials, such as usernames and passwords, or using other methods like biometrics or tokens.

- **Importance:** Authentication is essential for protecting systems, data, networks, and applications from unauthorized access and potential attacks. 

---

- **Methods:**
- **Password-based:** Users provide usernames and passwords to verify their identity. 
- **Biometric:** Users are authenticated using unique physical characteristics like fingerprints or facial recognition. 
- **One-time passwords (OTPs):** Users receive a unique code via email or SMS for authentication.
- **Multi-factor authentication (MFA):** Users are authenticated using multiple methods, such as password and a code from an authenticator app.
- **Token-based:** Users receive a token after successful login, which they use for subsequent access.
---
![[auth-jwt.png]]

---
# Tokens vs JWTs

There is a problem with using `stateful` tokens.

## Stateful

By stateful here, we mean that we need to store these tokens in a variable right now (and eventually in a database).

## Problem

The problem is that we need to `send a request to the database` every time the user wants to hit an `authenticated endpoint`

![[token.png]]