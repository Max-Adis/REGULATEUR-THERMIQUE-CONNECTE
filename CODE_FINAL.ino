#include "DHT.h"     //Bibliothèque du capteur DHT11
#include <SoftwareSerial.h>  //Bibliothèque du module bluetooth

//Déclaration des variables
SoftwareSerial mySerial(10, 11); // RX, TX vers HC-05
const int DHTPIN = 2;
const int DHTTYPE = DHT11;
const int pinRelais = 3;
DHT dht(DHTPIN, DHTTYPE);
bool modeAuto;
float seuil;

unsigned long dernierEnvoi = 0;
const unsigned long intervalleEnvoi = 1000; // 1000 millisecondes, respecte le DHT11

//Initialisation des variables 
void setup() {
  pinMode(DHTPIN,INPUT);
  pinMode(pinRelais, OUTPUT);
  digitalWrite(pinRelais, HIGH); // état initial : ventilateur éteint
  modeAuto = false;
  seuil = 31.0;       //Valeur par défaut de la température 
  dht.begin(); 
  Serial.begin(9600);
  mySerial.begin(9600);
}


void loop() {
  /* 1. Envoi périodique de la température sur le Bluetooth
  //millis() renvoie le nombre de millisecondes écoulées depuis le démarrage de l'Arduino.  
  Pourquoi pas delay(1000) ? Parce que delay() bloquerait complètement 
  le programme pendant 1 secondes, empêchant l'Arduino de recevoir une commande "A" ou "B" pendant ce temps. 
  Avec millis(), l'Arduino reste réactif en permanence.
  */
  if (millis() - dernierEnvoi >= intervalleEnvoi) { /*Cette ligne vérifie : "est-ce que 2000 ms se sont écoulées depuis le dernier envoi ?" Si oui, 
                                                     on entre dans le bloc.*/
    float t = dht.readTemperature(); 
    if (!isnan(t)) {
      mySerial.println(t);   // envoie juste le nombre, ex: "25.30"
      Serial.print("Température actuelle: ");
      Serial.println(t);     // pour debug sur le moniteur série USB
      if (modeAuto){
        if (t > seuil){
          digitalWrite(pinRelais, LOW);
        }
        else{
          digitalWrite(pinRelais, HIGH);
        }
      }
    }
    dernierEnvoi = millis();                            
  }


  // 2. Lecture des commandes manuelles reçues depuis l'app (A = ON, B = OFF)

  if (mySerial.available()) {
    String commande = mySerial.readStringUntil('\n');
    commande.trim();
  
    if (commande == "M1") {
      modeAuto = true;
    }
    else if (commande == "M0") {
      modeAuto = false;
    }
    else if (commande.startsWith("S")) {
      seuil = commande.substring(1).toFloat();  // ex: "S28.5" -> 28.5
      Serial.print("Nouveau seuil reçu");     
      Serial.println(seuil);     // debug utile pour vérifier
    }
    else if (commande == "A" && !modeAuto) {
      digitalWrite(pinRelais, LOW); // ventilateur ON
      Serial.println("Commande A reçue -> Ventilateur ON");     // commande manuelle ON (uniquement si pas en auto)
    }
    else if (commande == "B" && !modeAuto) {
      digitalWrite(pinRelais, HIGH);  // ventilateur OFF
      Serial.println("Commande B reçue -> Ventilateur OFF");      // commande manuelle OFF
    }
  }
}
