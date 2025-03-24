#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include <vector>
#include <string>

class Evaluator {
public:
    void ingest(const std::string& filename);
    void merge_comparison();
    void quick_comparison();
    void insertion_comparison();
    void evaluate();
    void run_multiple_times(int runs);


    const std::vector<std::vector<int> >& get_cases() const { return cases; }
    const std::vector<double>& get_merge_times() const { return merge_times; }
    const std::vector<double>& get_quick_times() const { return quick_times; }
    const std::vector<double>& get_insertion_times() const { return insertion_times; }

private:
    std::vector<std::vector<int> > cases;
    std::vector<double> merge_times;
    std::vector<double> quick_times;
    std::vector<double> insertion_times;
    
    std::vector<std::vector<double>> merge_times_runs;
    std::vector<std::vector<double>> quick_times_runs;
    std::vector<std::vector<double>> insertion_times_runs;

    void printSortResults(const std::string& sortName, const std::vector<std::vector<double>>& runs, std::ofstream& csvFileName);
};

#endif