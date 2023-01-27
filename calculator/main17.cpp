#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include <cerrno>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Opts {
private:
	std::vector<long> v;
	bool sum = true;
	bool numCorrect = true;
	long res=0;

	void usage(const char* progName);
public:
	Opts(int argc, char **argv);
	long getRes();
};

int main(int argc, char **argv)
{
	Opts op(argc, argv);
	cout << op.getRes() << endl;
	return 0;
}

Opts::Opts(int argc, char **argv)
{
	int opt;
	for (int j = 0; j < argc; j++)
		cout << argv[j] << " | ";
	cout << endl;
	while ((opt = getopt(argc, argv, "v:ash")) != -1) {
		switch (opt) {
		case 'a':
			cout << "add op\n";
			this->sum = true;
			break;
		case 's':
			cout << "sub op\n";
			this->sum = false;
			break;
		case 'v' :
		    for (;;)
		    {
		        errno = 0;
		        char* p_end;
		        const long i = std::strtol(optarg, &p_end, 10);
		        if (optarg == p_end)
		            break;
		 
		        const bool range_error = errno == ERANGE;
		        const std::string extracted(optarg, p_end - optarg);
		        optarg = p_end;
		 
		        this->v.push_back(i);
		        if (range_error)
		            std::cout << " Range error occurred.";
		 
		    }
		    if (this->v.size() < 5 || v.size() > 7){
		    	cerr << "You enter " << v.size() << " operands"<< endl;
		    	cerr << "Number of operands must be in [5..7]" << endl;
		    	this->numCorrect = false;
		    }
		    //std::cout << "  num = "<<v.size() <<" v = { ";

		    // for (long n : v)
		    //     std::cout << n << " ";
		    // std::cout << "}; \n\n";
			break;
		case 'h':
			usage(argv[0]);
			break;
		case ':': // Этот код недостижим по тесту main17.exe -v
			cerr << "empty param value\n";
			break;
		case '?':
			cerr << "unknown param\n";
			break;
		}
	}
	if (this->numCorrect) {
		if (this->sum){
			for (long n : v)
				res += n;
		} else {
			res = v[0];
			long vlength = v.size();
			for (long i = 1; i < vlength ; i++)
				res -= v[i];
		}
	}
}

void Opts::usage(const char * progName){
	cout << "Usage: " << progName << " [-a ] [-s] [-v '5 - 7 operands'] [-h]\n";
	exit(0);
}

long Opts::getRes() {
	if (numCorrect)
		return res;
	else {
		cerr << "Is not correct count of -v param\n\n";
		exit(0);
	}
}