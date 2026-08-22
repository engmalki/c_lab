# Structs in C 🧠

This folder contains various C programs demonstrating how to use `struct` in different scenarios. Each file focuses on a specific concept such as pointers, copying, arrays, and dynamic memory.

## 📂 Programs

- 'Filling_CharArrays.c'
- 'FuncPtrsElements_2.c'
- 'FuncPtrsElements.c'
- 'Structs_Copy_with_Pointers_Elements_1.c' Demonstrates shallow copy behavior with structs containing pointers.
- 'StructsPointers.c' Demonstrates how pointers interact with structs, including value modification and pointer reassignment.
- 'Structs_Copy_with_Pointers_Elements_2.c'
- 'Wrapping_C-Arrays'   Demonstrates Wrapping C-array with a struct so we can use assignment operator to copy from one structure to another without need to a loop on each element.


## 📌 Key Concepts Covered

- Struct declaration and initialization
- Pointer to struct and dereferencing
- Copying structs vs referencing them
- Reassignment of struct pointers


## 🧪 How to Run
Compile with GCC:

```bash
    Example: gcc filename.c -o output && ./output
    
    # Filling_CharArrays.c
    gcc  Filling_CharArrays.c -o Filling_CharArrays && ./Filling_CharArrays
    
    # FuncPtrsElements_2.c
    gcc  FuncPtrsElements_2.c -o FuncPtrsElements_2 && ./FuncPtrsElements_2
 
    # FuncPtrsElements.c
    gcc  FuncPtrsElements.c -o FuncPtrsElements && ./FuncPtrsElements
    
    # Structs_Copy_with_Pointers_Elements_1.c
    gcc  Structs_Copy_with_Pointers_Elements_1.c -o Structs_Copy_with_Pointers_Elements_1 && ./Structs_Copy_with_Pointers_Elements_1
    
    # Structs_Copy_with_Pointers_Elements_2.c
    gcc  Structs_Copy_with_Pointers_Elements_2.c -o Structs_Copy_with_Pointers_Elements_2 && ./Structs_Copy_with_Pointers_Elements_2
    
    # StructsPointers.c
    gcc  StructsPointers.c -o StructsPointers && ./StructsPointers
 
    # Wrapping_C-Arrays.c
    gcc  Wrapping_C-Arrays.c -o Wrapping_C-Arrays && ./Wrapping_C-Arrays