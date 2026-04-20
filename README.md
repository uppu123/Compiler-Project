# 🚀 Mini Expression Compiler with AST & Intermediate Representation

## 📌 Overview

This project is a **modular mini-compiler** built in **C++** that translates arithmetic expressions into **Intermediate Representation (IR)** using standard compiler design techniques.

It simulates how real-world compilers (like those used in GPU architectures such as NVIDIA PTX) process high-level code and convert it into low-level instructions.

---

## 🧠 Key Concepts Implemented

* Lexical Analysis (Tokenization)
* Parsing (Infix → Postfix conversion)
* Abstract Syntax Tree (AST)
* Optimization (Constant Folding)
* Intermediate Code Generation (Three-address code)

---

## ⚙️ Project Architecture

```
Input → Tokenizer → Parser → AST → Optimizer → Code Generator → Output (IR)
```

---

## 🧩 Step-by-Step Workflow

### 🔹 1. Input Handling

User provides an arithmetic expression:

```
a = b * 2 + c * 3
```

---

### 🔹 2. Tokenization (Lexical Analysis)

The input string is broken into tokens:

```
[a, =, b, *, 2, +, c, *, 3]
```

Handled in:

```
tokenizer.cpp
```

---

### 🔹 3. Parsing (Infix → Postfix Conversion)

The expression is converted into postfix notation using stack-based parsing:

```
b 2 * c 3 * +
```

Handled in:

```
parser.cpp
```

---

### 🔹 4. AST Construction

A binary **Abstract Syntax Tree (AST)** is built from postfix expression.

Example Tree:

```
        +
       / \
      *   *
     / \ / \
    b  2 c  3
```

Handled in:

```
ast.cpp
```

---

### 🔹 5. Optimization (Constant Folding)

The compiler optimizes constant expressions:

```
3 * 2 → 6
5 + 6 → 11
```

Only applied when both operands are numeric.

Handled in:

```
optimizer.cpp
```

---

### 🔹 6. Intermediate Code Generation

The AST is traversed to generate **Three-Address Code (IR)**:

```
t1 = b * 2
t2 = c * 3
t3 = t1 + t2
a = t3
```

Handled in:

```
codegen.cpp
```

---

## 📁 Project Structure

```
mini-compiler/
│
├── src/
│   ├── main.cpp
│   ├── tokenizer.cpp
│   ├── parser.cpp
│   ├── ast.cpp
│   ├── optimizer.cpp
│   ├── codegen.cpp
│
├── include/
│   ├── tokenizer.h
│   ├── parser.h
│   ├── ast.h
│   ├── optimizer.h
│   ├── codegen.h
│
├── README.md
```

---

## ▶️ How to Run

### 🔧 Compile

```
g++ src/*.cpp -o compiler
```

### ▶️ Execute

```
./compiler
```

---

## 🧪 Example

### Input:

```
a = b * 2 + c * 3
```

### Output:

```
t1 = b * 2
t2 = c * 3
t3 = t1 + t2
a = t3
```

---

## 🛠️ Technologies Used

* C++
* STL (Stack, Vector, String)
* Data Structures (Trees, Stacks)

---

## 🎯 Learning Outcomes

* Understood compiler pipeline (frontend → IR → optimization)
* Implemented AST-based computation
* Learned intermediate code generation
* Applied optimization techniques used in real compilers

---

## 🚀 Future Improvements

* Support for parentheses and complex expressions
* Symbol table for variable tracking
* LLVM IR integration
* Code generation for assembly/PTX

---

## 💡 Inspiration

This project is inspired by real compiler architectures and demonstrates how high-level code is transformed into low-level instructions in systems like LLVM and GPU compilers.

---


