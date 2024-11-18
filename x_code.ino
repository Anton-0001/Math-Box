#include <LiquidCrystal.h>
#include <Keypad.h>


// Keypad setup for 4x4
const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns


// Correct keypad mapping
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},   // First row
  {'4', '5', '6', 'B'},   // Second row
  {'7', '8', '9', 'C'},   // Third row
  {'*', '0', '#', 'D'}    // Fourth row
};


// Pin connection for rows and columns
byte rowPins[ROWS] = {13, 10, 9, A4};  // Corrected pin mapping for rows (Row 4 is A4)
byte colPins[COLS] = {8, 7, 6, A5};    // Corrected pin mapping for columns (Column 4 is A5)


Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


// LCD setup
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);


int xval = -1;
int yval = 0;
int zval = 0;
int answer;
int user_answer = 0;
String input = "";  // To store keypad input
bool solved = false;
bool equationGenerated = false; // Flag to check if equation is generated
bool firstRun = true;  // Flag to track if it's the first run


void setup() {
  Serial.begin(9600);
  lcd_1.begin(16, 2); // Initialize LCD with 16 columns and 2 rows
  randomSeed(analogRead(0)); // Use a random seed based on analog input


  if (firstRun) {
    // Display the initial message on startup
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Good Morning!");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Now Solve This");
    delay(4000);  // Wait for 4 seconds
    firstRun = false;  // Ensure this message is only displayed once
  }


  // Debugging: Print the key mappings for verification
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      Serial.print(hexaKeys[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }
}


void loop() {
  if (!solved && !equationGenerated) {
    // Generate new equation
    xval = random(1, 11); // Random x between 1 and 10
    yval = random(1, 11); // Random y between 1 and 10
    zval = random(1, 11); // Random z between 1 and 10
    answer = (xval * yval) + zval;


    // Display the equation on the LCD
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print(String(yval) + "x + " + String(zval) + " = " + String(answer));
    equationGenerated = true; // Set flag that equation is generated
  }


  // Get input from the keypad
  char key = customKeypad.getKey();
  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key);  // Debugging: print the pressed key


    if (key >= '0' && key <= '9') {
      input += key; // Add digits to the input
      lcd_1.setCursor(0, 1);
      lcd_1.print("X = " + input);
    }


    if (key == 'A') { // # acts as the "Enter" key
      user_answer = input.toInt(); // Convert input string to an integer
      input = ""; // Reset input


      if (user_answer == xval) {
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("CORRECT!");
        lcd_1.setCursor(0, 1);
        lcd_1.print("Opening Door...");
        delay(6000); // Wait for 6 seconds before ending
       
        // End the program and wait for 'A' to restart
        while (true) {
          char restartKey = customKeypad.getKey(); // Check for input
          if (restartKey == 'B') {
            // Restart the program by resetting the necessary variables
            resetProgram();
            break; // Exit the loop to restart the program
          }
        }
      } else {
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("Wrong Answer!");
        lcd_1.setCursor(0, 1);
        lcd_1.print("Try Again...");
        delay(2000); // Delay to give time to read the message
        lcd_1.clear();
        equationGenerated = false; // Reset to generate a new equation
      }
    }


    if (key == '*') { // * acts as the backspace key
      if (input.length() > 0) {
        input.remove(input.length() - 1); // Remove the last character
        lcd_1.setCursor(0, 1);
        lcd_1.print("X = " + input + " "); // Clear last character from display
      }
    }
  }
}


// Function to reset program variables
void resetProgram() {
  solved = false; // Reset solved state
  equationGenerated = false; // Reset equation generation flag
  input = ""; // Clear the input
  firstRun = true; // Reset first run flag to show greeting again
  setup(); // Call setup to reinitialize the program
}