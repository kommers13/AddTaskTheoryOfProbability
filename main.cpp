#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

long double rand_var(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<long double> dist(0.0, 1.0);
    return dist(gen);
}

int main()
{
    int range = 350;
    vector<long double> vector_var(range);
    vector<long double> vector_var_sum;
    for(int i = 0; i < range; ++i){
        vector_var[i] = rand_var();
    }

    for(auto it_i = vector_var.begin(); it_i < vector_var.end(); ++it_i){
        long double summ = 0.0;
        for(auto it_j = vector_var.begin(); it_j <= it_i; ++it_j){
            summ += *it_j;
        }
        vector_var_sum.push_back(summ);
    }
    ofstream file("data.csv");
    file << "Xi,Si\n";
    for(int i = 0; i < range; ++i){
        file << vector_var[i] << "," << vector_var_sum[i] << '\n';
    }


    return 0;
}
