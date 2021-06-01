#define PIN_DS 8   //pin 14  75HC595    
#define PIN_STCP 9  //pin 12  75HC595
#define PIN_SHCP 10 //pin 11  75HC595

//Nombre de registre a decalage utilise
#define numberOf74hc595 1 

// nombre total de pin de registre a decalage
#define numOfRegisterPins numberOf74hc595 * 8

// cree un array contenant des booleen de la taille du nombre de pin 74hc595
boolean registers[numOfRegisterPins];

void setup(){
  pinMode(PIN_DS, OUTPUT);
  pinMode(PIN_STCP, OUTPUT);
  pinMode(PIN_SHCP, OUTPUT);

 // remise a 0 des registres
  clearRegisters();
 // on applique les valeurs au registre a decalage
  writeRegisters();
}               

// Mettre toutes les valeurs a 0 pour le resigtre
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
} 

// affectation des valeurs engregistrés dans le tableau "registers" et application (visualisation) des valeurs a la fin
void writeRegisters(){

 // Tant que LOW les modifications ne seront pas affectés
  digitalWrite(PIN_STCP, LOW);

 // boucle pour affecter chaque pin des 74hc595
  for(int i = numOfRegisterPins - 1; i >=  0; i--){

    //doit etre a l'etat bas pour changer de colonne plus tard
    digitalWrite(PIN_SHCP, LOW);

    // recuperation de la valeur dans le tableau registers
    int val = registers[i];

    //affecte la valeur sur le pin DS correspondant a un pin du 74hc595
    digitalWrite(PIN_DS, val);
    
    //colonne suivante
    digitalWrite(PIN_SHCP, HIGH);
  }
  //applique toutes les valeurs au 74hc595
  digitalWrite(PIN_STCP, HIGH);

}

// enregistre une valeur pour un registre etat haut ou bas

void setRegisterPin(int index, int value){
  registers[index] = value;
}

void loop(){
  setRegisterPin(0, HIGH);
  setRegisterPin(1, HIGH);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, HIGH);
  setRegisterPin(4, HIGH);
  setRegisterPin(5, HIGH);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, HIGH);
// appelle la fonction pour appliquer les valeurs
  writeRegisters();  

delay(500);

  setRegisterPin(0, HIGH);
  setRegisterPin(1, HIGH);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, LOW);
  setRegisterPin(4, LOW);
  setRegisterPin(5, HIGH);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, HIGH);
  writeRegisters();

delay(500);

  setRegisterPin(0, HIGH);
  setRegisterPin(1, HIGH);
  setRegisterPin(2, LOW);
  setRegisterPin(3, LOW);
  setRegisterPin(4, LOW);
  setRegisterPin(5, LOW);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, HIGH);
  writeRegisters();

delay(500);

  setRegisterPin(0, HIGH);
  setRegisterPin(1, LOW);
  setRegisterPin(2, LOW);
  setRegisterPin(3, LOW);
  setRegisterPin(4, LOW);
  setRegisterPin(5, LOW);
  setRegisterPin(6, LOW);
  setRegisterPin(7, HIGH);
  writeRegisters();

delay(500);

  setRegisterPin(1, HIGH);
  setRegisterPin(6, HIGH);
  writeRegisters();

delay(200);

  setRegisterPin(2, HIGH);
  setRegisterPin(5, HIGH);
  writeRegisters();

delay(200);
}
