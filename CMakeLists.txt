cmake_minimum_required(VERSION 3.15)
project(Project3DS)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project3DS main.cpp Sequence.cpp Sequence.h SequenceD.cpp SequenceD.h Permutation.cpp Permutation.h KeyGen.cpp KeyGen.h Sbox.cpp Sbox.h Utils.cpp Utils.h S_fonction.cpp S_fonction.h F.cpp F.h DES.cpp DES.h Finv.cpp Finv.h DESinv.cpp DESinv.h Crypt.cpp Crypt.h Decrypt.cpp Decrypt.h)