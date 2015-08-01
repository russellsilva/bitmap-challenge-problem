#!/bin/bash

# Test the program with a very large input designed to make competitors' programs choke.

date
(gseq 4294967295 -2 2147483648; gseq 0 2147483648) | pv | time ./challenge-problem-2
date
