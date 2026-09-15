# Book Inventory Management System (Hash Table in C)

A lightweight and efficient CLI-based Book Inventory Management System implemented in **C**. This program utilizes a custom **Hash Table** with **Mid-Square Hashing** and **Separate Chaining** for collision handling to perform $O(1)$ average-case operations for data insertion, searching, and display.

---

## Authors / Team Members

* **Angelina Jolie Candaya** – `2802541644`
* **Aqila Nailal Husna** – `2802530565`
* **Elizaveta Falisha Susanto** – `2802530590`
* **Fauzan Surya Yudistira** – `2802544841`

---

## Overview & Theory

In computer science, efficient data organization and retrieval are critical as data volume grows. Traditional linear data structures like arrays or linked lists require $O(n)$ search time, which is inefficient for large datasets. 

A **Hash Table** addresses this limitation by using a **Hash Function** to map unique keys (e.g., Book Titles) into array indices, enabling near-instantaneous $O(1)$ average-case access time for basic operations.

### Key Characteristics of Hashing
* **Deterministic:** The same input always generates the same output.
* **Non-Reversible:** One-way function execution; input cannot be recovered directly from the hash.
* **Uniform Distribution:** Evenly spreads keys across the hash table to minimize collisions.
* **Avalanche Effect:** A tiny change in the key results in a significantly different hash output.

---

## Core Technical Implementation

### 1. Hash Function (Mid-Square Method)
The key (Book Title) is converted into a numeric value using a weighted ASCII sum ($total = \sum key[i] \times (i + 1)$). The resulting total is squared, and its middle digits are extracted to derive the index:
$$\text{Index} = \text{MidTwoDigits}(\text{Total}^2) \pmod{\text{TABLE\_SIZE}}$$

### 2. Collision Handling (Chaining)
When two different keys hash to the same array index, the collision is handled using **Separate Chaining**. Each slot in the hash table points to a dynamically allocated Singly Linked List of `Node` items.

---

## Features & Supported Operations

* **Insert Data:** Adds single or multiple book titles along with their stock quantities into the Hash Table.
* **Search Data:** Rapidly looks up a book title by hashing its key to retrieve its stock quantity.
* **Display Data:** Visualizes the current state of the Hash Table, showing indices and chained nodes.
* **Memory Management:** Dynamic allocation using C standard library `malloc`.

---

## Code Architecture & Function Documentation

* `struct Node`: Structure representing a book node (`key` = Title, `value` = Stock, `next` = Linked List Pointer).
* `Node* hashTable[10]`: Array of linked list head pointers with size 10.
* `int hash(const char* key)`: Computes the target index via the Mid-Square algorithm.
* `void insert(const char* key, const char* value)`: Dynamically creates a new node and prepends it to the linked list at the computed hash index.
* `void search(const char* key)`: Computes the hash index and traverses the chain to find a matching book title.
* `void display()`: Traverses and prints all indices of the hash table and their respective chained nodes.
* `void inputData()`: CLI handler to take user input for multiple book items.

---

## Getting Started

### Prerequisites
* A C Compiler (GCC, Clang, or MSVC)
* Terminal or Command Prompt

### Building & Running the Program

**Clone the repository:**
   ```bash
   git clone [https://github.com/your-username/hashtable-book-inventory.git](https://github.com/your-username/hashtable-book-inventory.git)
   cd hashtable-book-inventory
```

---

## Project Links & Resources

* Presentation Video : https://drive.google.com/file/d/1ZzoBXLNJ0my0mruezziGMH1QwQ-BeSeW/view?usp=drive_link
* Power Point : https://www.canva.com/design/DAGf5XMOap8/QGGJFMn06w8agJCDjeiqBQ/edit?utm_content=DAGf5XMOap8&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton


