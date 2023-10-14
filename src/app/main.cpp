#include <iostream>
#include <fstream>
#include <ctime>

#include "board.h"

int main()
{
  time_t now = time(0);
  
  std::string file_name("./src/data/" + std::to_string(now) + ".txt");
  
  std::ofstream file(file_name);
  
  Board board(2, 9600);
  
  board.gps_init();
  
  auto start = std::chrono::high_resolution_clock::now();
  
  for (int i = 0; i < 20000; i++)
  {
    // std::cout << board.gps_read();
    
    file << board.gps_read();
  }
  
  auto finish = std::chrono::high_resolution_clock::now();
  
  std::chrono::duration<double> elapsed = finish - start;

  std::cout << "Elapsed time: " << elapsed.count() << " s\n";
  
  board.gps_close();
  
  file.close();

  return EXIT_SUCCESS;
}
