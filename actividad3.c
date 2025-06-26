/*
- Ejercicio 1 (10 puntos)

Se pide crear un programa que pueda administrar los datos de los personajes de un videojuego. 

Para ello contamos con un fichero que contiene la información de estos personajes

En el caso de que no exista se debe pedir al usuario la información de los personajes y guardarla en dicho fichero. 

Los datos que incluye son:
	o Nombre
	o Clase del personaje (Únicamente pueden ser de los tipos: guerrero, mago, arquero, paladín y rogue)	
	o Nivel
	o Vida
	o Poder de ataque
	o Capacidad de defensa
	o Habilidad de magia

El formato del fichero:

En el caso de que no exista se debe pedir al usuario la información de los personajes y guardarla en dicho fichero. 

Por cada línea, se tienen los datos de un personaje:
	
	Se debe mostrar por pantalla todos los personajes leídos del fichero, la media de los niveles y se
	deben guardar en un fichero aquellos personajes cuyo nivel sea mayor que 7.


RECOMENDACIONES E INDICACIONES PARA LA ENTREGA

En este ejercicio está permitido usar funciones derivadas de la librería <string.h>
- En concreto funciones:
o int strcmp(const char *s1, const char *s2);
o size_t strlen(const char *s);
o char *strcpy(char *dest, const char *orig);
o size_t strcspn(const char *s, const char *reject);
o char *strcat(char *dest, const char *src);
o char *strstr(const char *haystack, const char *needle);
o char *strtok(char *string1, const char *string2);

Se pueden usar el resto de las funciones vistas en los temas 1 , 2 , 3 y 4, incluidas en <stdlib.h> y <stdio.h>
- atoi, atof,strtol,strtof,malloc, realloc,free, etc...

• Claridad en el código:
Asegúrate de que tu código sea claro y esté bien estructurado. Sigue las buenas prácticas de programación,
como el uso de indentaciones y comentarios, para facilitar su lectura y comprensión.

• Uso de identificadores descriptivos:
En la implementación en C, utiliza nombres de variables que describan claramente su propósito (por ejemplo,
exponente en lugar de solo exp).

• Revisa los datos de entrada:
Antes de implementar los algoritmos en C, verifica que tienes claro cuáles son los posibles datos que un
usuario puede introducir en tu programa y asegúrate de que no da errores al introducir datos no admitidas
como letras cuando se soliciten números

*/

//Sergio Garcia Gordo 1ºINSD

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
	GUERRERO,
	MAGO,
	ARQUERO,
	PALADIN,
	ROGUE,
	INVALID_CLASS
}Clase_e;

typedef struct {
	//char *nombre;
	char nombre[150];
	Clase_e clase; 
	int nivel;
	int vida;
	int poder_ataque;
	int capacidad_defensa;
	int habilidad_magia;
}Personaje_t;

//Creamos funciones diferentes para cada objetivo, para tratarlas mejor.
Clase_e convierteStringEnum(char *clase);
char *convierteEnumString(Clase_e clase);
char *leerLineaDinamica(char *nombre);
void creaFichero();
void insertaDatos(Personaje_t personaje);
void leerDatos();
void insertaPersonajesFiltrados(Personaje_t personaje);
void leerDatosFiltrados();

int main(int argc, char *argv []){
	
	Personaje_t personaje;
	int contador = 1;
	
	//Control de argumentos pasados por CLI
	if(argc != 2){
		printf("Numero de parametros invalido (> o < a 2)\n");
		return 0;
	}
	
	//Creamos memoria para almacenar en un buffer todo argv[1] ("Sergio,Mago,10,20,30,40,50")
	char *buffer = (char*)malloc(strlen(argv[1]) + 1);
	strcpy(buffer, argv[1]);
	
	//Creamos un espacio en memoria de tipo *char para "trocear" lo copiado en el buffer, separando por comas
	char *token = strtok(buffer, ",");
	
	//Mientras que haya otro "trozo" (valor) en nuestro buffer
	while(token != NULL){ 
			
		switch(contador){
			
			case 1: {
				
				//personaje.nombre = leerLineaDinamica(token);
				//personaje.nombre = (char*)malloc(sizeof(char) * strlen(token) + 1);
				strcpy(personaje.nombre, token);
				break;
			}
			
			case 2: {
				
				char *clasePersonaje = token; 
				//Hacemos que la clase sea lo obtenido a traves de meter en la func convierteStringEnum la enum
				personaje.clase = convierteStringEnum(clasePersonaje);
				if(personaje.clase == INVALID_CLASS){
					printf("Clase del personaje invalida\n");
					return 0;
				}
				break;
			}
			
			case 3: {
				
				//Convertimos en interger ascii-to-integer el token de la posicion 3
				personaje.nivel = atoi(token); 
				break;
				
			}

			case 4: {
				
				personaje.vida = atoi(token);
				break;
				
			}
			
			case 5: {
				
				personaje.poder_ataque = atoi(token);
				break;
				
			}
			
			case 6: {
				
				personaje.capacidad_defensa = atoi(token);
				break;
				
			}
			
			case 7: {
				
				personaje.habilidad_magia = atoi(token);
				break;	
				
			}
			
			default: {
				
				printf("Error al darle valor a los parametros\n");
				return 0;
				
			}
			
		}
		
		//Actualizamos el token pasandole null
		token = strtok(NULL, ","); 
		contador++; //Aumento de contador para el switch case
	}
	
	//Funciones de insercion y lectura de ficheros
	creaFichero();
	insertaDatos(personaje);
	leerDatos();
	leerDatosFiltrados();
		
	//free(personaje.nombre);
	free(buffer);
	
	return 0;
}

Clase_e convierteStringEnum(char *clase){
	
	//Compara la clase con un string (char) y devuelve una enum (int)
	if (strcmp(clase, "guerrero") == 0 || strcmp(clase, "Guerrero") == 0 || strcmp(clase, "GUERRERO") == 0) return GUERRERO;
	else if (strcmp(clase, "mago") == 0 || strcmp(clase, "Mago") == 0 || strcmp(clase, "MAGO") == 0) return MAGO;
	else if (strcmp(clase, "arquero") == 0 || strcmp(clase, "Arquero") == 0 || strcmp(clase, "ARQUERO") == 0) return ARQUERO;
	else if (strcmp(clase, "paladin") == 0 || strcmp(clase, "Paladin") == 0 || strcmp(clase, "PALADIN") == 0) return PALADIN;
	else if (strcmp(clase, "rogue") == 0 || strcmp(clase, "Rogue") == 0 || strcmp(clase, "ROGUE") == 0) return ROGUE;
	else return INVALID_CLASS;

}

char *convierteEnumString(Clase_e clase){
		
	//Formateamos el integer de la ENUM en palabras legibles
	switch(clase){
		case GUERRERO: return "Guerrero";
		case MAGO: return "Mago";
		case ARQUERO: return "Arquero";
		case PALADIN: return "Paladin";
		case ROGUE: return "Rogue";
		case INVALID_CLASS: return "Clase invalida";
	}
	
}


void creaFichero(){
	
	FILE *fichero = fopen("personajes.txt", "r");
	
	//Inefeciente, pero abrimos primeramente en modo lectura, para que si falla, se cree.
	if(fichero == NULL){
		fichero = fopen("personajes.txt", "w");
		printf("Fichero creado con exito\n");
	}
		
	fclose(fichero);
}

void insertaDatos(Personaje_t personaje){
	
	FILE *fichero = fopen("personajes.txt", "a");
	
	if(fichero == NULL){
		printf("Error, no se pudo escribir en el archivo\n");
	}else{
		//Insertamos valores con un salto de linea para su correcta indentacion
		fprintf(fichero, "%s %d %d %d %d %d %d\n", personaje.nombre, personaje.clase, personaje.nivel,
		personaje.vida, personaje.poder_ataque, personaje.capacidad_defensa, personaje.habilidad_magia);
	}
	
	fclose(fichero);
}

void leerDatos(){
	
	FILE *fichero = fopen("personajes.txt", "r");
	Personaje_t personaje;
	
	if (fichero == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return; 
    }	
	
	printf("Lista de personajes: \n");
	
	float mediaNivel = 0;
	int contador = 0;
	
	while(fscanf(fichero, "%s %d %d %d %d %d %d", 
		  personaje.nombre, &personaje.clase, &personaje.nivel, &personaje.vida, 
		  &personaje.poder_ataque, &personaje.capacidad_defensa, &personaje.habilidad_magia) == 7){
		
		//Mostramos los personajes encontrados. La clase la convertimos en una palabra legible en el momento de mostrarlos
		printf("Nombre: %s, Clase: %s, Nivel: %d, HP: %d, ATK: %d, DEF: %d, MAG: %d\n",
			personaje.nombre, convierteEnumString(personaje.clase), personaje.nivel,
			personaje.vida, personaje.poder_ataque, personaje.capacidad_defensa, 
			personaje.habilidad_magia);
		
		//Media de nivel
		mediaNivel += personaje.nivel; 
		contador++;
	}
	
	//Pasamos el personaje x cuyo nivel > 7
	if(personaje.nivel>7){
		insertaPersonajesFiltrados(personaje);
	}
	
	float mediaNivelResult = mediaNivel/contador;
	printf("--------------------------------------\n");
	printf("Estadistica de los personajes:\n");
	printf("Media de nivel de todos los personajes: %.2f\n", mediaNivelResult);
	
	fclose(fichero);
}


void insertaPersonajesFiltrados(Personaje_t personaje){
	
	//Lo abrimos en a+ para que añada al final y ademas lo lea
	FILE *ficheroPersonajesFiltrados = fopen("personajesFiltrados.txt", "a+");
	
	if(ficheroPersonajesFiltrados == NULL){
		printf("Error: no se pudo abrir o crear el archivo.\n");
		return;
	}
	
	//Escribimos el personaje nivel > 7
	fprintf(ficheroPersonajesFiltrados, "%s %d %d %d %d %d %d\n", 
	personaje.nombre, personaje.clase, personaje.nivel, personaje.vida,
	personaje.poder_ataque, personaje.capacidad_defensa, personaje.habilidad_magia);
		
	fclose(ficheroPersonajesFiltrados);
}

void leerDatosFiltrados(){
	
	FILE *ficheroPersonajesFiltrados = fopen("personajesFiltrados.txt", "r");
	Personaje_t personaje;
	
	printf("---------------------------------------------------------\n");
	if(ficheroPersonajesFiltrados == NULL){
		printf("Error, el archivo de personajes filtrados por nivel no existe (no se ha insertado personaje con nivel > 7)\n");
		return;
	}
	
	printf("Personajes filtrados:\n");
	while(fscanf(ficheroPersonajesFiltrados, "%s %d %d %d %d %d %d", 
	personaje.nombre, &personaje.clase, &personaje.nivel, &personaje.vida, &personaje.poder_ataque, &personaje.capacidad_defensa, &personaje.habilidad_magia) == 7){
	
	printf("Nombre: %s, Clase: %s, Nivel: %d, HP: %d, ATK: %d, DEF: %d, MAG: %d\n",
			personaje.nombre, convierteEnumString(personaje.clase), personaje.nivel,
			personaje.vida, personaje.poder_ataque, personaje.capacidad_defensa, 
			personaje.habilidad_magia);	
	}
	
	fclose(ficheroPersonajesFiltrados);
	
}


/*char *leerLineaDinamica(char *nombre){ 
	printf("Nombre -> %s\n", nombre);

	char *linea = (char*)malloc(sizeof(char)*1);
	if(linea == NULL){
		printf("Error de asignacion de memoria en el nombre \n");
		return 0;
	}

	int tamano = 1;
	int numeroLetras = 0;
	char c = 0;
	
	while((c = getchar()) != '\n'){
		linea[numeroLetras] = c;
		tamano++;
		numeroLetras++;
		
		linea = (char*)realloc(linea,tamano);
	}
	
	linea[numeroLetras] = '\0';	
	return linea;
	
}

	He tratado de hacer que el nombre sea dinamico con linea dinamica, pero si se introduce Juan Manuel por ej el programa
	va a entender argv[0] = nombreProg, argv[1] = Juan, argv[2] = Manuel, argv[3] = el resto -> Numero de parametros invalido > 2
	ya que en la practica no hay un ejemplo de modelo de datos de entrada del usuario por argc/argv. Se que es propenso a errores con nombres que 
	sobrepasen el limite permitido, pero es lo que he podido hacer.

*/