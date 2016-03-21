/***
 *     _   _ _     _        _    _ _           _               
 *    | | | (_)   | |      | |  | (_)         | |              
 *    | |_| |_  __| | ___  | |  | |_ _ __   __| | _____      __
 *    |  _  | |/ _` |/ _ \ | |/\| | | '_ \ / _` |/ _ \ \ /\ / /
 *    | | | | | (_| |  __/ \  /\  / | | | | (_| | (_) \ V  V / 
 *    \_| |_/_|\__,_|\___|  \/  \/|_|_| |_|\__,_|\___/ \_/\_/  
 *                                                             
 *                                                             
 *     _             _____                                     
 *    | |           |  _  |                                    
 *    | |__  _   _  | | | |_____   _ _ __ _   _                
 *    | '_ \| | | | | | | |_  / | | | '__| | | |               
 *    | |_) | |_| | \ \_/ // /| |_| | |  | |_| |               
 *    |_.__/ \__, |  \___//___|\__,_|_|   \__,_|               
 *            __/ |                                            
 *           |___/                                             
 */

#include <paensy.h>

void setup() {
  
  // Configure the delay that everything else scales off of.
  SetDelay(100);
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
  
  // Open CMD faded and harder to see.
  RunCommand("cmd /Q /D /T:7F /F:OFF /V:ON /K");
  
  delay(1000);
  
  // Pass the screen height as an argument so it can guarantee it hides the window.
  HideCurWindow(1080);
  
  // Demonstrate the ability to still type in the window. If you want to see it, alt + space the window and then select "Maximize".
  TypeLn("ping www.google.com");
   
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
