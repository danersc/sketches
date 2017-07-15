#include <SoftwareSerial.h>
#include <Wire.h>
#include "LiquidCrystal.h"

SoftwareSerial ESP8266(2, 3); // RX, TX
LiquidCrystal lcd(0);

String received;
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  Serial.println("A iniciar");
  ESP8266.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);

}

void loop()
{
  
  if (ESP8266.available()){

    String recebido = leStringSerial();
    opLed(recebido);
    
  }
    
  if (Serial.available()) {
    ESP8266.write(Serial.read());
  }
  
}

/**
 * Função que lê uma string da Serial
 * e retorna-a
 */
String leStringSerial(){
  String conteudo = "";
  char caractere;
  
  // Enquanto receber algo pela serial
  while(ESP8266.available() > 0) {
    // Lê byte da serial
    caractere = ESP8266.read();
    // Ignora caractere de quebra de linha
    if (caractere != '\n'){
      // Concatena valores
      conteudo.concat(caractere);
    }
    // Aguarda buffer serial ler próximo caractere
    delay(10);
  }
    
  Serial.print("Recebi: ");
  Serial.println(conteudo);
    
  return conteudo;
}

void opLed(String command){
  Serial.print("Comando serial: ");
  Serial.println(command);
  lcd.setCursor(0, 0);
  lcd.print(command);
}


