#include "linux_parser.h"

#include <dirent.h>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "process.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;
//using std::cout;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(LinuxParser::kOSPath + "");
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      std::cout << "line = " << line;
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          std::cout << "VALUE IS " << value;
          return value;
        }
      }
    }
  }
  std::cout << "VALUE OUTSIDE " << value;
  return value;
}

//std::string LinuxParser::OperatingSystem(std::string = "PRETTY_NAME");

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, kernel, version;
  string line;
  std::ifstream stream(LinuxParser::kProcDirectory + LinuxParser::kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    //linestream >> os >> version >> kernel;
    linestream >> os >> kernel;

  }
  std::cout << "os " << os;
  std::cout << "KERNEL " << kernel;
  return kernel;
}

/*float LinuxParser::MemoryUtilization() {
  string line;
  std::ifstream stream(kProcDirectory + kMeminfoFilename);
 return 0.0;
}*/

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  for (int x : pids) {
    std::cout << "\n PIDS \n" << x;
  }

  return pids;
}



// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  string line;
  string key;
  string value;
  float MemTotal, MemFree, MemAvailable, Buffers;
  float Utilization;
  std::ifstream filestream(kProcDirectory + kMeminfoFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      //std::cout << "LINE " << line;
      /*if (line == "MemTotal") {
        std::cout << "MemTotal: " << line;
      }*/
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "MemTotal:") {
          //std::cout << "VALUE MemUtil: " << "\n" << value;
          // MemTotal = value;
          MemTotal = std::stof(value);
          std::cout << "VALUE MemUtil After " << "\n" << MemTotal;
        }
        if (key == "MemFree:") {
          MemFree = std::stof(value);
          std::cout << "VALUE MemFree After " << "\n" << MemFree;
        }
        if (key == "MemAvailable:") {
          MemAvailable = std::stof(value);
          std::cout << "VALUE MemAvailable After " << "\n" << MemAvailable;
        }
        if (key == "Buffers:") {
          Buffers = std::stof(value);
          std::cout << "VALUE Buffers After " << "\n" << Buffers;
        }
      }

    }

    // return 0.0;

  }
  Utilization = 1.0 - (MemFree / (MemTotal - Buffers));
  std::cout << "\n UTILIZATION " << Utilization;
  //Memory Utilization = 1.0 - (free_memory / (total_memory - buffers))

  return Utilization;
}

int LinuxParser::TotalProcesses() {
  string line;
  string key;
  int value;
  // float MemTotal, MemFree, MemAvailable, Buffers;
  // float Utilization;
  std::ifstream filestream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "processes") {
          std::cout << "\n PROCESSES " << value;
          //value = std::stoi(value);
        }
      }
    }
  }
  return value;
}

long LinuxParser::UpTime() {
  string line;
  long key;
  string value;
  // float MemTotal, MemFree, MemAvailable, Buffers;
  // float Utilization;
  std::ifstream filestream(LinuxParser::kProcDirectory + LinuxParser::kUptimeFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        // std::cout << "KEY Uptime IS " << key << "\n" << "VALUE Uptime IS " << value;
        //std::string key_uptime = key + " " + " " + value;
        std::cout << "\n KEY UPTIME IS \n" << key;
        break;
        //std::cout << "value UPTIME IS \n" << value;
        //long key_ = std::stoll(key);
        //std::cout << "KEY UPTIME IS " << key_;
        /*if (key == procs) {
          std::cout << "\n PROCESSES " << value;
          //value = std::stoi(value);*/
        }
      }
    //std::cout << "KEY OUTSIDE \n" << key;
    }
  //std::cout << "KEY LAST \n" << key;
  return key;
  }

  int LinuxParser::RunningProcesses() {
  string line;
  string key;
  int value;
  // float MemTotal, MemFree, MemAvailable, Buffers;
  // float Utilization;
  std::ifstream filestream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "procs_running") {
          std::cout << "\n KEY \n" << key;
          std::cout << "\n VALUE \n" << value;
          //value = std::stoi(value);
        }
      }
    }
  }
  return value;
}

/*float LinuxParser::AggCPUtilization(std::string procs, std::string filename_path, std::string filename_path_) {
  string line;
  string key;
  float user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
  float value, value2, value3, value4, value5, value6, value7, value8, value9, value10;
  // float MemTotal, MemFree, MemAvailable, Buffers;
  // float Utilization;
  std::ifstream filestream(filename_path + filename_path_);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value >> value2 >> value3 >> value4 >> value5 >> value6 >> value7 >> value8 >> value9 >> value10) {
        if (key == procs) {
          std::cout << "\n CPU KEY \n" << key;
          std::cout << "\n CPU VALUE \n" << value;
          user = value;
          std::cout << "\n CPU USER \n" << user;
          std::cout << "\n CPU VALUE 2 \n" << value2;
          nice = value2;
          //nice = std::stof(value2);
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
          std::cout << "\n CPU VALUE 8 \n" << value8;
          steal = value8;
          std::cout << "\n CPU VALUE 9 \n" << value9;
          guest = value9;
          std::cout << "\n CPU VALUE 10 \n" << value10;
          guest_nice = value10;
          //value = std::stoi(value);
        }
      }
    }
  }
  // float previdle = previdle + previowait;
  return 0.0;
}*/



// TODO: Read and return the system uptime
//long LinuxParser::UpTime() { return 0; }

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() {
  long uptime;
  uptime = LinuxParser::UpTime();
  return uptime * sysconf(_SC_CLK_TCK);
  }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) {
  string os, kernel, version;
  string line;
  int pid_ = pid;
  string value, value2, value3, value4, value5, value6, value7, value8, value9,
  value10, value11, value12, value13, value14, value15, value16, value17, value18, value19, value20, value21, value22;
  std::ifstream stream(LinuxParser::kProcDirectory + std::to_string(pid_) +
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

  long ActiveJiffies;
  ActiveJiffies = std::stol(value14) + std::stol(value15) + std::stol(value16) + std::stol(value17);
  std:: cout << "\n Active Jiffies = \n" << ActiveJiffies;
  return ActiveJiffies;
}

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() {
  string line;
  string key;
  string user, nice, system, idle, iowait, irq, softirq, steal, guest,
      guest_nice;
  string value, value2, value3, value4, value5, value6, value7, value8, value9,
      value10;
  // float MemTotal, MemFree, MemAvailable, Buffers;
  // float Utilization;
  std::ifstream filestream(LinuxParser::kProcDirectory +
                           LinuxParser::kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value >> value2 >> value3 >> value4 >>
             value5 >> value6 >> value7 >> value8 >> value9 >> value10) {
        if (key == "cpu") {
          //std::cout << "\n CPU KEY \n" << key;
          std::cout << "\n CPU VALUE 1 \n" << value;
          user = value;
          //std::cout << "\n CPU USER \n" << user;
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
          std::cout << "\n CPU VALUE 8 \n" << value8;
          steal = value8;
          std::cout << "\n CPU VALUE 9 \n" << value9;
          guest = value9;
          std::cout << "\n CPU VALUE 10 \n" << value10;
          guest_nice = value10;
          // value = std::stoi(value);
          //
        }
      }
    }
  }
  long ActiveJeffies;
  ActiveJeffies = std::stol(value) + std::stol(value2) + std::stol(value3) +
      std::stol(value4) + std::stol(value5) + std::stol(value6) + std::stol(value7) + std::stol(value9) + std::stol(value10);
  std::cout << "\n ActiveJeffies sum of 10 cpu values \n" << ActiveJeffies;
  return ActiveJeffies;
}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() {
  string line;
  string key;
  string user, nice, system, idle, iowait, irq, softirq, steal, guest,
  guest_nice;
  string value, value2, value3, value4, value5, value6, value7, value8, value9,
  value10;
  // float MemTotal, MemFree, MemAvailable, Buffers;
  // float Utilization;
  std::ifstream filestream(LinuxParser::kProcDirectory +
  LinuxParser::kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value >> value2 >> value3 >> value4 >>
      value5 >> value6 >> value7 >> value8 >> value9 >> value10) {
        if (key == "cpu") {
          //std::cout << "\n CPU KEY \n" << key;
          std::cout << "\n CPU VALUE 1 \n" << value;
          user = value;
          //std::cout << "\n CPU USER \n" << user;
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
          std::cout << "\n CPU VALUE 8 \n" << value8;
          steal = value8;
          std::cout << "\n CPU VALUE 9 \n" << value9;
          guest = value9;
          std::cout << "\n CPU VALUE 10 \n" << value10;
          guest_nice = value10;
          // value = std::stoi(value);
          //
        }
      }
    }
  }
  float idle_, iowait_;
  idle_ = std::stof(idle);
  iowait_ = std::stof(iowait);
  float IdleJeffies;
  IdleJeffies = idle_ + iowait_;
  return IdleJeffies;
  //float IdleJeffies = idle + iowait;
}

/*float LinuxParser::CpuUtilization() {
  // the code to calculate CPU utilization
}*/
/*float LinuxParser::CpuUtilization(int pid){
  // the code to calculate CPU utilization for each process
}*/

// TODO: Read and return CPU utilization
float LinuxParser::CpuUtilization() {
  string line;
  string key;
  float previdle;
  float previowait;
  float prevuser;
  float prevnice;
  float prevsystem;
  float previrq;
  float prevsoftirq;
  float prevsteal;
  string user, nice, system, idle, iowait, irq, softirq, steal, guest,
  guest_nice;
  string value, value2, value3, value4, value5, value6, value7, value8, value9,
  value10;
  // float MemTotal, MemFree, MemAvailable, Buffers;
  // float Utilization;
  std::ifstream filestream(LinuxParser::kProcDirectory +
  LinuxParser::kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value >> value2 >> value3 >> value4 >>
      value5 >> value6 >> value7 >> value8 >> value9 >> value10) {
        if (key == "cpu") {
          std::cout << "\n CPU KEY \n" << key;
          std::cout << "\n CPU VALUE \n" << value;
          user = value;
          std::cout << "\n CPU USER \n" << user;
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
          std::cout << "\n CPU VALUE 8 \n" << value8;
          steal = value8;
          //*std::cout << "\n CPU VALUE 9 \n" << value9;
          guest = value9;
          std::cout << "\n CPU VALUE 10 \n" << value10;
          guest_nice = value10;
          // value = std::stoi(value);
          //
        }
      }
    }
    //std::cout << "\n IDLE VALUE 3 OUTSIDE\n" << system;
  }
  //std::cout << "\n IDLE VALUE 4 IN  \n" << idle << "\n IOWAIT VAUE 5 \n" << iowait;

  // changed from being at end of function
  previdle = std::stof(idle);
  previowait = std::stof(iowait);
  prevuser = std::stof(user);
  prevnice = std::stof(nice);
  prevsystem = std::stof(system);
  previrq = std::stof(irq);
  prevsoftirq = std::stof(softirq);
  prevsteal = std::stof(steal);

  float PrevIdle = previdle + previowait;
  float Idle = std::stof(idle) + std::stof(iowait);
 long idle_test = LinuxParser::IdleJiffies();
  std::cout << "\n Jiffies Idle Test \n" << idle_test;
  std::cout << "\n idle var \n" << std::stof(idle);
  std::cout << "\n iowait var \n" << std::stof(iowait);
  std::cout << "\n Idle equation \n" << Idle;

  float PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
  float NonIdle = std::stof(user) + std::stof(nice) + std::stof(system) + std::stof(irq) + std::stof(softirq) + std::stof(steal);
  long nonidle_jiffies = LinuxParser::ActiveJiffies(); // + LinuxParser::Jiffies();
  std::cout << "\n NON IDLE JIFFIES TEST \n " << nonidle_jiffies;
  std::cout << "\n Non Idle Equation \n" << NonIdle;
  std::cout << "\n user \n " <<  std::stof(user);
  std::cout << "\n nice \n " << std::stof(nice);
  std::cout << "\n system \n " << std::stof(system);
  std::cout << "\n irq \n " << std::stof(irq);
  std::cout << "\n softirq \n " << std::stof(softirq);
  std::cout << "\n steal \n " << std::stof(steal);

  float PrevTotal = PrevIdle + PrevNonIdle;
  float Total = Idle + NonIdle;
  std::cout << "\n Idle  \n" << Idle;
  std::cout << "\n NonIdle \n" << NonIdle;
  std::cout << "\n Total = Idle + NonIdle \n" << Total;

  float totald = Total - PrevTotal;
  float idled = Idle - PrevIdle;

 std::cout << "\n TotalD BEFORE in processor.cpp \n" << totald;
  std::cout << "\n idled BEFORE in processor.cpp \n" << idled;
  float output = ((totald - idled) / totald);
  std::cout << "\n OUTPUT in processor.cpp \n" << output;

 /* previdle = std::stof(idle);
  previowait = std::stof(iowait);
  prevuser = std::stof(user);
  prevnice = std::stof(nice);
  prevsystem = std::stof(system);
  previrq = std::stof(irq);
  prevsoftirq = std::stof(softirq);
  prevsteal = std::stof(steal);*/
  return output;
  //return 0.0;
}
//vector<string> LinuxParser::CpuUtilization() { return {}; }
/*float LinuxParser::CpuUtilization() {
  string line;
  string key;
  float user, nice, system, idle, iowait, irq, softirq, steal, guest,
  guest_nice;
  float value, value2, value3, value4, value5, value6, value7, value8, value9,
  value10;
  // float MemTotal, MemFree, MemAvailable, Buffers;
  // float Utilization;
  std::ifstream filestream(LinuxParser::kProcDirectory +
  LinuxParser::kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value >> value2 >> value3 >> value4 >>
      value5 >> value6 >> value7 >> value8 >> value9 >> value10) {
        if (key == "cpu") {
          std::cout << "\n CPU KEY \n" << key;
          std::cout << "\n CPU VALUE \n" << value;
          user = value;
          std::cout << "\n CPU USER \n" << user;
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
          std::cout << "\n CPU VALUE 8 \n" << value8;
          steal = value8;
          *//*std::cout << "\n CPU VALUE 9 \n" << value9;
          guest = value9;
          std::cout << "\n CPU VALUE 10 \n" << value10;
          guest_nice = value10;*//*
          // value = std::stoi(value);
          //
        }
      }
    }
    //std::cout << "\n IDLE VALUE 3 OUTSIDE\n" << system;
  }
  //std::cout << "\n IDLE VALUE 4 IN  \n" << idle << "\n IOWAIT VAUE 5 \n" << iowait;
  float PrevIdle = previdle + previowait;
  float Idle = idle + iowait;

  //std::cout << "\n Idle Var \n" << Idle;

  float PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
  float NonIdle = user + nice + system + irq + softirq + steal;

  float PrevTotal = PrevIdle + PrevNonIdle;
  float Total = Idle + NonIdle;

  float totald = Total - PrevTotal;
  float idled = Idle - PrevIdle;

  std::cout << "\n TotalD BEFORE in processor.cpp \n" << totald;
  std::cout << "\n idled BEFORE in processor.cpp \n" << idled;
  float output = ((totald - idled) / totald);
  std::cout << "\n OUTPUT in processor.cpp \n" << output;

  previdle = idle;
  previowait = iowait;
  prevuser = user;
  prevnice = nice;
  prevsystem = system;
  previrq = irq;
  prevsoftirq = softirq;
  prevsteal = steal;

  return output; }*/

// TODO: Read and return the total number of processes
// DONE ABOVE
// int LinuxParser::TotalProcesses() { return 0; }

// TODO: Read and return the number of running processes
// DONE ABOVE
// int LinuxParser::RunningProcesses() { return LinuxParser::TotalProcesses("procs_running", LinuxParser::kProcDirectory, LinuxParser::kStatFilename); }

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid[[maybe_unused]]) {
  Process process(pid);
  return process.Command();
  // return process.Command();
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid[[maybe_unused]]) {
  Process process(pid);
  return process.Ram();
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid[[maybe_unused]]) {
  Process process(pid);
  return process.UserHelper();
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid[[maybe_unused]]) {
  Process process(pid);
  return process.User(); }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
//long LinuxParser::UpTime(int pid[[maybe_unused]]) { return 0; }
