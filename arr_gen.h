void gen_random(int * t, int s) {
	srand(time(NULL));
	for (int i = 0; i < s; i++) t[i] = rand() % (10 * s);
}

void gen_constant(int * t, int s) {
	srand(time(NULL));
	int x = rand() % (10 * s);
	for (int i = 0; i < s; i++) t[i] = x;
}

void gen_constantly_increasing(int * t, int s) {
	srand(time(NULL));
	int x = rand() % (9 * s);
	for (int i = 0; i < s; i++) t[i] = x++;
}

void gen_constantly_decreasing(int * t, int s) {
	srand(time(NULL));
	int x = rand() % (9 * s) + s;
	for (int i = 0; i < s; i++) t[i] = x--;
}

void gen_increasing_decreasing(int * t, int s) {
	int x = 9 * s;
	for (int i = 0; i <= s / 2; i++) {t[i] = x; x += 2;}
	x -= 3;
	for (int i = s / 2 + 1; i < s; i++) {t[i] = x; x -= 2;}
}

void gen_decreasing_increasing(int * t, int s) {
	int x = 10 * s;
	for (int i = 0; i <= s / 2; i++) {t[i] = x; x -= 2;}
	x += 3;
	for (int i = s / 2 + 1; i < s; i++) {t[i] = x; x += 2;}
}

void gen_arr(std::string array_type, int * t, int s) {
	std::map <std::string, char> gen_map;
	gen_map["gen_random"] = 0;
	gen_map["gen_constant"] = 1;
	gen_map["gen_constantly_increasing"] = 2;
	gen_map["gen_constantly_decreasing"] = 3;
	gen_map["gen_increasing_decreasing"] = 4;
	gen_map["gen_decreasing_increasing"] = 5;

	typedef void (* gen_p)(int * t, int s);

	gen_p gen_arr[6];

	gen_arr[0] = &gen_random;
	gen_arr[1] = &gen_constant;
	gen_arr[2] = &gen_constantly_increasing;
	gen_arr[3] = &gen_constantly_decreasing;
	gen_arr[4] = &gen_increasing_decreasing;
	gen_arr[5] = &gen_decreasing_increasing;

	gen_arr[gen_map[array_type]](t, s);
}
