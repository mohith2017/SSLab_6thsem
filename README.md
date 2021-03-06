# SSLab_6thsem
All the programs executed for the 6th sem of Engineering

# Instructions to Execute:

## Lex:
```
lex "program name".l
cc lex.yy.c -ll
./a.out
```

## Yacc:
```
lex "program name".l
yacc "".c
cc lex.yy.c y.tab.c -ll
./a.out
```


# Implement the following using C/C++ for the SIC Machine:
1. Pass-1 of two-pass assembler.
2. Pass-2 of two-pass assembler to produce the object code.
3. Generate object program using the object code.
4. Absolute loader.
5. Relocating loader using bit mask.
6. One-pass macroprocessor.


# LEX Exercises:
1. Develop and implement a lex program to count the number of characters, words, spaces and lines in a
given input file.
2. Develop and implement a lex program to count the number of identifiers, operators and comment lines
in a given C program.
3. Develop and implement a lex program to recognize a valid arithmetic expression and identify the
identifiers and operators present.
4. Develop and implement a lex program to count the number of vowels, consonants, numbers, special
characters and lines in a given input file.
5. Develop and implement a lex program to count the number of
a) + ve and – ve numbers b) +ve and –ve fractions.

# YACC Exercises:
1. Develop and implement a YACC program to recognize a valid arithmetic expression that uses
operators + ,- ,* and /.
2. Develop and implement a YACC program to recognize a valid variable, which starts with a letter,
followed by any number of letters or digits.
3. Develop and implement a YACC program to evaluate an arithmetic expression involving operators +,-
,* and /.
4. Develop and implement a YACC program to recognize the strings of the form ambn, where
m>=0,n>=0.
5. Develop and implement a YACC program to accept an integer number with more than 3 digits.
