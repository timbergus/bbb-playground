#include <iostream>
#include <fstream>
#include <ctime>
#include <signal.h>

// #include "board.h"

/* void capture_sample()
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
} */

int main()
{
  /* rc_led_set(RC_LED_RED, 1);
  rc_led_set(RC_LED_GREEN, 0);

  if (rc_button_init(RC_BTN_PIN_PAUSE, RC_BTN_POLARITY_NORM_HIGH, RC_BTN_DEBOUNCE_DEFAULT_US))
  {
    fprintf(stderr, "ERROR: failed to init buttons\n");
    return -1;
  }

  signal(SIGINT, __signal_handler);
  running = 1;

  rc_button_set_callbacks(RC_BTN_PIN_PAUSE, __on_pause_press, __on_pause_release);

  while (running)
  {
    rc_usleep(500000);
  }

  rc_button_cleanup(); */

  std::cout << "Hello, world!" << std::endl;

  return EXIT_SUCCESS;
}
