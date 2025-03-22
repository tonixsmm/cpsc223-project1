#include "evaluator.hpp"

int main() {
    Evaluator evaluator;
    evaluator.ingest("evaluation_cases.txt");

    evaluator.merge_comparison();
    evaluator.quick_comparison();
    evaluator.insertion_comparison();

    evaluator.evaluate();
    return 0;
}