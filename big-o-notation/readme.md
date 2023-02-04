# Big O notation

- Simplified analysis of an algorithm efficiency (time and space analysis can be done)

- Gives algorithm complexity in terms of input size (N)

- Machine independent, it rather takes into account basic computer steps

## Types of measurements

- Worst case
  - Typically the most relevant

- Best case

- Average case

## General rules

- Ignore constants
  - 5n -> O(n), considering that if "n" gets too big, the constant part is not relevant anymore

- Certain terms "dominate" others
  - O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(2^n) < O(n!)

  - Low order terms are ignored when they are dominated by a higher order one

## Examples

- Example 1:
  ```Python
  for k in range(0, n):
    print(x)
  ```

  - `print(x)` is O(1)
  - So the `for` loop will be: n*O(1) = O(n)

- Example 2:
  ```Python
  y = 5 + (15*20)
  for k in range(0, n):
    print(x)
  ```

  - `y = 5 + (15*20)` is O(1)
  - The `for` loop is O(n)
  - Because there is a dominant term, we can drop O(1) and the final big-O notation for this snippet will be O(n)
    - The `for` loop dominates the run time

- Example 3:
  ```Python
  for k in range(0, n):
    for j in range(0, n):
      print(j*x)
  ```

  - Each of the `for` loops is O(n)
  - The final big-O notation for this snippet will be O(n^2)

- Example 4:
  ```Python
  if x == 0:
    #Something that is O(1)
  elif x > 0:
    #Something that is O(logn)
  else:
    #Something that is O(n^2)
  ```

  - In this case we know the big-O for each individual block of the `if-else` statement
  - Because we should consider the worst case scenario, the final big-O notation for this snippet will be O(n^2)