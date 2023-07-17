#pragma once
#include "assistance.h"

//KMP�㷨��˼�룺����ָ���������ݣ�ģʽ��ָ��ͨ����ȡnext���飬ֻ���ݵ�next�����Ӧ�ĵط�



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
	if (j >= T.size()) //˵��ƥ��ɹ�
		return i - T.size();
	else
		return 0;
}
