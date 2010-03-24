#ifndef QLEARNING_H
#define QLEARNING_H

#pragma udata DATA
int large_table[768];

#pragma udata
int *table_ptr = &large_table[0];

struct qtnode{
	int state;
	int action;
	int reward;
};
//typedef struct qtnode** qtable;

void initializeQLearning(void);
void addNode(char s, char a, char r);
void getTable(void);
void getAction(char s);
#endif