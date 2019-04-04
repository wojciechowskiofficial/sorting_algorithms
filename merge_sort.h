void merge(int * t, int left, int mid, int right, int * m) {
	for (int i = left; i <= right; i++) m[i] = t[i];

	int left_p = left, right_p = mid + 1, current = left;

	while (left_p <= mid && right_p <= right) {
		if (m[left_p] < m[right_p]) t[current++] = m[left_p++];
		else t[current++] = m[right_p++];
	}

	while (left_p <= mid) t[current++] = m[left_p++];
}

void merge_sort(int * t, int left, int right, int * m) {
	int mid = (left + right) / 2;

	if (left < right) {
		merge_sort(t, left, mid, m);
		merge_sort(t, mid + 1, right, m);
		merge(t, left, mid, right, m);
	}
}
