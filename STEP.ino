// 2615,87 mm3 -> 9 voltas
// vazão =
// fator de conversão de [mL/min] para [mm3/µs] = 1.666666667E-5

void steps(unsigned int n_passos, unsigned int periodo, int periodo_inicial, int acel, float vazao) {
  byte sequencia = 0;
  unsigned int cont = 0;
  unsigned int periodo_set;
  periodo = periodo_inicial;

  float inicio = 0, fim = 0, t = 0;

  //10 revoluções -> 25cm -> 90 voltas no máximo (1 volta = 4610 passos)
  // volume deslocado máximo = 261 586,68 mm3
  // encontrar o tempo

  float volume = 26158.67; //mm3 (z = 5mm)
  float tempo = 0;
  float tempo_decorrido = 0;

  vazao = vazao * 1.666666667E-5;
  Serial.print("vazão (mm3/µs): ");
  Serial.println(vazao, 10);

  tempo = volume / vazao;

  Serial.print("tempo_calculado: ");
  Serial.println(tempo);

  periodo_set = tempo / n_passos;

  Serial.print("periodo_set: ");
  Serial.println(periodo_set);

  unsigned int n_passos_acel = 9 * (periodo_inicial - periodo_set) / acel;
  unsigned int n_passos_decel = n_passos - n_passos_acel;

  unsigned int per = 0, t_acelera = 0;
  // para calcular o tempo se for dado o número de passos:
  for (int i = 0; i < n_passos_acel / 9; i++) {
    per = per - acel;
    //    Serial.print("per: ");
    //    Serial.println(per);
    for (int j = 0; j < 8; j++) {
      t_acelera = t_acelera + per;
    }
    t_acelera = t_acelera + per;
    //    Serial.print("t_acelera: ");
    //    Serial.println(t_acelera);
  }
  // obs: meus testes indicam que há uma diferença de mais ou
  // menos 100 000 µs/volta entre o tempo real e o calculado
  // creio que este seja o tempo o chip utiliza para executar as instruções
  //  t_mcu = (n_passos - 2 * n_passos_acel) * periodo_mcu;
  //  t_calculado = 2 * t_acelera + t_mcu + (n_passos / 4610) * 118000;
  Serial.print("t_acelera: ");
  Serial.println(t_acelera);

  inicio = micros();
  if (periodo_set < 500) {
    Serial.println("Vazão muito alta!");
  }
  else {
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
        if (cont < n_passos_acel) {
          periodo = periodo - acel;
          //Serial.println(periodo);
        }
        if (cont > n_passos_decel) {
          if (periodo < periodo_inicial) {
            periodo = periodo + acel;
            //Serial.println(periodo);
          }
        }
      }
      cont++;
      delayMicroseconds(periodo);
      tempo_decorrido = micros() - inicio;
    }
  }
  fim = micros();
  t = fim - inicio;
  Serial.print("tempo_decorrido (µs): ");
  Serial.println(t);
}
