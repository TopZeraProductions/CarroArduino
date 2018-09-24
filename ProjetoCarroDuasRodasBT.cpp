/*
	PT-BR:
	
	O trabalho consiste na realizacao de um combate entre carros controlados remotamente por comunicacao bluetooth, 
	as pecas que serao necessarias para faze-lo funcionar são:
	
	1x - Arduino Uno
	1x - Módulo bluetooth modelo HC06;
	1x - Shield modelo L293D;
	1x - Chassi com 2 motores com caixas de redução;
	1x - Suporte para acoplamento de 4x pilhas AA;
	1x - Uma bateria comum de 9v;
	1x - Plugue para bateria
	4x - Pilhas do tipo AA;
	xx - Jumpers diversos para ligações;
	
	Obs: para o correto funcionamento é recomendavel a instalaçao do aplicativo para android "Arduino Bluetooth RC Car"
	https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller
	Obs2: para ocorrer a conexão bluetooth somente é necessário conectar saída tx do módulo na porta rx(0) do arduíno, 
	não sendo necessario nenhuma configuração extra. 
	
	----------------------------------------------------
	@author: João vitor paulino 
	@year: 2018
	
	Firmware arduino controle de motores DC por bluetooth v0.1
	----------------------------------------------------
*/

#include <AFMotor.h> 

AF_DCMotor M1(1);
AF_DCMotor M2(2);

char buf;
void setup(){
	Serial.begin(9600);
}
void loop(){
	while(Serial.available() > 0){ 
		M1.setSpeed(255);
		M2.setSpeed(255);
		buf = Serial.read();
		switch (buf){ 
			case 'S':          
				M1.run(RELEASE);
				M2.run(RELEASE);
                break;	
			case 'F':          
				M1.run(FORWARD);
				M2.run(FORWARD);
                break;
			case 'L':
				M.run(BACKWARD);
				M2.run(FORWARD);
                break;
			case 'R':
				M1.run(FORWARD);
				M2.run(BACKWARD);
                break;
			case 'B':
				M.run(BACKWARD); 
				M.run(BACKWARD); 
                break;
			case 'G':
				M1.setSpeed(100);
				M1.run(FORWARD); 
				M2.run(FORWARD); 
                break;	
			case 'H':
				M1.setSpeed(100);
				M1.run(BACKWARD);
				M2.run(BACKWARD);
                break;	
			case 'I':
				M2.setSpeed(100);
				M1.run(FORWARD); 
				M2.run(FORWARD); 
                break; 	
			case 'J':
				M2.setSpeed(100);
				M1.run(BACKWARD);
				M2.run(BACKWARD);
                break;				
		}
	}
}
