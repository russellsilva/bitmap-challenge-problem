#!/bin/bash

# Test the program with a very large input designed to make competitor's programs choke.

date
(seq 4294967295 -2 2147483648 & seq 0 2147483648) | pv | time ./challenge-problem-2
date
