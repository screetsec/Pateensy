/*
 * Facebook Post script for Teensy.
 * I forgot who made this script
 * originally (so sorry!), but
 * the Facebook mobile site had
 * changed since the original script
 * was published, so I updated it.
 * Scroll down to find the message
 * to replace it with your own.
 * 
 * Have fun!
 * 
 * - B3H1NDu/Keith Anderson
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
  
  // Navigate to the mobile version to the site as it's easier to traverse using a keyboard.
  RunCommand("http://m.facebook.com/");
  
  delay(3000);
  
  // Tab our way to statuses button.
  PressKey(KEY_TAB, 12);
  
  delay(1000);
  
  // Type our Facebook message.
  TypeLn("This account has been hacked because I let someone plug in a USB, Signed - The USB in question");  
  
  // Tab our way to the post button.
  PressKey(KEY_TAB, 2);
  
  delay(1000);
  
  // Post the status.
  PressKey(KEY_ENTER, 1);
  
  delay(1000);
  
  // Close the tab.
  Ctrl(KEY_W);
   
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
