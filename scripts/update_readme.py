#!/usr/bin/env python3

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
README_PATH = ROOT / "README.md"
START_MARKER = "<!-- AUTO-GENERATED:START -->"
END_MARKER = "<!-- AUTO-GENERATED:END -->"


def normalize_problem_name(folder_name: str) -> str:
    """Convert a folder name like '1046-max-consecutive-ones-iii' into a readable title."""
    name = folder_name.split("-", 1)[1] if "-" in folder_name else folder_name
    cleaned = name.replace("-", " ")
    words = cleaned.split()
    normalized = []
    for word in words:
        lower = word.lower()
        if lower in {"i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix", "x"}:
            normalized.append(lower.upper())
        elif word.isdigit():
            normalized.append(word)
        else:
            normalized.append(word.capitalize())
    return " ".join(normalized)


def get_problem_dirs() -> list[str]:
    dirs = []
    for entry in sorted(ROOT.iterdir(), key=lambda p: p.name.lower()):
        if not entry.is_dir():
            continue
        if entry.name in {".git", ".github", "scripts"}:
            continue
        if re.fullmatch(r"\d+[-].+", entry.name):
            dirs.append(entry.name)
    return dirs


def build_tracker() -> str:
    problem_dirs = get_problem_dirs()
    rows = [
        "| # | Problem | Status |",
        "|---:|---|:---:|",
    ]
    for folder in problem_dirs:
        match = re.match(r"^(\d+)", folder)
        num = match.group(1) if match else "0"
        title = normalize_problem_name(folder)
        href = f"./{folder}"
        rows.append(f"| {num} | [{title}]({href}) | ✅ |")
    return "\n".join(rows)


def build_readme() -> str:
    problem_dirs = get_problem_dirs()
    total = len(problem_dirs)

    return f'''# Daily LeetCode Problem

[![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![LeetCode](https://img.shields.io/badge/Practice-LeetCode-orange.svg)](https://leetcode.com/)
[![Problems Solved](https://img.shields.io/badge/problems%20solved-{total}-success.svg)](https://github.com/Rishi-Kumar85/DailyLeetcodeProblem)
[![Repository](https://img.shields.io/badge/GitHub-DailyLeetcodeProblem-black.svg)](https://github.com/Rishi-Kumar85/DailyLeetcodeProblem)

This repository contains my daily LeetCode problem-solving practice, primarily implemented in C++.

## Overview

Each folder represents one LeetCode problem and follows the naming pattern:

```text
problem-number-problem-name
```

Examples:

```text
104-maximum-depth-of-binary-tree
141-linked-list-cycle
2050-count-good-numbers
2559-maximum-number-of-non-overlapping-palindrome-substrings
```

## Topics Covered

- Arrays
- Strings
- Linked Lists
- Trees
- Hashing
- Dynamic Programming
- Greedy Algorithms
- Sliding Window
- Binary Search
- Graphs
- Mathematics
- Bit Manipulation

## Problem Tracker

**Total problems solved: {total}**

{START_MARKER}
{build_tracker()}
{END_MARKER}

## How to Run

Compile a C++ solution with:

```bash
g++ solution.cpp -std=c++17 -O2 -o solution
./solution
```

## Goals

- Solve daily
- Strengthen Data Structures and Algorithms concepts
- Improve coding speed and accuracy
- Build a reusable problem-solving archive

## Author

[Rishi Kumar](https://github.com/Rishi-Kumar85)
'''


def main() -> None:
    README_PATH.write_text(build_readme(), encoding="utf-8")


if __name__ == "__main__":
    main()
