/*Este simples código visa controlar um sistema de luzes
* de rua de acordo com um portenciometro e um sistema 
* automatico de farois de rua
*/

int Luz = 0;//declarando a variavel inteira Luz

void setup(){ //durante os comandos abaixo estou definindo o que cada entrada será, se Input(Entrada de dados), ou Output(Saída de dados) 
	pinMode(A0, INPUT);
	Serial.begin(9600);
	
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(10, OUTPUT);
}
void loop(){
	//Aqui estou dizendo que deve ser atribuido a variavel Luz os dados recebidos pela entrada Analogica A0
	Luz = analogRead(A0);
	
	//Imprimindo no monitor serial as nformações que quero
	Serial.print("Luminosidade do Ambiente: ");
	Serial.println(Luz);
	
	//Sistema para verificar a luminosidade, se ela for relativamente baixa, as "luzes de rua"(os LEDs brancos) ´ão ativados, caso contrario, são desativados 
	if (Luz > 500) digitalWrite(2, LOW);
	else digitalWrite(2, HIGH);
	
	//daqui em diante temos a ordem dos farois, já pré-estabelecida e que funciona, bem rápido, mas funciona, e o tempo pode ser alterado da forma que for preferivel(Adendo: otempo esta delay, que mostra o tempo de execução de uma ação para outra, em milissegundos, e tambem desativado os farois amarelos na transição do VERMELHO pro VERDE
	
	digitalWrite(4, LOW);
	digitalWrite(3, HIGH);
	digitalWrite(10, HIGH);
	digitalWrite(8, LOW);
	delay(3100); // Espere por 3100 millissegundo(s)
	digitalWrite(3, LOW);
	digitalWrite(4, HIGH);
	digitalWrite(10, LOW);
	digitalWrite(8, HIGH);
	delay(1000); // Espere por 1000 millissegundo(s)
	digitalWrite(4, LOW);
	digitalWrite(5, HIGH);
	digitalWrite(8, LOW);
	digitalWrite(6, HIGH);
	delay(3100); // Espere por 3100 millissegundo(s)
	digitalWrite(5, LOW);
	digitalWrite(4, HIGH);
	digitalWrite(6, LOW);
	digitalWrite(8, HIGH);
	delay(1000); // Espere por 1000 millissegundo(s)
}
