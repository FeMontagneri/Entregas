/**
 * IMT - Rafael Corsi
 * 
 * PIO - 07
 *  Configura o PIO do SAM4S (Banco A, pino 19) para operar em
 *  modo de output. Esse pino est� conectado a um LED, que em 
 *  l�gica alta apaga e l�gica baixa acende.
*/

#include <asf.h>
#include <pio_maua.h>

/*
 * Prototypes
 */

/** 
 * Defini��o dos pinos
 * Pinos do uC referente aos LEDS.
 *
 * O n�mero referente ao pino (PIOAxx), refere-se ao
 * bit que deve ser configurado no registrador para alterar
 * o estado desse bit espec�fico.
 *
 * exe : O pino PIOA_19 � configurado nos registradores pelo bit
 * 19. O registrador PIO_SODR configura se os pinos ser�o n�vel alto.
 * Nesse caso o bit 19 desse registrador � referente ao pino PIOA_19
 *
 * ----------------------------------
 * | BIT 19  | BIT 18  | ... |BIT 0 |
 * ----------------------------------
 * | PIOA_19 | PIOA_18 | ... |PIOA_0|
 * ----------------------------------
 */


/**
 * Main function
 * 1. configura o clock do sistema
 * 2. desabilita wathdog
 * 3. ativa o clock para o PIOA
 * 4. ativa o controle do pino ao PIO
 * 5. desabilita a prote��o contra grava��es do registradores
 * 6. ativa a o pino como modo output
 * 7. coloca o HIGH no pino
 */

int main (void)
{

	/**
	* Inicializando o clock do uP
	*/
	sysclk_init();
	
	/** 
	*  Desabilitando o WathDog do uP
	*/
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	pin_config();


	/**
	*	Loop infinito
	*/
		while(1){

            /*
             * Utilize a fun��o delay_ms para fazer o led piscar na frequ�ncia
             * escolhida por voc�.
             */
            //delay_ms();
			
			delay_ms(500);
			PIOA_pin_clear();
			PIOC_pin_set();
			delay_ms(500);
			PIOA_pin_set();
			PIOC_pin_clear();
			
			
		
	}
}



