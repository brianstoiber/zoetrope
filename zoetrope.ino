  // Audio
  #include "Arduino.h"
  #include "SoftwareSerial.h"
  #include "DFRobotDFPlayerMini.h"

  SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
  DFRobotDFPlayerMini myDFPlayer;
  void printDetail(uint8_t type, int value);


  // Motor
  int motor1pin1 = 2;     // L298N Motor Controller Input 1
  int motor1pin2 = 3;     // L298N Motor Controller Input 2


  // LEDs
  #include <FastLED.h>

  #define MAX_NUM_LEDS 10   // # of LEDs in strip
  #define LED_PIN 6    // pin that connects from the LED strip through the 330oH resistor

  CRGB leds[MAX_NUM_LEDS];

  // Timer
  boolean didMyOneTimeAction = false;



void setup() {

  // Audio
  
  
  myDFPlayer.volume(30);  // Set volume value. From 0 to 30
  myDFPlayer.play(1);  // Play the first mp3 (0001.mp3)
  
  
  // Motor
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT); 
  
  pinMode(9, OUTPUT);

  analogWrite(9, 100); //RPM - 100 = 80RPM


 
 
  // LEDs
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, MAX_NUM_LEDS);
  FastLED.setBrightness(100);
}





void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}





void loop() {

  if (didMyOneTimeAction == false)
  {
    didMyOneTimeAction = true;
    
  
  // Audio
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  
  
  // Motor
  delay(4200);
  digitalWrite(motor1pin1, HIGH);
  delay(95000);      // Spin for 95 seconds
  digitalWrite(motor1pin1, LOW);


  

  // LEDs
  leds[0] = CRGB::White;
  leds[1] = CRGB::White;
  leds[2] = CRGB::White;
  leds[3] = CRGB::White;
  leds[4] = CRGB::White;
  leds[5] = CRGB::White;
  leds[6] = CRGB::White;
  leds[7] = CRGB::White;
  leds[8] = CRGB::White;
  leds[9] = CRGB::White;
  leds[10] = CRGB::White;
  leds[11] = CRGB::White;
  leds[12] = CRGB::White;
  leds[13] = CRGB::White;
  leds[14] = CRGB::White;
  leds[15] = CRGB::White;
  FastLED.show();
  delay(80);

  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
  leds[10] = CRGB::Black;
  leds[11] = CRGB::Black;
  leds[12] = CRGB::Black;
  leds[13] = CRGB::Black;
  leds[14] = CRGB::Black;
  leds[15] = CRGB::Black;
  FastLED.show();
  delay(80); 
  }
}
