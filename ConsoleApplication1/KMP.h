#pragma once
#include "assistance.h"

//KMP算法的思想：主串指针永不回溯，模式串指针通过求取next数组，只回溯到next数组对应的地方



void getNext(string T, int* next) {
    int len = T.length();
    int i = 0, j = -1;
    next[0] = -1;

    while (i < len) {
        if (j == -1 || T[i] == T[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}


int Index_KMP(string S, string T, int next[]) {
	int i = 0, j = 0;
	while (i < S.size() && j < T.size()) {
		if (j == -1 || S[i] == T[i]) {
			++i; ++j;
		}
		else
			j = next[j];
	}
	if (j >= T.size()) //说明匹配成功
		return i - T.size();
	else
		return 0;
}
