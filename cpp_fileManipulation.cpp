#include <iostream>
#include <fstream>

//NOTE: Multiple main() functions for the sake of notes and visual changes for learning purposes ONLY.

//OPEN FILE, CREATE FILE IF FILE DOES NOT EXIST [outfile]

int main()
{
	std::ofstream outfile;
		outfile.open("students.dat");
		//RELATIVE PATH VS. ABSOLUTE PATH. 
	return 0;
}

// CLOSE A FILE THAT HAS BEEN CREATED VIA std::ofstream outfile; / outfile.open
int main()
{
	std::ofstream outfile;
	outfile.open("students.dat");
	outfile.close();
}

//HAVE USER INPUT NAME OF THE FILE TO BE OPENED/CREATED

int main()
{
	std::ofstream outfile;
	char filename[80];
	//INITIALIZED VIA CHAR 
	std::cout << "Enter name of file: ";
	std::cin >> filename; 
	outfile.open(filename);
	return 0;
}

//OPENING APPENDING RATHER THAN OVERWRITING [outfile]
 
int main()
{
	std::ofstream outfile;
		outfile.open ("students.dat", std::ios::app);
		//"std::ios::app" appending a file, for example an error log. 
	return 0;
}


//UPDATING FILE VIA INPUT AND OUTPUTTING THE RESULT

int main()
{
	char data[80];
	std::ofstream outfile;
	outfile.open("students.dat", std::ios::app),
	std::cout << "Enter Data: ";
	std::cin.getline(data, 80);
	//"std::cin.getline ()" getline ensure that whitespace is included. 
	//std::cin >> data, 80; 
	outfile << data << std::endl;
	outfile.close();
	return 0;
}

// READING A FILE

int main()
{
	std::ifstream infile;
	infile.open("students.dat");
	return 0;
}



int main()
{
	std::ifstream infile;
	infile.open("testfile.dat");
	if (infile.fail() == true)
	//"If file does not exist then:
		std::cout << "File canot be opened for reading\n";
	else
	{
		infile.close();
		//close normally.
	}
	return 0;
}

//OFSTREAM + FSTREAM. Specifically user input of two data sets at a time, also result of user input outputted and added onto file. 

int main()
{
	char data[80];
	std::ofstream outfile;
	outfile.open("students.dat");
	std::cout << "Enter data: ";
	std::cin.getline(data, 80);
	outfile << data << std::endl;
	std::cout << "Enter more data: ";
	std::cin.getline(data, 80);
	outfile << data << std::endl;
	outfile.close();
	std::fstream infile;
	infile.open("students.dat");
	if (infile.fail() == true)
		std::cout << "File canot be opened for reading\n";
	else
	{
		infile.getline(data, 80);
		std::cout << data << std::endl;
		infile.getline(data, 80);
		std::cout << data << std::endl;
		infile.close();
	}
	return 0;
}

// IF WE DO NOT KNOW HOW MANY PIECES OF DATA TO READ [while]

int main()
{
	char data[80];
	std::ofstream outfile;
	outfile.open("students.dat");
	std::cout << "Enter data: ";
	std::cin.getline(data, 80);
	outfile << data << std::endl;
	std::cout << "Enter more data: ";
	std::cin.getline(data, 80);
	outfile << data << std::endl;
	outfile.close();
	std::fstream infile;
	infile.open("students.dat");
	if (infile.fail() == true)
		std::cout << "File cannot be opened for reading.\n";
	else
	{
		while ((infile.fail() == false))
		{
			infile.getline(data, 80);
			std::cout << data << std::endl;
		}
		infile.close();
	}
	return 0;
}

//Implementing different functions and a loop for file input + output 

#include <iostream>
#include <fstream>

void writeFile(std::ofstream&, const char*);
void readFile(std::ifstream&, const char*);

int main()
{
	std::ofstream outfile;
	std::ifstream infile;
	writeFile(outfile, "students.dat");
	readFile(infile, "students.dat");
	return 0;
}
void writeFile(std::ofstream& file, const char* strFile)
{
	char data[80];
	file.open(strFile);
	while ((file.fail() == false))
	{
		std::cout << "Enter data, or press ENTER to quit: ";
		std::cin.getline(data, 80);
		std::cout << data << std::endl;
	}
	file.close();
}

//REPLACED
//	file << data << std::endl;
//	std::cout << "Enter more data: ";
//	std::cin.getline(data, 80);
//	file << data << std::endl;
//	file.close();
//}
void readFile(std::ifstream& file, const char* strFile)
{
	if (file.fail() == true)
		std::cout << "File can't be opened for reading\n";
	else
	{
		char data[80];
		file.open(strFile);
		while ((file.fail() == false))
		{ 
			file.getline(data, 80);
			std::cout << data << std::endl;
		}
		file.close();
	}
}

