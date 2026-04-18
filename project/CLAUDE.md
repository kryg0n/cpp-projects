# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Goal

Implement and compare **at least 3 different methods** to find the most frequent duplicate element in a list of integers. If there's a tie in frequency, return the element that appears first in the list.

## OJ Input/Output Format

- Input: multiple test cases, each a single line of space-separated integers (up to 10^5 integers per line, each in range (-10^5, 10^5))
- Output: one line per test case — the most frequent duplicated element

```
Input:        Output:
-1 1 -1 8     -1
1 2 3 3 3 4   3
```

## Build Command

```bash
g++ -std=c++11 -O2 -lm solution.cpp -o solution
```

## I/O Pattern

Use normal Cin/Cout. Read a full line per test case and parse integers from it.
