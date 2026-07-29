// Define the analog input pins
const int pinA1 = A1;
const int pinA3 = A3;

int a1_count = 0; 
int a3_count = 0; 
void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
}

void loop() {
  // Read the raw 10-bit analog values (0 - 1023)
  int rawValA1 = analogRead(pinA1);
  int rawValA3 = analogRead(pinA3);

  if (rawValA1 < 300){
    a1_count += 1; 
  }else {
    a1_count = 0;
    }
  if (rawValA3 > 0){
    a3_count += 1; 
    } else{
      a3_count = 0;
      
      }

  // Print the raw values and the count to the Serial Monitor
  Serial.print("Raw A1: ");
  Serial.print(rawValA1);
  Serial.print("\t | Raw A3: ");
  Serial.print(rawValA3);
  Serial.print("\t | Count: ");
  Serial.println(a1_count);

  if (a1_count >= 2){
    digitalWrite(6, LOW); 
    a1_count = 0;
  }
  
  if (a3_count >= 2){
    digitalWrite(6, HIGH);
    a3_count = 0; 
    }
  // Short delay to keep the Serial Monitor readable
  delay(500);
}
