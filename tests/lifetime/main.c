#include <stdio.h>
#include <logger.h>

static Logger logger;

int main() {
  lg_init_opt(&logger, "logs", .sinks={.items={{stdout, LG_OUT_TTY}}, .count=1});

  printf("Is logger alive: %s\n", lg_is_alive(&logger) ? "YES" : "NO");
  lg_info("This should be visible!");

  lg_destroy(&logger);

  printf("Is logger alive: %s\n", lg_is_alive(&logger) ? "YES" : "NO");
  lg_info("This should NOT be visible!");
  return 0;
}
