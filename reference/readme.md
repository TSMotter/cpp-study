# reference

- "References are just pointers in disguise"
- Syntax sugar on top of pointers to make it easier to read and follow
- A reference can be seen as an `alias`

- **While you can create a new pointer variable and set it to `nullptr`, you can't do that with a reference**
  - A reference always actually references some variable that already exists

- **Once you create a reference, you cannot change what it references to**
```C++
int  a   = 5;
int  b   = 10;
int& ref = a;

// -> this is equal to doing "a = b;"
ref = b;
```