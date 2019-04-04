void counting_sort(int * t, int s) {
	int max = t[0];
	for (int i = 1; i < s; i++) if (t[i] > max) max = t[i];

	int * c;
	c = new int [max + 1];

	for (int i = 0; i <= max; i++) c[i] = 0;
	for (int i = 1; i < s; i++) c[t[i]]++;
	for (int i = 1; i <= max; i++) c[i] += c[i - 1];
	int * o;
	o = new int [s];
	for (int i = s - 1; i >= 1; i--) {
		o[c[t[i]]] = t[i];
		c[t[i]]--;
	}

	for (int i = 0; i < s; i++) t[i] = o[i];

	delete [] c;
	c = NULL;
	delete [] o;
	o = NULL;

}
