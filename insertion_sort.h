void insertion_sort(int * t, int s) {
	int j, tmp;
	for (int i = 1; i < s; i++) {
		tmp = t[i];
		j = i - 1;

		while (j >= 0 && t[j] > tmp) {
			t[j + 1] = t[j];
			j--;
		}

		t[j + 1] = tmp;
	}
}
