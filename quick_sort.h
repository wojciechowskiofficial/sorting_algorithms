void quick_sort(int * t, int left, int right, int * m = NULL) {
	int i = left, j = right, pivot = t[(left + right) / 2];

	do {
		while (t[i] < pivot) i++;
		while (t[j] > pivot) j--;

		if (i <= j) {
			std::swap(t[i], t[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > left) quick_sort(t, left, j);
	if (i < right) quick_sort(t, i, right);
}
