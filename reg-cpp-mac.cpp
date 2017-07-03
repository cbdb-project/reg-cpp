#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <chrono>
#include <ctime>
#include <boost/algorithm/string.hpp>
#include <sstream>
// for mac
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>


using namespace std;


std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
	size_t start_pos = 0;
	while((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
	return str;
}

// for mac
int getFiles (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
    	if(strcmp(dirp->d_name,".") != 0  &&  strcmp(dirp->d_name,"..") != 0)
    	{
        	files.push_back(dir+"/"+string(dirp->d_name));
        }
    }
    closedir(dp);
    return 0;
}


int main()
{
	string file_path = "input";
	string out_path = "output";
	vector<string> files; 
	getFiles(file_path, files); 
	for (int i = 0; i < files.size(); i++) 
	{ 
		string current_file = files[i];
		cout<<"working on "<<current_file<<endl;
		std::chrono::time_point<std::chrono::system_clock> start, end;
		start = std::chrono::system_clock::now();
		std::time_t start_time = std::chrono::system_clock::to_time_t(start);
		cout << "start at " << std::ctime(&start_time);

		std::ifstream ifs(current_file);
		string content( (std::istreambuf_iterator<char>(ifs) ),
						(std::istreambuf_iterator<char>()  ) );
		ifs.close();
		cout << "loading finish..." << endl;

		std::ifstream ifs_reg("reg.txt");
		string reg_content( (std::istreambuf_iterator<char>(ifs_reg) ),
						(std::istreambuf_iterator<char>()  ) );
		string split_loc = "\t";

		std::vector<string> reg_lines;
		std::vector<string> reg_vector;
		boost::split(reg_lines, reg_content, boost::is_any_of("\n"));
		string reg_line, reg_find, reg_new;
		for (int i = 0; i < reg_lines.size(); ++i)
		{
			reg_line = reg_lines[i];
			boost::split(reg_vector, reg_line, boost::is_any_of(split_loc));
			reg_find  = reg_vector[0];
			reg_new  = reg_vector[1];
			cout << endl << "reg_find: " << reg_find << endl;
			cout << "reg_new: " << reg_new << endl << endl;
			reg_new = ReplaceAll(reg_new, "\\n", "\n");
			reg_new = ReplaceAll(reg_new, "\\r", "\r");
			reg_new = ReplaceAll(reg_new, "\\t", "\t");
			std::regex reg(reg_find);
			while(std::regex_search(content, reg)==1){
				content = std::regex_replace(content, reg, reg_new);
			}
		}

		cout << "replacement finish..." << endl;
		cout << "current_file:" << current_file << endl;
		cout << "saving to " << out_path << "/" << current_file.substr(6) << endl;
		std::ofstream fout(out_path + "/" + current_file.substr(6));
		fout << content;
		fout.close();
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end-start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	
		std::cout << "finished at " << std::ctime(&end_time)
				  << "elapsed time: " << elapsed_seconds.count() << "s\ndone\n\n----\n";
	}
	return 0;

}
