#pragma once

#include <ctime>
#include <string>
#include <fstream>
#include <iostream>

#include "board.h"

void capture_sample()
{
  time_t now = time(0);

  std::string file_name("./src/data/" + std::to_string(now) + ".txt");

  std::ofstream file(file_name);

  Board board(2, 9600);

  board.gps_init();

  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 10000; i++)
  {
    // std::cout << board.gps_read();

    file << board.gps_read();
  }

  auto finish = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = finish - start;

  std::cout << "Elapsed time: " << elapsed.count() << " s\n";

  board.gps_close();

  file.close();

  rc_led_set(RC_LED_RED, 1);
  rc_led_set(RC_LED_GREEN, 0);
}

// Buttons.

int running = 0;

void __on_pause_press(void)
{
  rc_led_set(RC_LED_RED, 0);
  rc_led_set(RC_LED_GREEN, 1);
  capture_sample();
  return;
}

void __on_pause_release(void)
{
  // rc_led_set(RC_LED_GREEN, 0);
  return;
}

void __signal_handler(__attribute__((unused)) int dummy)
{
  running = 0;
  return;
}
