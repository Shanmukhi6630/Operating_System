# 🚦 Traffic Controller using Semaphores in C

This project is a simulation of a **traffic controller system** at a two-way intersection using **POSIX semaphores** and **pthreads** in C. The idea is to simulate how traffic from two or more directions can be managed efficiently without collisions using synchronization primitives (like semaphores).

This is useful for:
- Operating Systems and Concurrency concept demonstrations
- Embedded Systems simulations
- Learning thread synchronization with semaphores

---

## 🧠 Concepts Covered

| Concept            | Description |
|--------------------|-------------|
| **Threads**        | Simulate vehicles arriving from different directions using `pthread`. |
| **Semaphores**     | Used to control access to the critical section where only one direction of traffic can move at a time. |
| **Mutual Exclusion** | Only one thread (direction) can access the intersection at any given moment. |
| **Concurrency Control** | Ensures traffic simulation behaves predictably under concurrent execution. |

---


