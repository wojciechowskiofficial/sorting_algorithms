double simple_log(void(* sort)(int *, int), int * t, int s) {
	clock_t begin = clock();
	(* sort)(t, s);
	clock_t end = clock();
	return double (end - begin) / CLOCKS_PER_SEC;
}

double complex_log(void(* sort)(int *, int, int, int * m), int * t, int left, int right, int * m = NULL) {
	clock_t begin = clock();
	(* sort)(t,left, right, m);
	clock_t end = clock();
	return double (end - begin) / CLOCKS_PER_SEC;
}
