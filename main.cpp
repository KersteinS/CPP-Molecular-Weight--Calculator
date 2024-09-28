#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <numeric>
#include <periodic_tools.h>

using std::string;
using std::vector;

int parse_input(string *input_ptr, vector<vector<string>> *results_ptr);

int validate_input(vector<string> *entry_ptr);

double calculate_mw(vector<string> *atom_count, periodic_tools::PeriodicTable *periodic_table);

int main()
{
    string x;
    periodic_tools::PeriodicTable table;
    while (true) {
        vector<vector<string>> main_results;
        vector<double> vector_to_sum;
        double total_mw = 0;
        std::cout << "Enter an molecular formula: ";
        std::getline(std::cin, x);
        if (x == "exit") return 0;
        int par_check = parse_input(&x, &main_results);// par_check: 0 is bad element name and bad number; 1 is invalid first character; 2 is bad number only; 3 is bad element name only; 5 is all good
        if (par_check != 0){
            std::cout << "    Invalid format (parse check code=" << par_check << ")" << std::endl;
            continue;
        }
        std::cout << "    ";
        for (vector<string> item: main_results){
            for (string sub_item: item){
                std::cout << sub_item + ", ";
            }
        }
        std::cout << "\b\b " << std::endl;
        for (vector<string> item: main_results){
            double val = calculate_mw(&item, &table);
            vector_to_sum.push_back(val);
        }
        if (std::any_of(vector_to_sum.begin(), vector_to_sum.end(), [](double i){return i==0;})){
            std::cout << "    Invalid formula (not an atom)" << std::endl;
            continue;
        }
        total_mw = std::accumulate(vector_to_sum.begin(), vector_to_sum.end(), 0.0);
        std::cout << "Molecular Weight is " << total_mw << std::endl;

        /*periodic_tools::PeriodicTable::PERIODIC_ELEMENT elem = table.find(x);
        if (elem.atomic_number != 0){
            string element_information = "Element Name: " + elem.atomic_name +
            ", Element Number: " + std::to_string(elem.atomic_number) +
            ", Element Weight: " + std::to_string(elem.atomic_weight) +
            ";";
            std::cout << element_information << std::endl;
        }
        else {
            std::cout << "That is not an atom!" << std::endl;
        }*/
    }
    return 0;
}
int parse_input(string *input_ptr, vector<vector<string>> *results_ptr){
    //results_ptr is the pointer to the top level vector; *results_ptr is the top level vector
    //input_ptr is the pointer to the user_input string; *input_ptr is the user input string "x" in main()
    if (std::isupper((*input_ptr)[0]) < 1) return 1;
    int last_upper_index = 0; // this is the index of the last uppercase letter
    for (int i=1; i < (*input_ptr).length(); i++){
        char subc = (*input_ptr)[i];
        if (std::isupper(subc) > 0){
            string subs = (*input_ptr).substr(last_upper_index,i-last_upper_index);
            (*results_ptr).push_back(vector<string> {subs});
            last_upper_index = i;
        }
    }
    (*results_ptr).push_back(vector<string> {(*input_ptr).substr(last_upper_index,-1)});
    for (int i=0; i < (*results_ptr).size(); i++){
        //std::cout << (*results_ptr)[i].size() << std::endl;
        for (int j = 0; j < (*results_ptr)[i].size(); j++){
            //std::cout << (*results_ptr)[i][j].length() << std::endl;
            for (int k=1; k != (*results_ptr)[i][j].length(); k++){
                char item = (*results_ptr)[i][j][k];
                if (std::isdigit(item)) {
                    (*results_ptr)[i].push_back((*results_ptr)[i][j].substr(k,-1));
                    (*results_ptr)[i][j] = (*results_ptr)[i][j].substr(0,k);
                    int val_check = validate_input(&results_ptr->at(i));
                    if (val_check < 5) return val_check; // check: 0 is bad element name and bad number; 2 is bad number only; 3 is bad element name only; 5 is all good
                }
                //std::cout << (*results_ptr)[i].size() << std::endl;
                if ((*results_ptr)[i].size() > 1) break;
                //std::cout << "looping again" << std::endl;
            }
            if ((*results_ptr)[i].size() == 1) {
                (*results_ptr)[i].push_back("1");
                break;
            }
            else if ((*results_ptr)[i].size() > 1) break;
            //std::cout << "outer looping again" << std::endl;
        }
    }
    return 0;
}

int validate_input(vector<string> *entry_ptr){
    int check1 = 2 * std::all_of(entry_ptr->begin()->begin()+1, entry_ptr->begin()->end(), [](char i) {return std::islower(i);});
    int check2 = 3 * std::all_of((entry_ptr->end()-1)->begin(), (entry_ptr->end()-1)->end(), [](char i) {return std::isdigit(i);});
    // check1 + check2: 0 is bad element name and bad number; 2 is bad number only; 3 is bad element name only; 5 is all good
    return check1 + check2;
}

double calculate_mw(vector<string> *atom_count, periodic_tools::PeriodicTable *periodic_table){
    periodic_tools::PeriodicTable::PERIODIC_ELEMENT elem = periodic_table->find(atom_count->at(0));
    if (elem.atomic_number == 0) return 0;
    std::cout << "    " << elem.atomic_weight << " * " << std::stoi(atom_count->at(1)) << std::endl;
    return elem.atomic_weight * std::stoi(atom_count->at(1));
}
