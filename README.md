# Student Record and Result Management System

**Course:** Programming in C (PRC1001)  
**University:** University of Petroleum and Energy Studies (UPES)  
**Program:** B.Tech CSE, Semester I  
**SAP ID:** 590033722

## About the Project

This is a menu-driven Student Record and Result Management System developed in C as part of my first-semester programming assignment.

The program maintains student records, calculates academic results, and provides simple academic recommendations based on CGPA.

## Features

1. Add student records with SAP ID, roll number, name, phone, email, year, semester and SGPA.
2. Search students using SAP ID.
3. Calculate CGPA using available semester SGPA values.
4. Calculate average CGPA for each academic year.
5. Display all student records.
6. Delete individual student records.
7. Sort students by SAP ID in ascending order.
8. Sort students alphabetically by name.
9. Generate CGPA-based academic advice.

The program also includes input validation and duplicate SAP ID checking.

## Technologies Used

- C programming language
- GCC compiler
- Visual Studio Code
- Git and GitHub

## How to Compile and Run

Open a terminal in the project directory.

Compile:

```bash
gcc -Wall -Wextra -std=c11 590033722.c -o student
```

Run on Windows:

```powershell
.\student.exe
```

## CGPA Calculation

CGPA is calculated as the average of available semester SGPA values.

For example, if a student has SGPA values of 8.0, 8.5 and 9.0:

CGPA = (8.0 + 8.5 + 9.0) / 3 = 8.50

Unavailable SGPA values are represented internally by -1 and excluded from the calculation.

## Academic Advisor

The Academic Advisor is a rule-based feature developed with assistance from AI tools.

| CGPA | Performance Category |
|---|---|
| 8.50–10.00 | Excellent Performance |
| 7.00–below 8.50 | Good Performance |
| 6.00–below 7.00 | Needs Improvement |
| Below 6.00 | Requires Immediate Attention |

The recommendations are generated through C `if-else` statements. The program does not connect to an external AI API.

These thresholds are project-defined and are not official university grading rules.

## Algorithms and Concepts

- Structures and arrays of structures
- Functions and pointers
- Loops and conditional statements
- Linear search
- Bubble sort
- String comparison using `strcmp()`
- Input validation

## Testing

The `tests` folder contains sample input and output demonstrating student management, CGPA calculations and Academic Advisor recommendations.

## Limitations

- Student records are currently stored in memory and are lost when the program exits.
- The program supports up to 100 student records.
- The Academic Advisor uses fixed rules rather than a live AI model.

## AI Assistance

OpenCode and ChatGPT were used as learning assistants for academic-advisor design, understanding C concepts, debugging and testing.

Details are documented in `AI_USAGE_LOG.md`.