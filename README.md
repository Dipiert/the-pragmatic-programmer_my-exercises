## Exercise 11
Your C program uses an enumerated type to represent one of 100 states.
You’d like to be able to print out the state as a string (as opposed to a
number) for debugging purposes. Write a script that reads from standard
input a file containing

```
name
state_a
state_b
:
:
```
Produce the file name.h, which contains

```
extern const char* NAME_names[];
typedef enum {
    state_a,
    state_b,
      :
      :
} NAME;
```

and the file name.c, which contains

```
const char* NAME_names[] = {
  "state_a",
  "state_b",
      :
      :
};
```
