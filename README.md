# Magical Container & Custom Iterators 🧙‍♂️✨

## 🗺️ Overview

**The Quest for the Magical Iterators** is a fantasy-themed C++ project that implements a custom container and multiple traversal strategies using advanced iterator patterns.

In the ancient land of **Iteratia**, a magical container was said to hold the balance of the kingdom. Only by mastering the secrets of the **three iterators** can its power be fully restored.

This project showcases:
- Custom container implementation in C++
- Iterator design and operator overloading
- Traversal logic: ascending, cross-order, and prime-filtered
- Deep understanding of OOP and STL-style behavior

---

## 🧪 Features

- `MagicalContainer` – a dynamic container for mystical elements (integers)
- `AscendingIterator` – iterates in ascending order
- `SideCrossIterator` – iterates in cross pattern (start-end-start-end...)
- `PrimeIterator` – iterates only over prime elements
- All iterators support:
  - Copy/assignment constructors
  - Operator overloading: `==`, `!=`, `<`, `>`, `*`, `++`
  - Strong exception safety
  - O(1) memory and time per iterator step
- Live-update support: iterators reflect changes in container dynamically

---

## ⚙️ How to Run

```bash
make
bash grade      # run test cases
make tidy       # formatting
make valgrind   # memory checks
