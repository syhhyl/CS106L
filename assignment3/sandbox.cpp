/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include "class.h"

void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  Computer pc {"2025-01-01", 1999.0, "Apple",
    {"2025-01-02", 299.0, "Apple", 10, 4.5, 36}
  };
  pc.info();
  pc.resetdate_();
  pc.info();
}

// int main() {
//   sandbox();
// }