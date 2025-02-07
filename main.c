#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct AlgoritmoSmo 
{
	long double** X;
	long double* y;
	long double* lagrange;
	long double* kernel;
	long double* erro;
	long double* w;
	long double tol;
	long double bias;
	long double C;
	long double eps;
	int dim1, dim2;
	int otim_lin;
}AlgoritmoSmo;

int Primeira_Heuristica(AlgoritmoSmo *smo)
{
	int NumAlt = 0;
	int indnlim = getindnlim(smo);

	for (int i = 0; i < indnlim; i++) {
		NumAlt += examine_exemplo(smo, i);
	}
	return NumAlt;
}

void main_routine(AlgoritmoSmo *smo)
{
	int NumAlt=0, examT=1;

	while (NumAlt > 0 || examT) {
		NumAlt = 0;

		if (examT) {
			for (int i = 0; i < smo->m; i++) {
				NumAlt += examine_exemplo(smo, i);
			}
		}
		else {
			NumAlt += Primeira_Heuristica(smo);
		}

		if (examT) {
			examT = 0;
		}
		else if (NumAlt == 0) {
			examT = 1;
		}
	}
}
