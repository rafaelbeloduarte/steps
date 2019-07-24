unsigned int freq = 490;
int pino1 = 8;
int pino2 = 9;
int pino3 = 10;
int pino4 = 11;
unsigned long tempo = 10;
int passos = 4500; // n passos por volta
int periodo = 1;
int periodo_inicial = 2000;
int acel = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pino1, OUTPUT);
  pinMode(pino2, OUTPUT);
  pinMode(pino3, OUTPUT);
  pinMode(pino4, OUTPUT);
}

void loop() {
  Serial.println("numero de passos");
  while (Serial.available() == 0);
  int passos = Serial.parseInt();
  Serial.println(Serial.available());
  Serial.println("periodo");
  while (Serial.available() == 0);

  periodo = Serial.parseInt();
  steps(passos, periodo, periodo_inicial, acel);
  Serial.println("finalizado.");
  digitalWrite(pino1, LOW);
  digitalWrite(pino2, LOW);
  digitalWrite(pino3, LOW);
  digitalWrite(pino4, LOW);
}
