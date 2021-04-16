/*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: Mica Rubin
 */

#include "tp0.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;



	logger = iniciar_logger();

	//Loggear "soy un log"

	config = leer_config();

	//asignar valor de config a la variable valor

	//Loggear valor de config

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	//crear conexion
	//Primero hay que levantar los valores IP y PUERTO del archivo de configuracion con esas claves
	ip = config_get_string_value(g_config, "IP");
	puerto = config_get_string_value(g_config, "PUERTO");
	//creo la conexion
	conexion = crear_conexion(ip, puerto);
	//levanto el valor que le corresponde a clave
	valor = config_get_string_value(g_config, "CLAVE");
	//le mando el mensaje al servidor
	enviar_mensaje(valor, conexion);
	terminar_programa(conexion);

	paquete(conexion);
	//terminar_programa(conexion); ?
	terminar_programa(conexion, logger, config);
}

t_log* iniciar_logger(void){
	g_logger = log_create("tp0.log", "TP0", 1, LOG_LEVEL_INFO);
	//logeo msje soy un log
	log_info(g_logger, "Soy un log");

}

t_config* leer_config(void){
	char* valor;
	//abro archivo de config tp0.config
	g_config = config_create("tp0.config");
	//levanto valor de clave
	valor = config_get_string_value(g_config, "CLAVE");
	//logeo el valor
	log_info(g_logger, valor);
}

void leer_consola(t_log* logger)
{
	char* leido;

	//El primero te lo dejo de yapa
	leido = readline(">");
	while(*leido != '\0'){
		log_info(g_logger, leido);
		free(leido);
		leido = readline(">");
	}
	free(leido);

}

void paquete(int conexion)
{
	//Ahora toca lo divertido!

	char* leido;
	t_paquete* paquete;


}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
}
