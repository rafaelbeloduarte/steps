void steps(int n_passos, int periodo, int periodo_inicial, int acel) {
  byte sequencia = 0;
  int cont = 0;
  int periodo_set = periodo;
  periodo = periodo_inicial;

  int n_passos_acel = 9*(periodo_inicial - periodo_set) / acel;

  int start_decel = n_passos - n_passos_acel;
  int start_acel = n_passos_acel;

  while (cont < n_passos) {
    if (sequencia == 0) {
      digitalWrite(pino1, HIGH);
      digitalWrite(pino2, LOW);
      digitalWrite(pino3, LOW);
      digitalWrite(pino4, LOW);
    }
    if (sequencia == 1) {
      digitalWrite(pino1, HIGH);
      digitalWrite(pino2, HIGH);
      digitalWrite(pino3, LOW);
      digitalWrite(pino4, LOW);
    }
    if (sequencia == 2) {
      digitalWrite(pino1, LOW);
      digitalWrite(pino2, HIGH);
      digitalWrite(pino3, LOW);
      digitalWrite(pino4, LOW);
    }
    if (sequencia == 3) {
      digitalWrite(pino1, LOW);
      digitalWrite(pino2, HIGH);
      digitalWrite(pino3, HIGH);
      digitalWrite(pino4, LOW);
    }
    if (sequencia == 4) {
      digitalWrite(pino1, LOW);
      digitalWrite(pino2, LOW);
      digitalWrite(pino3, HIGH);
      digitalWrite(pino4, LOW);
    }
    if (sequencia == 5) {
      digitalWrite(pino1, LOW);
      digitalWrite(pino2, LOW);
      digitalWrite(pino3, HIGH);
      digitalWrite(pino4, HIGH);
    }
    if (sequencia == 6) {
      digitalWrite(pino1, LOW);
      digitalWrite(pino2, LOW);
      digitalWrite(pino3, LOW);
      digitalWrite(pino4, HIGH);
    }
    if (sequencia == 7) {
      digitalWrite(pino1, HIGH);
      digitalWrite(pino2, LOW);
      digitalWrite(pino3, LOW);
      digitalWrite(pino4, HIGH);
    }
    if (sequencia < 8) {
      sequencia++;
    }
    else {
      sequencia = 0;
      if (cont < start_acel) {
        periodo = periodo - acel;
        Serial.println(periodo);
      }
      if (cont >= start_decel) {
        periodo = periodo + acel;
        Serial.println(periodo);
      }
    }
    cont++;
    delayMicroseconds(periodo);
  }
}
