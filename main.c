#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
			NumAlt += primeira_heuristica;
		}

		if (examT) {
			examT = 0;
		}
		else if (NumAlt == 0) {
			examT = 1;
		}
	}
}
