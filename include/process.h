#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <iostream>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process  {
 public:
  Process(int p) : pid(p) {}
  //int Pid() { std::cout << "\n SET PID TO \n" << pid; return pid; }             // TODO: See src/process.cpp
  int Pid(); // { std::cout << "\n SET PID TO \n" << pid; return pid; }
  std::string User();                      // TODO: See src/process.cpp // changed to int pid instead of 0 args
  std::string UserHelper(); // changed to int pid instead of 0 args
  std::string Command();                   // TODO: See src/process.cpp // changed to int pid instead of 0 args
  float CpuUtilization() const;                  // TODO: See src/process.cpp
  // float CpuUtilization2();
  std::string Ram();                       // TODO: See src/process.cpp // changed to int pid instead of 0 args
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp
//
  //int Pid() { return pid; }

  // TODO: Declare any necessary private members
 private:
  int pid;
};

/*
Process::Pid() {

}
*/

/*int Process::Pid() {

};*/

#endif