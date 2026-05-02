#define LOGGER_IMPLEMENTATION
#include <logger.h>

// Empty translation unit test (tests includes etc.)

int main() {
  Logger lg = {0};
  lg_init_defaults(&lg, "logs"); // tests undefined refereneces/linker errors (Will "extern"s fucked up or not)
  return 0;
}
