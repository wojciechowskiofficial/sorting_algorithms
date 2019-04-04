void bubble_sort(int * t, int s) {
	for (int i = 0; i < s; i++) {
		for (int j = i; j < s - i - 1; j++) {
			if (t[j] > t[j + 1]) std::swap(t[j], t[j + 1]);
		}
	}
}
