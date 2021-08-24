#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;
#include <fstream>
#include <regex>
#include <string>
#include <dirent.h>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "linux_parser.h"
#include "format.h"

// TODO: Return this process's ID
int Process::Pid() { return getppid(); }


float Process::CpuUtilization() const {
  string os, kernel, version;
  string line;
  string pid = std::to_string(getppid());
  string value, value2, value3, value4, value5, value6, value7, value8, value9,
  value10, value11, value12, value13, value14, value15, value16, value17, value18, value19, value20, value21, value22;
  long int utime, stime, cutime, cstime, starttime;
  std::ifstream stream(LinuxParser::kProcDirectory + pid +
  LinuxParser::kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    //linestream >> os >> version >> kernel;
    linestream >> value >> value2 >> value3 >> value4 >>
                 value5 >> value6 >> value7 >> value8 >> value9 >>
                    value10 >> value11 >> value12 >> value13 >> value14 >> value15 >> value16 >> value17 >> value18 >> value19 >> value20 >> value21 >> value22;

  } //
  std::cout << "\n utime 14 = \n" << value14;
  long int value14_ = std::stol(value14);
  std::cout << "\n utime AFTER COVERSION 14 = \n" << value14_;
  utime = value14_;
  std::cout << "\n stime 15 = \n " << value15;
  long int value15_ = std::stol(value15);
  stime = value15_;
  std::cout << "\n cutime 16 = \n " << value16;
  long int value16_ = std::stol(value16);
  cutime = value16_;
  std::cout << "\n cstime 17 = \n " << value17;
  long int value17_ = std::stol(value17);
  cstime = value17_;
  std::cout << "\n sstarttime 22 = \n " << value22;
  long int value22_ = std::stol(value22);
  starttime = value22_;

  long int UpTimeofSystem = LinuxParser::UpTime();
  std::cout << "\n HERTZ \n" << sysconf(_SC_CLK_TCK);
 //
  long int total_time;
  total_time = utime + stime;
  total_time = total_time + cutime + cstime;
  long int seconds;
  seconds = UpTimeofSystem - (starttime / sysconf(_SC_CLK_TCK));
  long int cpu_usage;
  cpu_usage = 100 * ((total_time / sysconf(_SC_CLK_TCK)) / seconds);
  /*long int value22_ = std::stol(value22);
  //long int starttime = std::stol(value22);
  long int starttime_ = value22_ / sysconf(_SC_CLK_TCK);*/


  // std::cout << "\n CPU USAGE in process.cpp \n" << cpu_usage;
  return cpu_usage;
                }

// TODO: Return this process's CPU utilization
/*float Process::CpuUtilization2() {
    string line;
    string key;
    string pid = std::to_string(getppid());
    *//*float user, nice, system, idle, iowait, irq, softirq, steal, guest,
        guest_nice;*//*
    float value, value2, value3, value4, value5, value6, value7, value8, value9,
        value10, value11, value12, value13, value14;
    // float MemTotal, MemFree, MemAvailable, Buffers;
    // float Utilization;

    std::ifstream filestream(LinuxParser::kProcDirectory + pid +
                             LinuxParser::kStatFilename);
    if (filestream.is_open()) {
      while (std::getline(filestream, line)) {
        std::istringstream linestream(line);
        std::cout << "\n line \n" << line;
        //std::cout << "\n line \n" << line[2];
        //  >> value2 >> value3 >> value4 >>
        //                value5 >> value6 >> value7 >> value8 >> value9 >>
        //                value10 >> value11 >> value12 >> value13 >> value14)
        while (linestream >> key >> value )  {
         // if (key == "cpu") {
            std::cout << "\n 14th KEY \n" << value;
            //std::cout << "\n 12th value \n" << value;
            //std::cout << "\n 14th value \n" << value14;

            //break;

            //user = value;
            *//*std::cout << "\n CPU USER \n" << user;
            std::cout << "\n CPU VALUE 2 \n" << value2;
            nice = value2;
            // nice = std::stof(value2);
            std::cout << "\n CPU VALUE 3 \n" << value3;
            system = value3;
            std::cout << "\n CPU VALUE 4 \n" << value4;
            idle = value4;
            std::cout << "\n CPU VALUE 5 \n" << value5;
            iowait = value5;
            std::cout << "\n CPU VALUE 6 \n" << value6;
            irq = value6;
            std::cout << "\n CPU VALUE 7 \n" << value7;
            softirq = value7;
            std::cout << "\n CPU VALUE 8 \n" << value8;*//*

        }
      }
    }
  }*/

// TODO: Return the command that generated this process // changed to int pid instead of 0 args
string Process::Command() {
                  string line;
                  string key;
                  //int value;
                  //string pid_ = std::to_string(pid);
                  string pid_ = std::to_string(getppid());
                  //string pid = std::to_string(getppid());
                  // float MemTotal, MemFree, MemAvailable, Buffers;
                  // float Utilization;
                  std::ifstream filestream(LinuxParser::kProcDirectory + pid_ +
                                           LinuxParser::kCmdlineFilename);
                  // std::ifstream filestream("/proc/" + getppid() + "/status");
                  if (filestream.is_open()) {
                    while (std::getline(filestream, line)) {
                      std::istringstream linestream(line);
                      std::cout << "\n line \n" << line;

                      /* while (linestream >> key >> value) {
                         //if (key == "VmSize:") {
                         std::cout << "\n cmdine key = \n" << key;
                           std::cout << "\n cmdine value = \n" << value;
                           //value = std::stoi(value);
                         }*/
                    }
                  }
                  return line;
                }



// TODO: Return this process's memory utilization
string Process::Ram() {
  string line;
  string key;
  int value;
  string pid_ = std::to_string(getppid());
  // float MemTotal, MemFree, MemAvailable, Buffers;
  // float Utilization;
  std::ifstream filestream(LinuxParser::kProcDirectory + pid_ + LinuxParser::kStatusFilename);
  //std::ifstream filestream("/proc/" + getppid() + "/status");
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "VmSize:") {
          std::cout << "\n Vm Size = \n" << value;
          //value = std::stoi(value);
        }
      }
    }
  }
  return std::to_string(value);
}

  //return string(); }

// TODO: Return the user (name) that generated this process
string Process::UserHelper() {
  //int LinuxParser::TotalProcesses(std::string procs, std::string filename_path, std::string filename_path_) {
    string line;
    string key;
    int value;
    string pid_ = std::to_string(getppid());
    // float MemTotal, MemFree, MemAvailable, Buffers;
    // float Utilization;
    std::ifstream filestream(LinuxParser::kProcDirectory + pid_ + LinuxParser::kStatusFilename);
    //std::ifstream filestream("/proc/" + getppid() + "/status");
    if (filestream.is_open()) {
      while (std::getline(filestream, line)) {
        std::istringstream linestream(line);
        while (linestream >> key >> value) {
          if (key == "Uid:") {
            std::cout << "\n Uid value = \n" << value;
            return std::to_string(value);
            //value = std::stoi(value);
          }
        }
      }
    }
    return std::to_string(value);
  }

  // TODO: Return the user (name) that generated this process
  string Process::User() {
  //int LinuxParser::TotalProcesses(std::string procs, std::string filename_path, std::string filename_path_) {
  string line;
  string key;
  string uid = Process::UserHelper();
  //std::cout << "\n uid in User() = \n" << uid;
  string user;
  //int value;
  //std::map<std::string, int> m;

  //string pid = std::to_string(getppid());
  // float MemTotal, MemFree, MemAvailable, Buffers;
  // float Utilization;
  std::ifstream filestream(LinuxParser::kPasswordPath);
  //std::ifstream filestream("/proc/" + getppid() + "/status");
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      //std::replace(line.begin(), line.end(), ':', '\n');

     /* m[line] = 1000;
      if (m.find("1000") != m.end())
        std::cout << "map contains key world!\n";
      std::map<std::string, int>::iterator i = m.find(line);
      std::cout << "Key: " << i->first << " Value: " << i->second << '\n';
      if (i->first == "1000") {std::cout << "CHINA";}*/

     //:x:1000:1000:cam,,,:/home/cro0sh:/bin/bash
     //std::string delimiter = ":x:1000:1000:"; // USE UID!!!!
     std::string delimiter = ":x:" + uid + ":" + uid + ":";
     std::cout << "\n testing delimiter = \n" << delimiter;
     std::string user = line.substr(0, line.find(delimiter));
     if (user.length() < 30) {
       std::cout << "\n key value = \n" << user;
       return user;
     }
     //if (token.length() > 1) { break; }
      //v.push_back(line);
      //if (v == 1000)

      /*for (string c: line) {
        std::cout << "\n something \n" << c;
      }*/
      //if (line == "1000") { std::cout << "\n key value\n" << line; }
      //std::cout << "\n key value\n" << line;

      //std::cout << "\n key value\n" << line;
      /*for (int c: line) {
        std::cout << c << "\nYES\n";
      }*/
      //if (line == "cro0sh:x:1000:1000:cam,,,:/home/cro0sh:/bin/bash") { std::cout << line << "\nYES\n"; }
      /*while (linestream >> key >> value) {
        //std::cout << "\n key value\n" << linestream;
        std::cout << "\n key value\n" << key;
        std::cout << "\n Uid value\n" << value;
        *//*if (key == "cro0sh:x") {
          std::cout << "\n key value\n" << key;
          std::cout << "\n Uid value\n" << value;
          //value = std::stoi(value);
        }*//*
      }*/
    }
  }
  return user;
  /*for (string s : v) {
    std::cout << "from vector " << s;
    if (s == "1000") {std::cout << "CHINA" << s;}
  }*/
  //return user;
}




  //return string(); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() {
  string os, kernel, version;
  string line;
  string pid = std::to_string(getppid());
  string value, value2, value3, value4, value5, value6, value7, value8, value9,
  value10, value11, value12, value13, value14, value15, value16, value17, value18, value19, value20, value21, value22;
  std::ifstream stream(LinuxParser::kProcDirectory + pid +
  LinuxParser::kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    //linestream >> os >> version >> kernel;
    linestream >> value >> value2 >> value3 >> value4 >>
    value5 >> value6 >> value7 >> value8 >> value9 >>
    value10 >> value11 >> value12 >> value13 >> value14 >> value15 >> value16 >> value17 >> value18 >> value19 >> value20 >> value21 >> value22;

  } //
  std::cout << "\n value 2 = \n" << value2;
  std::cout << "\n utime 14 = \n" << value14;
  std::cout << "\n stime 15 = \n " << value15;
  std::cout << "\n cutime 16 = \n " << value16;
  std::cout << "\n cstime 17 = \n " << value17;

  long int value22_ = std::stol(value22);
  //long int starttime = std::stol(value22);
  long int starttime_ = value22_ / sysconf(_SC_CLK_TCK);
  std::cout << "\n value 22 = \n " << value22;
  std::cout << "\n sstarttime_ 22 = \n " << starttime_;
  Format::ElapsedTime(starttime_);

  return starttime_;

}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
  //Process proc;
  //std::cout << "Overload " << (proc.CpuUtilization() < a.CpuUtilization());
  //return (proc.CpuUtilization() < a.CpuUtilization());
  return (this->CpuUtilization() < a.CpuUtilization());
   }