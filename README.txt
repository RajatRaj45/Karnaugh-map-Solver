# Karnaugh-map-Solver
It is a program that can:
  1. Generate the most condensed boolean expression from a K map of any no. of variables
  2. Generate the K map from a boolean expression consisting of any no. of variables.


HOW TO USE THE PROGRAM:

enter 0 for expression to k-map operation, or enter 1 for k-map to expression.
then enter no. of variables.

for expression to k-map operation:
enter expression string in capital letters only without space in between. for complement use apostrophe(').
for example-
A'C'+B'CD

this will give output as-
1 1 1 0
1 1 0 0
0 0 0 0
0 0 1 0

for k-map to expression operation:
input k-map directly in matrix format.
for example-
1 1 1 0
1 1 0 0
0 0 0 0
0 0 1 0

this will give output as- 
A'C'+B'CD

