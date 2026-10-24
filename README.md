# Student Record Manager Using C++

A menu-driven console application for storing student records and analysing subject marks. This project demonstrates object-oriented programming through classes, objects, member functions, arrays and strings.

Developed as a Cornerstone Project for **Object Oriented Programming through C++ (2501CS08)**, Department of Artificial Intelligence and Machine Learning, **Aditya University**, academic year **2026–2027**.

## Project overview

The application stores each student's roll number, full name and marks in five subjects: **C++, DSA, Java, English and DAE**. Users can maintain up to **100 student records** during a program session.

Two classes organise the implementation:

- **`Student`** stores one student's information and provides `input()` and `display()` functions.
- **`StudentRecordManager`** manages the array of student objects and provides the menu, record operations and marks analysis.

## Repository files

The links below use the uploaded filenames. Keep these files and `README.md` together in the repository's main folder. If a file is renamed, update its link and any compilation command that uses it.

| File | Description |
| --- | --- |
| [Project(1).cpp](./Project%281%29.cpp) | Complete C++ source code. |
| [C++ review - 1pptx(1).pptx](./C%2B%2B%20review%20-%201pptx%281%29.pptx) | Review 1 presentation covering project planning and design. |
| [cpp review - 2(1).pptx](./cpp%20review%20-%202%281%29.pptx) | Review 2 presentation covering proposed modules, implementation and team contributions. |
| [Student_Record_Manager_Documentation(1).docx](./Student_Record_Manager_Documentation%281%29.docx) | Project report with diagrams, source code, sample outputs, testing and conclusions. |
| [README.md](./README.md) | Project overview and instructions for running the application. |

## Features

- Add a student with a numeric roll number, full name and five subject marks.
- Display all stored student records.
- Search for a student by roll number.
- Calculate each student's total marks, highest and lowest subject marks, average and percentage.
- Update an existing student's roll number, name and marks.
- Delete a student record and shift the remaining records to close the gap.
- Reject numeric marks outside the range **0 to 100**.
- Prevent additions when the **100-record limit** is reached.

## Menu options

| Option | Operation |
| --- | --- |
| 1 | Add Student |
| 2 | Display All Students |
| 3 | Search Student |
| 4 | Marks Analysis |
| 5 | Update Student |
| 6 | Delete Student |
| 7 | Exit |

## Technologies and concepts

- **Language:** C++
- **Standard library headers:** `<iostream>` and `<string>`
- **OOP concepts:** classes, objects, constructor, member functions, composition and encapsulation of manager state
- **Data structures:** fixed array of student objects and arrays of marks
- **Other concepts:** strings, linear search, loops, conditional statements and console input/output

The manager's record array and count are private. The fields in `Student` are public in this implementation. Inheritance and runtime polymorphism are not used.

## How to compile and run

### Requirements

- A C++ compiler supporting C++17, such as GCC or Clang.
- A terminal or an IDE configured to compile C++ programs.

No database or third-party library is required.

Download the source file and open a terminal in the folder containing **`Project(1).cpp`**. Keep the quotation marks around the filename in the commands below.

### Windows with GCC installed

Compile:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic "Project(1).cpp" -o student_record_manager.exe
```

Run in PowerShell:

```powershell
.\student_record_manager.exe
```

### Linux or macOS with a C++ compiler installed

Compile:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic "Project(1).cpp" -o student_record_manager
```

Run:

```bash
./student_record_manager
```

Enter a menu number and follow the prompts. Use numeric roll numbers such as `101`; the current program does not accept alphanumeric university registration IDs.

## Example marks analysis

Add a student with roll number `101`, name `Asha Rao`, and the following marks:

| Subject | Marks out of 100 |
| --- | ---: |
| C++ | 80 |
| DSA | 90 |
| Java | 70 |
| English | 85 |
| DAE | 75 |

Choose **4 — Marks Analysis**. The result for this student is:

```text
Student: Asha Rao
Roll No: 101
Total Marks: 400/500
Highest Marks: 90 (DSA)
Lowest Marks: 70 (Java)
Average Marks: 80/100
Percentage: 80%
```

The highest and lowest values compare the five subjects **within each student**. They do not rank students across the class. When subject marks tie, the first matching subject in the fixed subject order is reported.

## Current limitations

- **Temporary storage:** records are held in memory and are lost when the program exits.
- **Marks labels:** validation accepts marks from 0 to 100, but record display currently prints `/50`, and the invalid-mark message says `0 and 50`. These labels are inconsistent with the implemented scale. Total and percentage calculations use 500 maximum marks.
- **Input validation:** duplicate roll numbers, zero or negative roll numbers and blank names are not rejected. Non-numeric input where numbers are expected is not safely handled.
- **First-match operations:** search, update and delete act on the first matching roll number.
- **Scope:** name-based search, class averages, name formatting, attendance, login roles and persistent storage are not implemented. Some of these appear as planned features in the review presentations.

## Future improvements

- Correct the marks labels and improve input validation.
- Support unique alphanumeric roll numbers.
- Add file or database storage to retain records between runs.
- Add name-based search and class-level performance analysis.
- Introduce a graphical interface and user permissions if required.

## Team members

| Name | Roll number | Contribution |
| --- | --- | --- |
| Kappala Hemanth Sai Venkata Vidya Sagar | 25B11AI494 | OOP class design and student management |
| Baluguri Ganesh | 25B11AI084 | Student data and marks management |
| Gannabathula Sai | 25B11AI320 | Search, marks analysis and testing |
| Ayenavalli Keerthu Praveen | 26B21AI0132 | Documentation, presentations and project reporting |

**Project guide:** T. Vijaya Lakshmi, Assistant Professor, Department of Artificial Intelligence and Machine Learning, Aditya University.

Team details follow the project documentation and the Review 2 contribution table.

## Project purpose

This academic project applies C++ programming concepts to a small student record management application. The presentations and report document its planning, design, implementation and evaluation.
