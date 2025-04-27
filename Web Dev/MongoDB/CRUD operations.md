---
tags:
  - mongo
---
---

# CRUD Operations

CRUD operations in MongoDB refer to the basic operations you can perform on documents within a MongoDB database. CRUD stands for:

1. **Create**: Adding new documents to a collection.
2. **Read**: Retrieving documents from a collection.
3. **Update**: Modifying existing documents in a collection.
4. **Delete**: Removing documents from a collection.

![[Pasted image 20250427230016.png]]

#### 
**Let's assume we have a collection named "students" with documents like this:**

```javascript
{ "_id" : ObjectId("654321abcdef"), "name" : "Alice", "grade" : "A" }
{ "_id" : ObjectId("654321fedcba"), "name" : "Bob", "grade" : "B" }
```


**1. Create:**

* **Using `insertOne()`:** Adds a single document.

```javascript
db.students.insertOne( { "name" : "Charlie", "grade" : "C" } )
```

* **Using `insertMany()`:** Adds multiple documents.

```javascript
db.students.insertMany( [
  { "name" : "David", "grade" : "A" },
  { "name" : "Eve", "grade" : "B" }
] )
```


**2. Read:**

* **Using `find()`:** Retrieves documents matching a query.  Without a query, it retrieves all documents.

```javascript
// Find all students
db.students.find()

// Find students with grade A
db.students.find( { grade: "A" } )

// Find one student with grade A
db.students.findOne( { grade: "A" } )
```

* **Using `aggregate()`:** Allows for more complex queries and data transformations.  This is beyond basic CRUD, but important to mention.

```javascript
// Count students with each grade
db.students.aggregate( [ { $group: { _id: "$grade", count: { $sum: 1 } } } ] )
```


**3. Update:**

* **Using `updateOne()`:** Updates a single document matching a query.

```javascript
// Update Bob's grade to A
db.students.updateOne( { name: "Bob" }, { $set: { grade: "A" } } )
```

* **Using `updateMany()`:** Updates multiple documents matching a query.

```javascript
// Update all students with grade B to C
db.students.updateMany( { grade: "B" }, { $set: { grade: "C" } } )
```


**4. Delete:**

* **Using `deleteOne()`:** Deletes a single document matching a query.

```javascript
// Delete Charlie
db.students.deleteOne( { name: "Charlie" } )
```

* **Using `deleteMany()`:** Deletes multiple documents matching a query.

```javascript
// Delete all students with grade C
db.students.deleteMany( { grade: "C" } )
```


This expanded explanation provides more practical examples and shows the different methods available for each CRUD operation.  Remember to replace `"students"` with your actual collection name.  Also,  consider adding information about error handling and best practices for each operation.
