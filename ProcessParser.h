#include <algorithm>
#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>
#include <iterator>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include "constants.h"
#include "util.h"


using namespace std;

class ProcessParser{
private:
    std::ifstream stream;
    public:
    static string getCmd(string pid);
    static vector<string> getPidList();
    static std::string getVmSize(string pid);
    static std::string getCpuPercent(string pid);
    static long int getSysUpTime();
    static std::string getProcUpTime(string pid);
    static string getProcUser(string pid);
    static vector<string> getSysCpuPercent(string coreNumber = "");
    static float getSysRamPercent();
    static string getSysKernelVersion();
    static int getTotalThreads();
    static int getTotalNumberOfProcesses();
    static int getNumberOfRunningProcesses();
    static string getOSName();
    static std::string PrintCpuStats(std::vector<std::string> values1, std::vector<std::string>values2);
    static bool isPidExisting(string pid);
};

// TODO: Define all of the above functions below:
std::string ProcessParser::getVmSize(std::string pid) {
    std::string pathToFile = Path::basePath() + pid + Path::statusPath();
    std::string searchString = "VmData:";
    ifstream stream;
    string line;
    float result;
    Util::getStream(pathToFile,stream);
    while(std::getline(stream, line)) {
        if (line.rfind(searchString,0) == 0) {
            istringstream buf(line);
            istream_iterator<string> beg(buf), end;
            vector<string> values (beg, end);
            result = (stof(values[1]) / float(1024));
            break;
        }
    }
        return to_string(result);


}