void heapify(int * t, int s, int i) {
	int left = 2 * i + 1, right = 2 * i + 2, high = i;
	if (left < s && t[left] > t[high]) high = left;
	if (right < s && t[right] > t[high]) high = right;
	if (i != high) {
		std::swap(t[i], t[high]);
		heapify(t, s, high);
	}
}

void max_heap(int * t, int s) {
	for (int i = s / 2 - 1; i >= 0; i--) heapify(t, s, i);
}

void heap_sort(int * t, int s) {
	max_heap(t, s);
	for (int i = s - 1; i >= 0; i--) {
		std::swap(t[0], t[i]);
		heapify(t, i, 0);
	}
}
