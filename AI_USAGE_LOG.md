# AI Usage Log

**Project:** AI-Assisted Student Record and Result Management System  
**Course:** Programming in C (PRC1001)  
**SAP ID:** 590033722

## 1. AI Assistance — Academic Advisor

**AI Tool Used:** OpenCode

**Purpose:** To understand and design a simple CGPA-based Academic Advisor for my C programming project.

**Prompt Asked:** I asked OpenCode to suggest four academic performance categories, suitable CGPA ranges, practical academic recommendations, simple if-else logic, and boundary test cases.

**Suggestions Received:** OpenCode suggested four performance categories using CGPA boundaries of 8.5, 7.0, and 6.0.

**Review and Modifications:** I reviewed the suggested categories and simplified the academic advice. I also changed the recommendation about identifying weak subjects because my program stores semester-wise SGPA rather than individual subject marks.

**Implementation:** I implemented the recommendations using C if-else statements and my existing CGPA calculation function. No external AI API is used.

### Academic Advisor Testing

I tested the Academic Advisor using the following student records:

| Student | CGPA | Expected Category | Result |
|---|---:|---|---|
| Rahul Verma | 8.50 | Excellent Performance | Passed |
| Aarav Mehta | 7.50 | Good Performance | Passed |
| Simran Kaur | 6.32 | Needs Improvement | Passed |
| Priya Verma | 5.33 | Requires Immediate Attention | Passed |
| Karan Singh | Not available | No academic advice | Passed |

All four categories and the missing-SGPA case produced the expected recommendations.

## 2. AI Assistance — Understanding and Debugging C

**AI Tool Used:** ChatGPT

**Purpose:** To understand C programming concepts and identify errors during project development.

**Questions Asked:**
- How can structures and arrays be used to store multiple student records?
- How do pointers allow a function to update the student count?
- How can CGPA be calculated using available SGPA values?
- How can Bubble Sort be used to arrange student records?
- How can invalid inputs and duplicate SAP IDs be handled?

**Useful Suggestions:** ChatGPT explained structures, functions, pointers, loops, sorting, input validation, and debugging techniques.

**How I Used and Verified the Suggestions:** I reviewed the explanations, applied changes to my C program, compiled it using GCC, and tested the functions using different student records.

During testing, I corrected issues involving student-name input, duplicate SAP IDs, invalid menu choices, year and semester validation, and SGPA input.

## 3. Final Verification

I tested the program using five student records and checked the following features:

- Adding, searching, displaying and deleting student records.
- Calculating individual CGPA and year-wise average CGPA.
- Sorting students by SAP ID and name.
- Generating academic recommendations.
- Handling invalid names, duplicate SAP IDs, invalid year/semester combinations, invalid SGPA values and nonnumeric menu choices.

The successful test output and negative test output are included in the `tests` folder.

## 4. Conclusion

AI tools helped me understand programming concepts, design the Academic Advisor, debug errors and prepare test cases.

I reviewed the suggestions and tested the implementation instead of using the AI responses without checking them.

The final Academic Advisor is a simple rule-based feature written in C using if-else statements. It does not use machine learning or connect to an external AI API.