#include <iostream>
#include <fstream>
#include <ctime>
#include <signal.h>

#include "core.h"
#include "color.h"

// #include "board.h"
// #include "functions.h"

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

  fmt::print(fmt::emphasis::bold | fg(fmt::color::red), "Elapsed time: {0:.2f} seconds\n", 1.23);

  return EXIT_SUCCESS;
}
