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
	char nombre[50];
	Clase_e clase; 
	int nivel;
	int vida;
	int poder_ataque;
	int capacidad_defensa;
	int habilidad_magia;
}Personaje_t;

Clase_e convierteStringEnum(char *clase);
char *convierteEnumString(Clase_e clase);
char *leerLineaDinamica(char *nombre);

int main(int argc, char *argv []){
	
	Personaje_t personaje;
	int contador = 1;
	
	if(argc != 2){
		printf("Numero de parametros invalido (> o < a 2)\n");
		return 0;
	}
	
	char *buffer = (char*)malloc(strlen(argv[1]) + 1);
	strcpy(buffer, argv[1]);
	
	char *token = strtok(buffer, ",");
	
	printf("---------------------------------\n");
	while(token != NULL){
			
		switch(contador){
			
			case 1: {
				strcpy(personaje.nombre, "Sergio");
				printf("Nombre: %s\n", personaje.nombre);
				break;
			}
			
			case 2: {
				char *clasePersonaje = token;
				personaje.clase = convierteStringEnum(clasePersonaje);	
				if(personaje.clase == INVALID_CLASS){
					printf("Clase del personaje invalida\n");
					return 0;
				}
				printf("Clase: %s \n", convierteEnumString(personaje.clase));
				break;
			}
			
			case 3: {
				personaje.nivel = atoi(token);
				printf("Nivel: %d \n", personaje.nivel);
				break;
			}

			case 4: {
				personaje.vida = atoi(token);
				printf("Vida: %d \n", personaje.vida);
				break;
			}
			
			case 5: {
				personaje.poder_ataque = atoi(token);
				printf("Ataque: %d \n", personaje.poder_ataque);
				break;
			}
			
			case 6: {
				personaje.capacidad_defensa = atoi(token);
				printf("Defensa: %d \n", personaje.capacidad_defensa);
				break;
			}
			
			case 7: {
				personaje.habilidad_magia = atoi(argv[7]);
				printf("Habilidad magia: %d", personaje.habilidad_magia);
				break;	
			}
			
			default: {
				printf("Error al darle valor a los parametros\n");
				return 0;
			}
		}
		
		token = strtok(NULL, ",");
		contador++;
	}
	
	//Damos valores a los campos de la estructura personaje
	/*char *nombre = argv[1]; //IMPLEMENTAR LINEA DINAMICA
	char *nombre = leerLineaDinamica(argv[1]);
	
	strcpy(personaje.nombre, nombre);
	*/
	
	return 0;
}

Clase_e convierteStringEnum(char *clase){
	
	if (strcmp(clase, "guerrero") == 0 || strcmp(clase, "Guerrero") == 0 || strcmp(clase, "GUERRERO") == 0) return GUERRERO;
	else if (strcmp(clase, "mago") == 0 || strcmp(clase, "Mago") == 0 || strcmp(clase, "MAGO") == 0) return MAGO;
	else if (strcmp(clase, "arquero") == 0 || strcmp(clase, "Arquero") == 0 || strcmp(clase, "ARQUERO") == 0) return ARQUERO;
	else if (strcmp(clase, "paladin") == 0 || strcmp(clase, "Paladin") == 0 || strcmp(clase, "PALADIN") == 0) return PALADIN;
	else if (strcmp(clase, "rogue") == 0 || strcmp(clase, "Rogue") == 0 || strcmp(clase, "ROGUE") == 0) return ROGUE;
	else return INVALID_CLASS;

}

char *convierteEnumString(Clase_e clase){
	
	switch(clase){
		case GUERRERO: return "Guerrero";
		case MAGO: return "Mago";
		case ARQUERO: return "Arquero";
		case PALADIN: return "Paladin";
		case ROGUE: return "Rogue";
		case INVALID_CLASS: return "Clase invalida";
	}
	
}

/*char *leerLineaDinamica(char *nombre){
	
	char *nombrePersonaje = malloc(sizeof(char) * 1);
	int tamano = 1;
	int contadorLetras = 0;
	char c = 0;
	
	while((c == getchar()) != '\n'){
		nombrePersonaje[contadorLetras] = c;
		tamano++;
		contadorLetras++;
		nombrePersonaje = realloc(nombrePersonaje, tamano);
	}
	
	nombrePersonaje[numLetras] = '\0';
	
	//strcpy(nombrePersonaje, nombre);
	//printf("Nombre: %s \n", nombre);
	return nombre;
	
}*/
