# Hash Table Database in C
Using An Open Guide to Data Structures and Algorithms by Paul W. Bible and Lucas Moser to implement a hash table based database

A modular hash table implementation written from scratch in C. The project demonstrates low-level software design, manual memory management, generic interfaces using function pointers, and two collision resolution strategies.

The primary goal of this project is educational: to strengthen systems programming skills, software architecture, and data structure implementation without relying on external libraries.

---

## Features

- Generic `HashMap` interface
- Runtime selection of hash table implementation
- Function pointers for implementation-specific operations
- Manual memory management
- Modular source organization
- Student database example

### Collision Resolution

#### Open Addressing

- Quadratic probing
- Generic hash function
- Tombstone support for deletion

#### Separate Chaining

- Singly linked lists
- One linked list per bucket
- Dynamic node allocation

---

## Project Structure

```
.
├── hashmap.c
├── hashmap.h
├── hashmap_open.c
├── hashmap_open.h
├── hashmap_chain.c
├── hashmap_chain.h
├── linkedlist.c
├── linkedlist.h
├── student.c
├── student.h
└── main.c
```

---

## Design

The `HashMap` structure provides a generic interface independent of the underlying collision handling implementation.

```c
struct HashMap {
    void *hashData;

    void (*insertStudent)(...);
    void (*removeStudent)(...);
    int  (*searchStudent)(...);

    int tableSize;
    enum type implementation;
};
```

Implementation-specific data is stored through a `void *` pointer.

During initialization, the hash table configures the appropriate data structure and assigns the correct function pointers.

This allows client code to interact with the hash table without needing to know whether it is using open addressing or separate chaining.

---

## Data Structures

### Student

Stores

- Student ID
- Name
- Email

---

### Node

Represents a node in a singly linked list.

Each node owns a `Student` object.

---

### Linked List

Used as buckets for the separate chaining implementation.

Supports

- insertion
- removal
- search
- destruction

---

### Open Addressing

Stores students directly inside an array.

An additional status array tracks

- Empty
- Occupied
- Deleted (tombstone)

---

## Hash Function

Both implementations use the student's key to compute the initial bucket index.

The probing implementation computes additional probe locations using quadratic probing.

---

## Building

Compile using GCC (in root directory):

```bash
gcc -Iinclude -Wall -Wextra src/*.c -o hashmap
```

Run (in root directory):

```bash
./hashmap
```

---

## Concepts Practiced

- C Programming
- Dynamic Memory Management
- Modular Software Design
- Generic Interfaces
- Function Pointers
- Hash Tables
- Open Addressing
- Separate Chaining
- Linked Lists
- Pointer Ownership
- API Design

---

## Future Improvements

- Resize / Rehash support
- Iterator interface
- Generic key/value storage
- Unit tests
- Performance benchmarking
- Additional probing strategies
