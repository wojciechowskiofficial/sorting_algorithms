#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <map>

#include "arr_gen.h"
#include "logs.h"

#include "heap_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "counting_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"

/*
arr_gen:
	void gen_random(int * t, int s)			: random arr
	void gen_constant(int * t, int s) 		: constant arr
	void gen_constantly_increasing(int * t, int s)	: constantly increasing arr
	void gen_constantly_decreasing(int * t, int s)	: constantly decreasing arr
	void gen_increasing_decreasing(int * t, int s)	: starting with number of value 9s then increasing and decreasing by 2
	void gen_decreasing_increasing(int * t, int s)	: starting with number of value 10s then decreasing and increasing by 2

logs.h:
	double simple_log(void(* sort)(int *, int), int * t, int s)		: takes sorting function, array and size as
       									          input returnes time of sorting
										  with double precision
	double complex_log(void(* sort)(int *, int, int), int left, int right)	: takes sorting function, array, left
										  and right returns time of sorting with
										  double precision

heap_sort.h:
	void heapify(int * t, int s, int i)			: fixes heap of size s from ith element downwards
	void max_heap(int * t, int s)				: builds max heap of size s
	void heap_sort(int * t, int s)				: performs heap sort on arr of size s

bubble_sort.h:
	void bubble_sort(int * t, int s)			: performs bubble sort on arr of size s

insertion_sort.h:
	void insertion_sort(int * t, int s)			: performs insertion sort on arr of size s

selection_sort.h:
	void selection_sort(int * t, int s)			: performs selection sort on arr of size s

counting_sort.h:
	int find_max(int * t, int s)				: returns maximal element from array
	void counting_sort(int * t, int s)			: performs counting sort on arr of size s

shell_sort.h:
	void shell_sort(int * t, int s)				: performs shell sort on arr of size s

quick_sort.h:
	void quick_sort(int * t, int left, int right, int * m)	: performs quick sort on array from lefth element to right element

merge_sort.h:
	void merge_sort(int * t, int left, int right, int * m)	: performs merge sort on array form lefth element to right element
	void arr_merge(int * t, int left, int mid, int right)	: merges 


main argument vector	: [sort type, array type, starting number of elements, incrementation value, number of meausers]
example			: [bubble_sort, gen_increasing_decreasing, 10000, 5, 20]

*/

double log(std::string sort_name, int * t, int s) {
	std::map <std::string, char> sort_map;
	sort_map["bubble_sort"] = 0;
	sort_map["insertion_sort"] = 1;
	sort_map["selection_sort"] =  2;
	sort_map["shell_sort"] = 3;
	sort_map["counting_sort"] = 4;
	sort_map["heap_sort"] = 5;
	sort_map["quick_sort"] = 6;
	sort_map["merge_sort"] = 7;

	typedef void (* simple_f_p)(int * t, int s);
	typedef void (* complex_f_p)(int * t, int left, int right, int * m);

	simple_f_p sort_arr_simple[6];
	sort_arr_simple[0] = &bubble_sort;
	sort_arr_simple[1] = &insertion_sort;
	sort_arr_simple[2] = &selection_sort;
	sort_arr_simple[3] = &shell_sort;
	sort_arr_simple[4] = &counting_sort;
	sort_arr_simple[5] = &heap_sort;

	complex_f_p sort_arr_complex[2];
	sort_arr_complex[0] = &quick_sort;
	sort_arr_complex[1] = &merge_sort;

	switch (sort_map[sort_name]) {
		case 0 : 
			return simple_log(sort_arr_simple[sort_map[sort_name]], t, s);
			break;
		case 1 : 
			return simple_log(sort_arr_simple[sort_map[sort_name]], t, s);
			break;
		case 2 : 
			return simple_log(sort_arr_simple[sort_map[sort_name]], t, s);
			break;
		case 3 : 
			return simple_log(sort_arr_simple[sort_map[sort_name]], t, s);
			break;
		case 4 : 
			return simple_log(sort_arr_simple[sort_map[sort_name]], t, s);
			break;
		case 5 : 
			return simple_log(sort_arr_simple[sort_map[sort_name]], t, s);
			break;
		case 6 : 
			return complex_log(sort_arr_complex[sort_map[sort_name] - 6], t, 0, s - 1);
			break;
			
		case 7 : 
			int * m;
			m = new int [s];

			return complex_log(sort_arr_complex[sort_map[sort_name] - 6], t, 0, s - 1, m);

			delete [] m;
			m = NULL;

			break;
	}
}

int main(int argc, char ** argv) {
	if (argc != 6) return 0;
	std::string arg[5];
	for (int i = 0; i < 2; i++) arg[i] = argv[i + 1];
	for (int i = 2; i < 5; i++) arg[i] = argv[i + 1];



	int * t;
	int n = stoi(arg[2]), incr = stoi(arg[3]), measures = stoi(arg[4]);
	double out_arr[measures];
	std::string sort_name = arg[0], array_type = arg[1];
	double current_time, elapsed = 0;



	std::cout << "$$$$$$$$$$$$$$$$$$$$$_MAIN_SORTING_PROGRAM_$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl << std::endl;
	std::cout << "sorting algorithm: \t\t" << arg[0] << std::endl;
	std::cout << "array type: \t\t\t" << arg[1] << std::endl;
	std::cout << "starting number of elements: \t" << n << std::endl;
	std::cout << "incrementation value: \t\t" << incr << std::endl;
	std::cout << "number of measures: \t\t" << measures << std::endl << std::endl;



	for (int i = 0; i < measures; i++) {
		t = new int [n];
		gen_arr(array_type, t, n);
		current_time = log(sort_name, t, n);
		elapsed += current_time;
		delete [] t;
		t = NULL;
		out_arr[i] = current_time;
		printf("i: %d \t| n: %d \t| current_time: %.3f \t| elapsed: %.3f \n", i, n, current_time, elapsed);
		n += incr;
	}

	

	std::cout << "save data to txt file? [y/n]" << std::endl;
	if (std::cin.get() == 'n') return 0;

	std::string json_output_name = "json", sql_output_name = "sql";

	for (int i = 0; i < 5; i++) {
		json_output_name += ("@" + arg[i]);
		sql_output_name += (";" + arg[i]);
	}

	std::fstream output_json, output_sql;
	output_json.open(json_output_name + ".txt", std::fstream::out);
	output_sql.open(sql_output_name + ".txt", std::fstream::out);



	n = stoi(arg[2]);
	output_json << json_output_name << std::endl;
	output_json << "{";
	for (int i = 0; i < measures; i++) {
		output_json << n << ":" << out_arr[i];
		n += incr;
		if (i != measures - 1) output_json << ",";
	}
	output_json << "}";




	n = stoi(arg[2]);
	output_sql << sql_output_name << std::endl;
	for (int i = 0; i < measures; i++) {
		output_sql << n << ";" << out_arr[i] << "; \n";
		n += incr;
	}

	std::cout << "successfuly saved" << std::endl;

	output_json.close();
	output_sql.close();
	



	return 0;

}
