#pragma once

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <map>

#include <chrono>
#include <thread>

#include <robotcontrol.h>

using namespace std::chrono_literals;

// https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp

class Board
{
private:
  int port;
  int baudrate;
  
  struct termios tty;
  
  std::map<int, speed_t> baudrates = {
      {9600, B9600},
      {19200, B19200},
      {38400, B38400},
      {57600, B57600},
      {115200, B115200},
  };

public:
  Board(int port, int baudrate);
  ~Board();

  void gps_init();
  std::string gps_read();
  void gps_close();
};

Board::Board(int port, int baudrate)
{
  this->baudrate = baudrate;
  
  char port_name[50];
  
  sprintf(port_name, "/dev/ttyO%d", port);
  
  this->port = open(port_name, O_RDWR | O_NOCTTY);
}

Board::~Board()
{
  gps_close();
}

void Board::gps_init()
{
  if (tcgetattr(port, &tty) != 0)
  {
    printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
  }

  cfsetispeed(&tty, baudrates[baudrate]);
  cfsetospeed(&tty, baudrates[baudrate]);

  if (tcsetattr(port, TCSANOW, &tty) != 0)
  {
    printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
  }
}

std::string Board::gps_read()
{
  std::string message = "";

  char c = '\0';

  read(port, &c, 1);
  
  if (c == '$') {
  
    message += c;
  
    while (c != '\n')
    {
      read(port, &c, 1);
      message += c;
    }
  }
  
  std::this_thread::sleep_for(1ms);
  
  return message;
}

void Board::gps_close()
{
  close(port);
}
