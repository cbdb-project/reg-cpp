#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <chrono>
#include <ctime>
#include <algorithm>

using namespace std;

std::vector<std::string> split(const string& input, const string& regex) {
    std::regex re(regex);
    std::sregex_token_iterator
        first{input.begin(), input.end(), re, -1},
        last;
    return {first, last};
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
	std::time_t start_time = std::chrono::system_clock::to_time_t(start);
	cout << "start at " << std::ctime(&start_time) << endl;
	ifstream ifs_reg("reg.txt");
	string reg_content( (std::istreambuf_iterator<char>(ifs_reg) ),
					(std::istreambuf_iterator<char>()  ) );
	string split_loc = "＾";
	vector<string> reg_vector = split(reg_content, split_loc);
	string reg_find = reg_vector[0];
	string reg_new = reg_vector[1];
	cout << "reg_find: " << reg_find << endl;
	cout << "reg_new: " << reg_new << endl;
	reg_new = ReplaceAll(reg_new, "\\n", "\n");
	reg_new = ReplaceAll(reg_new, "\\r", "\r");
	reg_new = ReplaceAll(reg_new, "\\t", "\t");
	ifstream ifs("data.txt");
	string content( (std::istreambuf_iterator<char>(ifs) ),
					(std::istreambuf_iterator<char>()  ) );
	ifs.close();
	cout << "loading finish..." << endl;
	regex reg(reg_find);
	int count = 0;
	while(regex_search(content, reg)==1){
		count++;
		content = regex_replace(content, reg, reg_new);	
	}
	cout << "replacement finish..." << endl;
	ofstream fout("data_out.txt");
	fout << content;
	fout.close();
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\ndone\n";
	return 0;
}
