@echo off
cls
make clean

make

KrustyKrab < TEST_CASE.txt > RESULT.txt