// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int degree;
double realDegree;
String lcdBuffer;
void setup() {
  pinMode(13, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  degree = 0;
  realDegree = 0;
  lcd.print("Core Body Temperature:");
  // Print a message to the LCD.
  
}

void loop(){
  lcd.print("                ");
  degree = analogRead(0);
  realDegree = (double)degree/1024;
  realDegree *= 5;
  realDegree -= 0.5;
  realDegree *= 100;
  lcd.setCursor(0,1);
  realDegree = (9.0/5)*(realDegree) + 32;
  String output = String(realDegree) + String((char)178) + "F";
  lcd.print((realDegree-32)*5/9);
  lcd.print (String((char)178));
  lcd.print("C");
  lcd.print(" ");
  lcd.print(output);
  delay(1000);
  lcd.clear();
  if (realDegree > 122) {
    lcd.print("Abnormal");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature: ");
    lcd.setCursor(0, 1);
    
    
  
  // Convert Fahrenheit back to Celsius and display
  double tempCelsius = (realDegree - 32) * 5 / 9;
  lcd.print(tempCelsius);
  lcd.print((char)223); // Degree symbol
  lcd.print("C ");

  // Check if the temperature is below the hypothermia threshold (35C)
  if (tempCelsius < 35.0) {
    digitalWrite(13, HIGH); // Send signal to activate vest (assuming pin 13 is used)
    lcd.print("Cold");
  } else {
    digitalWrite(13, LOW); // No signal, child is not cold
    lcd.print("Normal");
  }
  
   delay(1000);
  
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
}
}
