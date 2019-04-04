void shell_sort(int * t, int s) {
	for (int gap = s / 2; gap >= 1; gap /= 2) {
		for (int i = gap; i < s; i++) {
			int tmp = t[i], j;
			for (j = i; j >= gap; j -= gap) {
				if (t[j - gap] > tmp) t[j] = t[j - gap];
				else break;
			}
			t[j] = tmp;
		}
	}
}
