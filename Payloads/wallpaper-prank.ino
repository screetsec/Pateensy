/*

Teensy ( https://www.pjrc.com/teensy/ )

Payload: wallpaper-prank

Concept https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---Wallpaper-prank

Minimize all windows, take screenshot, disable desktop icons, saves screenshot and sets as wallpaper

Created by Kleo Bercero - @kbeflo - kbeflo@gmail.com

*/

#include <paensy.h>

int ds = 500;

void setup() {

  // Configure the delay that everything else scales off of.
  SetDelay(200);
  // Configure the delay that the Morse code uses.
  SetMorseDelay(250);

  // Perform an initial delay to give the USB time to prepare.
  PerformInitDelay();

  // LED pin number, 13 for 3.1
  // 11 for 2 and 2.x
  SetLEDPin(13);
  // Put the pin into output mode
  pinMode(LED_PIN, OUTPUT);
  // Turn on the LED pin so we know the device is running.
  digitalWrite(LED_PIN, HIGH);
  delay(3000);
  // Show desktop
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_D);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  // Printscreen
  Keyboard.set_key1(KEY_PRINTSCREEN);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  // Hide desktop icons
  Keyboard.set_key1(KEY_MENU);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_V);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_D);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  // Open paint
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  Keyboard.print("mspaint");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  // Paste Printscreen
  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_V);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  // Save as wallpaper
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_F);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  Keyboard.set_key1(KEY_B);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  Keyboard.print("26xxm74b5i.png");
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  // Close paint
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_F4);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(1000);
}

void loop()
{
  // blink quickly when complete
  digitalWrite(LED_PIN, HIGH);
  delay(ds/2);
  digitalWrite(LED_PIN, LOW);
  delay(ds/2);
}
