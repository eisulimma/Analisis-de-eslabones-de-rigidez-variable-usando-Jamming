const int sensor = 15;
const int rele = 4;

int volt = 0;

void setup() {
  pinMode(rele, OUTPUT);

  Serial.begin(9600);
  delay(1000);
}

void loop() {
  digitalWrite(rele,HIGH); 
  //HIGH: cerrar  Relé, por tanto corren 10V y se abre la electrovalcula
  //LOW: abrir Relé, por tanto se cierra la electrovalcula

  //Lectura de la entrada analógica
  volt = analogRead(sensor);
  Serial.println(sensor);
  delay(500);

}
