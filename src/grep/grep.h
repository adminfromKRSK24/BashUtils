#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <stdio.h>

typedef struct all_flags {
    int fl_e;
    int fl_i;
    int fl_v;
    int fl_c;
    int fl_l;
    int fl_n;
    int fl_h;
    int fl_s;
    int fl_f;
    int fl_o;
    char *pattern;
} flags;

flags Get_Flags(int argc, char *const argv[], flags myflags);
void Get_pattern_E(int argc, char *argv[]);  // доделать E если несколько флагов
void Get_pattern_I(int argc, char *argv[], flags myflags);
void Get_pattern_V(int argc, char *argv[], flags myflags);
void Get_pattern_C(int argc, char *argv[], flags myflags);
void Get_pattern_L(int argc, char *argv[], flags myflags);
void Get_pattern_N(int argc, char *argv[], flags myflags);
void Get_pattern_H(int argc, char *argv[], flags myflags);
void Get_pattern_S(int argc, char *argv[]);
void Get_pattern_F(int argc, char *argv[]);
void Get_pattern_O(int argc, char *argv[]);

#endif  // SRC_GREP_S21_GREP_H_
