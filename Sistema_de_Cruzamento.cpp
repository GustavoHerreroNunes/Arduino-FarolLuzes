/*Este simples código visa controlar um sistema de luzes
* de rua de acordo com um portenciometro e um sistema 
* automatico de farois de rua
*/

int Luz = 0, Led = 3, v =1;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  for(int x=3; x<=5; x++){
  	pinMode(x, OUTPUT);
  }
  for(int y=7; y<=9; y++){
  	pinMode(y, OUTPUT);
  }
}

void loop()
{
  Luz = analogRead(A0);
  
  //Informando ao usuario a luminosidade ambiente
  Serial.print("Luminosidade do Ambiente: ");
  Serial.println(Luz);
  
  //Sistema para verificar a luminosidade, se ela for relativamente baixa, as "luzes de rua"(os LEDs brancos) sao ativados, caso contrario, são desativados 
  if (Luz > 500) {
    digitalWrite(2, LOW);
  } else {
    digitalWrite(2, HIGH);
  }
  
  /*Ascendendo as luzes opostas dos farois (Ex: Verm. e Verd; Amar. e Amar.)*/ 
  digitalWrite(Led, 1);
  digitalWrite((Led+4), 1);
  
  /*Verificando se a luz que foi acesa é a amarela*/
  if(Led == 4) delay(1000);//Se sim, o delay sera menor
  else delay(3100);
  
  /*Desligando os LEDs acesos anteriormente para no proximo loop ja sejam acesos os proximos sem interferencia*/
  digitalWrite(Led, 0);
  digitalWrite((Led+4), 0);
  
  /*Verificando quantas vezes o código ja rodou, e assim o LED a ser aceso devera ser...*/
  if(v<3) Led++;//...o proximo...
  else Led--;//...ou o anterior
  
  v++;//Mais uma vez
  
  if(v==5) v =1;//Se o código ja rodou 5 vezes, reinicia-se o ciclo
  
}
