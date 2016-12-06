/*
 * Accessable script for Teensy.
 * Created by B3H1NDu/Keith Anderson
 * 
 * Super annoying prank script, turns
 * on high-contrast mode, enables
 * Narrator and spins the screen a few
 * times.
 * 
 * You may need to adjust the delays
 * depending on the victim's PC.
 */

#include <paensy.h>

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
  // Turn on High Contrast Mode
  Keyboard.set_modifier(MODIFIERKEY_SHIFT | MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_PRINTSCREEN);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(1000);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(6000);
  // Turn on narrator
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(1000);
  Keyboard.set_key1(KEY_LEFT);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(500);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(1000);
  // Spin the screen
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_RIGHT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_DOWN);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_LEFT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_UP);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_RIGHT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_DOWN);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_LEFT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_UP);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void loop() {
 // Celebratory LED fluttering.
 LED_Flutter(200, 10);
 
 // P
 LED_MorseDot();
 LED_MorseDash();
 LED_MorseDash();
 LED_MorseDot();
 
 // W
 LED_MorseDot();
 LED_MorseDash();
 LED_MorseDash();
 
 // N
 LED_MorseDash();
 LED_MorseDot();

 // 3
 LED_MorseDot();
 LED_MorseDot();
 LED_MorseDot();
 LED_MorseDash();
 LED_MorseDash();
 
 // D
 LED_MorseDash();
 LED_MorseDot();
 LED_MorseDot();
 
 // Flutter again.
 LED_Flutter(200, 10); 
}
