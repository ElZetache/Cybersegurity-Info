#include <Keyboard.h>

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  delay(120000);
  //sin este delay se vuelve loco (se puede poner mas pequeño)
}

void loop() {
  Keyboard.press(KEY_RIGHT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.println("cmd");
  Keyboard.press(KEY_RETURN);
  delay(20);
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.press(KEY_LEFT_ALT);
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.print("color 02");
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("cls");
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.println("ipconfig /all");
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(2000);


  Keyboard.print("cls");
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.print("Has sido hackeado por YksuhRoht. Este ordenador borrara todos los datos en...");
  delay(3000);
  Keyboard.print(" 3...");
  delay(1000);
  Keyboard.print(" 2...");
  delay(1000);
  Keyboard.print(" 1...");
  delay(1000);
  Keyboard.press(KEY_ESC);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.print("cd ..");
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.print("cd ..");
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.print("Descargando datos confidenciales.");
  delay(3000);
  Keyboard.print(".");
  delay(250);
  Keyboard.print(".");
  delay(250);
  Keyboard.print(".");
  delay(250);
  Keyboard.print(".");
  delay(250);
  Keyboard.print(".");
  delay(250);
  Keyboard.print(".");
  delay(250);
  Keyboard.print(".");
  delay(250);
  Keyboard.print(".");
  delay(250);
  Keyboard.print(".");
  delay(250);
  Keyboard.print(".");
  delay(250);
  Keyboard.press(KEY_ESC);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.print("tree");
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(4000);

  while (1) {
    Keyboard.press(KEY_RIGHT_GUI);
    Keyboard.press('l');
    delay(100);
    Keyboard.releaseAll();
    delay(3000);
  };

  Keyboard.end();
}
