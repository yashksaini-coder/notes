---
tags:
  - mongo
---
---

The structure of a simple database commonly seen in apps depends heavily on the app's purpose. However, a common pattern involves several core tables related through foreign keys.  

**Tables:**

* **Users:**
	* `user_id` (INT, PRIMARY KEY, AUTO_INCREMENT): Unique identifier for each user.
	* `username` (VARCHAR(255), UNIQUE): User's username (must be unique).
	* `email` (VARCHAR(255), UNIQUE): User's email address (must be unique).
	* `password_hash` (VARCHAR(255)): Hashed password for security.
	* `first_name` (VARCHAR(255)): User's first name.
	* `last_name` (VARCHAR(255)): User's last name.
	* `created_at` (TIMESTAMP): Timestamp indicating when the user was created.

**Relationships:**

* **One-to-many:**  A user can have many orders (Users 1:N Orders).
* **One-to-many:** A category can have many products (Categories 1:N Products).
* **One-to-many:** An order can have many order items (Orders 1:N Order_Items).
* **Many-to-one:** An order item belongs to one order (Order_Items N:1 Orders).
* **Many-to-one:** An order item belongs to one product (Order_Items N:1 Products).


This is a simplified example.  A real-world e-commerce app would likely have more tables (e.g., for reviews, payments, shipping information, etc.) and more complex relationships.  The key is to normalize the data (avoid redundancy) and use foreign keys to establish relationships between tables.  The choice of database (MySQL, PostgreSQL, SQLite, etc.) will influence specific data types and features.
