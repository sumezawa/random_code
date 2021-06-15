#include <ctime> // measure run time
#include <fstream> // read array file
#include <iomanip> // setw()
#include <iostream> // user input/output
#include <sstream> // stream array file contents
#include <string> // string to integer
#include <vector> // array
#include <utility> // pair<double,double>

/* Given an int array, and int parameter k,
 * returns maximum sum for k consecutive elements */
class ksum {
    public:
        // Brute Force: check all subarrays, every time (O(n^2))
        int brute_ksum(const std::vector<int>& arr, const int& k) {
            int max_sum = 0;
            int current_sum = 0;

            for (size_t i = 0; i < arr.size() - k + 1; ++i) {
                current_sum = 0;
                for (size_t j = 0; j < k; ++j) {
                    current_sum += arr[i + j];
                }

                max_sum = kmax(current_sum, max_sum);
            }

            return max_sum;
        }

        // Sliding Window: conserve partial sums from past iterations (O(n))
        int window_ksum(const std::vector<int>& arr, const int& k) {
            int max_sum = 0;
            int current_sum = 0;

            for (size_t i = 0; i < k; ++i) {
                current_sum += arr[i];
            }

            for (size_t i = k; i < arr.size(); ++i) {
                current_sum += arr[i] - arr[i - k];
                max_sum = kmax(current_sum, max_sum);
            }

            return max_sum;
        }

    private:

        int kmax(int current_sum, int max_sum) {
            if (current_sum > max_sum) {
                return current_sum;
            }
            else {
                return max_sum;
            }
        }
};

int main() {
    
    // make array
    std::vector<int> arr;

    std::ifstream infile("array.txt");
    std::string line;
    while (std::getline(infile, line)) { // check each line in file
        std::istringstream input(line);
        std::string num;
        while (getline(input, num, ',')) { // check each string in line
            arr.push_back(std::stoi(num));
        }
    }

    infile.close();
    infile.clear();

    // get k
    int k = 0;
    std::cout << "Array: {";
    for (auto& i : arr) {
        std::cout << i << " ";
    }
    std::cout << "}\n";

    while (true) {
        std::cout << "Enter K: ";
        std::cin >> k;
        std::cout << "\n";


        // compute ksums, and measure time elapsed
        ksum K; 
        clock_t time;
        time = std::clock();
        std::cout << "Brute " << k << "-Sum: " << K.brute_ksum(arr, k) << "\n";
        time = std::clock() - time;
        std::pair<double, double> times{(double)time, 0};

        time = std::clock();
        std::cout << "Window " << k << "-Sum: " << K.window_ksum(arr, k) << "\n";
        time = std::clock() - time;
        times.second = (double)time;

        // Print Trials
        std::cout.precision(3);

        if ((times.first * 1000 / CLOCKS_PER_SEC) < 1) {
            std::cout << "Brute Force Time: " << std::setw(4) << 
                times.first * 1000000 / CLOCKS_PER_SEC << " us\n";
        }
        else {
            std::cout << "Brute Force Time: " << std::setw(4) << 
                times.first * 1000 / CLOCKS_PER_SEC << " ms\n";
        }

        if ((times.second * 1000 / CLOCKS_PER_SEC) < 1) {
            std::cout << "Sliding Window Time: " << std::setw(4) << 
                times.second * 1000000 / CLOCKS_PER_SEC << " us\n";
        }
        else {
            std::cout << "Sliding Window Time: " << std::setw(4) << 
                times.second * 1000 / CLOCKS_PER_SEC << " ms\n";
        }
    }

    return 0;
}
