# smart-pointers

- Wrapper around a raw pointer
  - Under the hood, it calls `new` for you and later `delete`
    - The "later" depends on which type of smart pointer you are using

- Rule of thumb:
  - Prefer using `unique_ptr`, then `shared_ptr`

## unique_ptr
- scoped pointer: when it goes out of scope, the object is deleted
- Can't be copied
  - Otherwise, one of the copies goes out of scope (dies), the other copy will be pointing to an memory region that has been free'd

## shared_ptr
- The detail about how the shared_ptr is implemented are compiler/libraries specific
- Generally speaking, it implements a `reference counter`
  - Keeps track of how many references there are to the pointer
  - Once that reference counter gets to 0, it deletes the pointer

## weak_ptr
- Can be assigned to the value of a shared_ptr
- It doesn't increase the `reference counter`, 
- Great when you don't want to take ownership of the object
  - It will not keep the object alive for longer
  - Ex: when you just want to store a reference of something
- It can point to some expired object