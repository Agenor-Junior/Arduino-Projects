//---------------------------INCLUDES & DEFINES-------------------------------
#include <LiquidCrystal.h>
#include <Keypad.h>

// LCD
#define LCD_RS 12
#define LCD_EN 11
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// Keypad
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {  
  {'D','#','0','*'},
  {'C','9','8','7'},
  {'B','6','5','4'},
  {'A','3','2','1'}  
};
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//---------------------------CONSTANTS----------------------------------------
const byte RELAYS[] = {14, 15, 16, 17};
const byte LEDS[] = {31, 33, 35, 37};
const byte MODES[] = {39, 41, 43};
const byte ALARMS[] = {22, 24, 26, 28};
const byte ALARM_LED = 45;

// Analog pins
const int ANALOG_OPEN = A0;
const int ANALOG_CLOSE = A1;

//---------------------------VARIABLES----------------------------------------
int timeOpen, timeClose;

//---------------------------FUNCTION DECLARATIONS---------------------------
void initializeHardware();
void displayMessage(String message);
void checkKeypadInput();
void controlRelays(int relayIndex, bool state);
void handleAlarms();
void debug(String message);

void setup();
void loop();

//---------------------------FUNCTION IMPLEMENTATIONS-------------------------

void initializeHardware() {
  // Configuração de relés e LEDs
  for (byte i = 0; i < sizeof(RELAYS); i++) {
    pinMode(RELAYS[i], OUTPUT);
    digitalWrite(RELAYS[i], LOW); // Estado inicial
  }
  for (byte i = 0; i < sizeof(LEDS); i++) {
    pinMode(LEDS[i], OUTPUT);
    digitalWrite(LEDS[i], LOW);
  }
  
  // Configuração de modos
  for (byte i = 0; i < sizeof(MODES); i++) {
    pinMode(MODES[i], OUTPUT);
    digitalWrite(MODES[i], LOW);
  }

  // Configuração de alarmes
  for (byte i = 0; i < sizeof(ALARMS); i++) {
    pinMode(ALARMS[i], INPUT);
  }
  pinMode(ALARM_LED, OUTPUT);
  digitalWrite(ALARM_LED, LOW);

  // Inicialização do LCD
  lcd.begin(16, 2);
  displayMessage("System Ready");
}

void displayMessage(String message) {
  lcd.clear();
  lcd.print(message);
}

void controlRelays(int relayIndex, bool state) {
  if (relayIndex < sizeof(RELAYS)) {
    digitalWrite(RELAYS[relayIndex], state ? HIGH : LOW);
    digitalWrite(LEDS[relayIndex], state ? HIGH : LOW); // Atualiza o LED correspondente
    debug("Relay " + String(relayIndex) + " set to " + (state ? "ON" : "OFF"));
  }
}

void checkKeypadInput() {
  char key = customKeypad.getKey();
  if (key) {
    debug("Key pressed: " + String(key));
    switch (key) {
      case 'A':
        controlRelays(0, true); // Liga o relé 0
        break;
      case 'B':
        controlRelays(0, false); // Desliga o relé 0
        break;
      // Adicione outros casos conforme necessário
      default:
        displayMessage("Key: " + String(key));
        break;
    }
  }
}

void handleAlarms() {
  bool alarmTriggered = false;
  for (byte i = 0; i < sizeof(ALARMS); i++) {
    if (digitalRead(ALARMS[i]) == HIGH) {
      alarmTriggered = true;
      debug("Alarm " + String(i) + " triggered!");
    }
  }
  digitalWrite(ALARM_LED, alarmTriggered ? HIGH : LOW);
}

#define DEBUG_MODE 1

void debug(String message) {
  if (DEBUG_MODE) {
    Serial.println(message);
  }
}

void setup() {
  Serial.begin(9600);
  initializeHardware();
}

void loop() {
  checkKeypadInput();
  handleAlarms();  
}