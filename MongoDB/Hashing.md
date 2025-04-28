---
tags:
  - mongo
---
---
Hashing is a one-way function that transforms an input (the "key") into a fixed-size string of characters (the "hash" or "hash value").  It's computationally infeasible to reverse the process and obtain the original key from the hash. This one-way property is crucial for its security applications.

**Needs for Hashing:**

* **Password Storage:**  This is the primary use case shown in your example code.  Storing passwords directly in a database is incredibly risky.  If the database is compromised, all passwords are exposed. Hashing allows you to store a representation of the password (the hash) without storing the password itself.  If the database is compromised, the attacker only has the hashes, which are useless without the computationally infeasible reverse process.  `bcrypt`, used in your example, is a strong password hashing algorithm specifically designed to resist attacks.

* **Data Integrity:** Hashing can verify if data has been tampered with. If you hash a file and then later re-hash it, any change in the file, no matter how small, will result in a different hash value.  This is used for checksums and digital signatures.

* **Data Deduplication:** If you hash data before storing it, you can quickly check if a piece of data already exists by comparing hashes.  This saves storage space and reduces redundancy.

* **Lookup Tables (Hash Tables):** Hashing is fundamental to hash tables, a very efficient data structure for storing and retrieving data based on a key.  A hash function maps keys to indices in an array, allowing for fast lookups.


**Key Points:**

* **One-Way Function:**  It's easy to compute the hash from the key, but extremely difficult (computationally infeasible) to compute the key from the hash.
* **Fixed-Size Output:**  Regardless of the size of the input key, the hash has a predetermined, fixed size.
* **Collision Resistance:**  A good hash function minimizes the probability of different keys producing the same hash (a "collision").  However, collisions are inevitable with sufficiently large input spaces.
* **Deterministic:** The same input key will always produce the same hash value.

**Features of a Good Hash Function:**

* **Preimage resistance:**  Given a hash, it should be computationally infeasible to find the original input (key).
* **Second preimage resistance:**  Given an input and its hash, it should be computationally infeasible to find a different input that produces the same hash.
* **Collision resistance:**  It should be computationally infeasible to find two different inputs that produce the same hash.
* **Uniformity/Distribution:** The hash values should be uniformly distributed across the output space.

**Hashing Techniques:**

Many different hashing algorithms exist, each with its strengths and weaknesses. Some common examples include:

* **MD5:** An older algorithm, now considered cryptographically broken and unsuitable for security-sensitive applications like password storage.
* **SHA-1:** Also considered insecure for cryptographic purposes.
* **SHA-256/SHA-512:**  Widely used and generally considered secure members of the SHA-2 family.
* **bcrypt:** Specifically designed for password hashing, it's resistant to brute-force and rainbow table attacks.  It incorporates a "salt" (a random value unique to each password) to further enhance security, making it much harder for attackers to pre-compute hashes.  This is what your example code utilizes.
* **scrypt:** Another password hashing function designed for resistance against hardware-accelerated attacks.

> Official [bcrypt](https://www.npmjs.com/package/bcrypt) package 

### **Example**

- import bcrypt package
```javascript
const bcrypt  = require("bcrypt")
```

- `signup` endpoint with hashed feature:-

```javascript
app.post("/signup", async function(req, res) {
    const username = req.body.username;
    const password = req.body.password;
    const email = req.body.email;

	const hashed = await bcrypt.hash(password,10)

    await user.create({
        username: username,
        password: hashed,
        email: email
    });
  
    res.json({
        message: "User created successfully",
        user: {
            username: username,
            password: password,
            email: email
        }
    });
});
```

- `signin` endpoint to decrypt the hashed password:-
- 