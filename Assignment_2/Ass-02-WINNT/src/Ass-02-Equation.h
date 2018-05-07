#ifndef ASS_02_EQUATION_H_
#define ASS_02_EQUATION_H_

#include "Ass-02.h"

typedef struct{
	int size;
	char **input;
	int pos;
}
	str_mem;
	str_mem equation;

typedef struct{
	char *formula;
	int pos;
	double result;
	double prev_ans;
}
	result_mem;
	result_mem output;


extern void Equation_Init(void);
extern int Get_Size(void);
extern char **Get_Input(void);
extern int Get_Pos(void);
extern void Set_Size(int Value);
extern void Set_Input(char **Value);
extern void Set_Pos(int Value);
extern char Get_Formula_c(void);
extern char* Get_Formula(void);
extern double Get_Result(void);
extern double Get_Prev_ans(void);
extern void Set_Formula(char *Value);
extern void Set_Result(double Value);
extern void Set_Prev_ans(double Value);
extern int Increment_Formula(void);



#endif /* ASS_02_EQUATION_H_ */
