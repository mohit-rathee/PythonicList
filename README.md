# PythonicList
Re-Implementation of Pythonic list in c.

### How Python List works:
- Lists in python are actually pre-allocated with some capacity, which is hidden to user.
- Even though you lists looks empty and has lenght=0. It already already allocated an array of let's say 50.
- That's why __append()__ function has __O(1)__ complexity. Because all it's doing is putting value in an array and increasing the size by 1.
- And when capacity is reached, then a new array with it's double size is allocated and whole data is copied to that new array(basically expand). Same happens when you pop from array(it shrinks).
- Best thing about these lists is that they can store multiple kind of data like int, char, char*(string), bool, list, dictionary etc. Well this is possible due to pointers, yeah instead of storing the string it stores the pointer to the string.

### Whats Done:
- Storing multiple type of data in list.
- Basic  functions like :- Append, Pop, insert, get, update, add, print, Free.
- Capacity logic (that expansion and shrinking).
  
### Some caveats:
- You don't need to free your strings, when you pop them.(It will check for refrence count.)
- When you have a list of too much String. Even if you pop all of them, c memory management will not give the empty space to kernal.(BUT hey you can use that later, if needed)

