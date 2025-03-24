#include "evaluator.hpp"

int main() {
    Evaluator evaluator;
    evaluator.ingest("evaluation_cases.txt");

    // Run the sorting comparisons 10 times
    evaluator.run_multiple_times(2);

    // Evaluate and print the results
    evaluator.evaluate();

    return 0;
}