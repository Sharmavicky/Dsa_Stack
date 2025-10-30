# 🧠 DSA Journey — Stack Data Structure

Welcome to my **Stack Data Structure** section of the **DSA Journey 🚀**.  
This folder contains all the problems I’ve solved and implemented related to the **Stack** concept in Data Structures.

Each implementation focuses on understanding stack behavior — **LIFO (Last In, First Out)** — and how it can be applied to solve a variety of algorithmic problems.

---

## 📂 Folder Overview
```
Dsa_Stack/
├── Stack.cpp # Implementation using List (custom linked list stack)
├── vectorStack.cpp # Implementation using STL vector
├── [other problem files] # Example: NextGreaterElement.cpp, ValidParentheses.cpp
├── README.md # You’re here
```

---

## ⚙️ Topics Covered

Here are some of the problems and concepts explored in this folder 👇

| # | Problem | Approach | Concept Highlight |
|---|----------|-----------|-------------------|
| 1️⃣ | Stack Implementation (Vector) | Using `std::vector` | Dynamic array-based stack |
| 2️⃣ | Stack Implementation (Linked List) | Custom `List` class | Pointer-based stack, manual memory management |
| 3️⃣ | Valid Parentheses | Stack-based validation | Matching brackets using stack logic |
| 4️⃣ | Next Greater Element | Using stack traversal | Monotonic stack pattern |
| 5️⃣ | Evaluate Reverse Polish Notation | Using stack for expression evaluation | Postfix computation |
| 6️⃣ | Implement Min Stack | Two-stack approach | Constant-time min retrieval |

*(More problems will be added as I continue my DSA learning journey 📈)*

---

## 🧩 Key Learnings

- Deep understanding of **stack operations**: `push()`, `pop()`, and `top()`  
- Difference between **array-based** and **linked list-based** stack implementations  
- Applying stacks to simplify complex problems like **expression parsing** and **recursion simulation**  
- Improved understanding of **pointer manipulation**, **memory management**, and **algorithmic problem-solving**

---

## 🧰 Tech & Tools

- **Language:** C++  
- **Compiler:** g++  
- **Custom Headers:** `List.h`, `List.cpp` (used for linked list-based stack)  
- **IDEs:** VS Code / Code::Blocks  

---

## 🧪 How to Run

If your project structure looks like this:
```
ProjectRoot/
├── DSA_Linked_List/
│ ├── List.cpp
│ └── List.h
└── Dsa_Stack/
├── Stack.cpp
└── README.md
```

### ▶️ Compile and Run:
```bash
# from ProjectRoot
g++ Dsa_Stack/Stack.cpp DSA_Linked_List/List.cpp -I DSA_Linked_List -o Stack
./Stack

📚 Learning Goal

🔹 This repository is part of my daily DSA practice, where I:
🔹Solve at least one problem per day 💪
🔹Document every solution clearly ✍️
🔹Share my progress and insights on LinkedIn and GitHub 🌱

📈 Next Problem Tracker
Upcoming Focus	Description
🔜 Min Stack	Design a stack supporting constant-time getMin()
🔜 Daily Temperatures	Apply Monotonic Stack concept
🔜 Largest Rectangle in Histogram	Advanced stack-based interval logic

🌐 Connect With Me

👨‍💻 GitHub: https://github.com/Sharmavicky
💼 LinkedIn: https://www.linkedin.com/in/sharma-vicky/
📘 LeetCode: https://leetcode.com/u/Sharmavicky/
✖️ Twitter (X): https://x.com/Sharmavicky_93

“The more you understand data structures, the more intuitive problem-solving becomes.” 💭
Keep coding. Keep improving. 🚀