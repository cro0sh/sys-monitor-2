#include "processor.h"
#include <iostream>
#include "linux_parser.h"
#include <iostream>
using std::string;

// TODO: Return the aggregate CPU utilization
// TODO: change to strings and then convert to float

float Processor::Utilization() {
  return LinuxParser::CpuUtilization();
}
/*float Processor::Utilization() {
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

  return output;
}*/

//return LinuxParser::AggCPUtilization("cpu", LinuxParser::kProcDirectory, LinuxParser::kStatFilename);
