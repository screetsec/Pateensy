/*

TeensyDuino ( BadUSB) Like a Rubber Ducky )
 
You can buy Teensy >> ( https://www.pjrc.com/teensy/teensyduino.html )

Tutorial >> ( https://www.pjrc.com/teensy/teensyduino.html ) , Youtube.com or Google.com :>

PAYLOAD : 


OPEN NOTEPAD AND WRITE HELLO WORLD


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
    
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
    
  delay(500);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print("notepad.exe");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();


  delay(300);
  Keyboard.print(" Hello World !!");
  Keyboard.set_key1(KEY_ENTER);   
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();

}

void loop()
{
  // blink quickly when complete
  digitalWrite(LED_PIN, HIGH);
  delay(ds/2);
  digitalWrite(LED_PIN, LOW);
  delay(ds/2);
}
