A collection of high-performance, robust, and dynamically sized data structures written in pure C. 

Currently, the project features **`astring`** — a C-implementation of a dynamic string inspired by C++ `std::string`, providing safe memory management, advanced pattern matching, and minimal allocation overhead.

## 📦 Data Structures Roadmap
- [x] **`astring`** (Dynamic Strings)
- [ ] *[Vector / Dynamic Array] - planned*
- [x] **`linkedlist`** (Generic Singly Linked List)
- [ ] *[Hash Map] - planned*

---

## 🧵 `astring` Module

### Key Features
* **Safe Memory Management:** Built-in protection against buffer overflows and memory leaks.
* **Geometric Growth:** Smart capacity reallocation ($O(1)$ amortized time complexity) for efficient `pushback` and `append` operations.
* **Fast Substring Search:** Utilizes the **Boyer-Moore-Horspool (BMH)** algorithm for blazing fast `find()` and `rfind()` operations ($O(N)$ text traversal with skipping heuristics).
* **Zero-Cost Abstractions:** Features like $O(1)$ `swap()` that strictly manipulate pointers without touching the heap.

### Quick Start

```c
#include <stdio.h>
#include "astring.h"

int main() {
    // Allocation
    string* str = strnew("Hello");
    string* name = strnew("World");

    // Modification
    append(str, name);           // "HelloWorld"
    insert(str, ", ", 5);        // "Hello, World"
    pushback(str, '!');          // "Hello, World!"

    size_t pos = find(str, name); 
    if (pos != (size_t)-1) {
        printf("Found at index: %zu\n", pos);
    }

    // Always free to prevent memory leaks
    strfree(name);
    strfree(str);

    return 0;
}

## 🔗 `linkedlist` Module

### Key Features
* **Type-Agnostic (Generic):** Stores any data type via `void*` payload, allowing for polymorphic lists.
* **Smart Memory Management:** Injection of custom destructor callbacks (`void (void*)`) in `destroylist` and popping operations prevents memory leaks of heap-allocated payloads.
* **Safe Pattern Matching:** Uses function pointers for comparators (`int (void*, void*)`) to ensure accurate node lookup in `lfind` and `keyremove`.
* **In-Place Operations:** Zero-allocation utilities like $O(N)$ `lreverse` manipulate pointers directly without touching the heap.

### Quick Start

```c
#include <stdio.h>
#include "linkedlist.h"

int main() {
    Node* head = NULL;

    // Population
    binsert(&head, "First");
    lpushback(head, "Second");

    // Access & Utilities
    printf("List size: %zu\n", llength(head));
    
    void* val = lpopback(&head);
    if (val) printf("Popped: %s\n", (char*)val);

    // Always free the container (pass NULL if payload isn't heap-allocated)
    destroylist(&head, NULL);

    return 0;
}
