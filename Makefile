vector_sort: vector_compile vector_run vector_clean

vector_compile:
	@g++ -std=c++11 main.cpp vector_sorter.cpp -o sorter

vector_run:
	@./sorter

vector_clean:
	@rm -f sorter

test_vector: test_vector_compile test_vector_run test_vector_clean

test_vector_compile:
	@g++ -std=c++11 test_vector_sorting.cpp vector_sorter.cpp -o tests

test_vector_run:
	@./tests

test_vector_clean:
	@rm -f tests

evaluate: evaluate_compile evaluate_run evaluate_clean

evaluate_compile:
	@g++ -std=c++11 main.cpp evaluator.cpp vector_sorter.cpp doubly_linked_list.cpp -o evaluate

evaluate_run:
	@./evaluate

evaluate_clean:
	@rm -f evaluate
