// unidade de comprimento = [mm]
//passos/volta =
//redução = 9 voltas do motor para 1 revolução
//1 revolução -> 2.5mm
// periodo mínimo = 500 microsegundos = 5ms
// pedir a vazão em [mL/min]

float D = 36.5; //diâmetro
float z = 2.5;  //avanço do pistão

unsigned int freq = 490;
int pino1 = 8;
int pino2 = 9;
int pino3 = 10;
int pino4 = 11;
unsigned int passos = 46100; // n passos por volta
unsigned int periodo = 1000;
unsigned int periodo_inicial = 2000;
unsigned int acel = 10;
float vazao = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pino1, OUTPUT);
  pinMode(pino2, OUTPUT);
  pinMode(pino3, OUTPUT);
  pinMode(pino4, OUTPUT);
}

void loop() {
  Serial.println("vazão");
  while (Serial.available() == 0);
  int vazao = Serial.parseInt();
  //  Serial.println("numero de passos");
  //  while (Serial.available() == 0);
  //  int passos = Serial.parseInt();
  //  Serial.println(Serial.available());
  //  Serial.println("periodo");
  //  while (Serial.available() == 0);
  //  periodo = Serial.parseInt();
  //  steps(passos, periodo, periodo_inicial, acel, vazao);
  steps(passos, periodo, periodo_inicial, acel, vazao);
  Serial.println("finalizado.");
  digitalWrite(pino1, LOW);
  digitalWrite(pino2, LOW);
  digitalWrite(pino3, LOW);
  digitalWrite(pino4, LOW);
}
