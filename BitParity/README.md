# Bit Parity

## Problem

A friend received this question in a technical interview. He was asked to determine whether an integer's binary representation contains an odd or even number of "on" bits (1's). Return 1 if the number contains an odd number of 1's, and 0 if it contains an even number of 1's.

## Solution

While my binary/bitwise operation skills are not the strongest yet, I realized that repeatedly bitshifting a number right by 1 eliminates bits one-by-one, and at the beginning of each iteration--before the bitshift right--the bit that is about to be removed determines whether a number is odd or even.

A counter variable is initialized to 0 before the loop, and the first way I thought to determine the value of the least significant bit was by checking the current value of the number modulo 2. In the case that `bitshiftedCopy % 2 == 1`, the counter is incremented by 1. Regardless of the magnitude of the first number or of the values of its more significant bits, all bits will become zero when anded with 1, except for the least-significant 1's bit _if and only if that bit is 1, i.e. if the number is odd_.

I was also able to remove the conditional. Initially I had:

```cpp
if (bitshiftedCopy & 1 == 1) {
    counter++;
}
```

I realized I can simply add `bitshiftedCopy & 1` to the counter, as the result of that operation will only ever be 0 or 1:

```cpp
counter += bitshiftedCopy & 1;
```

The loop breaks when `bitshiftedCopy` becomes 0 or -1, and 1 is returned in the case that `counter` is odd, or 0 in the case that it's even. This again is done by simply returning `counter & 1`.
