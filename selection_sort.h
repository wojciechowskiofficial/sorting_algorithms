void selection_sort(int * t, int s) {
	int minimum;
	for (int i = 0; i < s; i++) {
		minimum = i;
		for (int j = i; j < s; j++) if (t[j] < t[minimum]) minimum = j;
		std::swap(t[i], t[minimum]);
	}
}
