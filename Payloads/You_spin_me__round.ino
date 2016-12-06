/*
 * You spin me 'round payload for Teensy. 
 * Created by B3H1NDu/Keith Anderson
 * Inspired by the many rick roll payloads
 * and a soviet womble video where he uses
 * the song.
 * 
 * A new take on the classic rick-roll payload.
 * Opens up a very fitting music video on youtube
 * and rotates the screen for a little bit.
 * 
 * You may need to adjust delays for slower computers
 * or internet connections.
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

  delay(1000);
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(1500);
  Keyboard.print("https://youtu.be/PGNiXGX2nLU?t=61"); //You Spin Me Round!
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(6000);
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_RIGHT);
  Keyboard.send_now();
  delay(250);
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_DOWN);
  Keyboard.send_now();
  delay(250);
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_LEFT);
  Keyboard.send_now();
  delay(250);
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_UP);
  Keyboard.send_now();
  delay(250);
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_RIGHT);
  Keyboard.send_now();
  delay(250);
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_DOWN);
  Keyboard.send_now();
  delay(250);
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_LEFT);
  Keyboard.send_now();
  delay(250);
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_UP);
  Keyboard.send_now();
  delay(250);
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
