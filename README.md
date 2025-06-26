# 🕹️ Proyecto en C: Administración de Personajes de un Videojuego

## 📘 ¿De qué trata este proyecto?

La idea es simple: queremos tener un programa en C que nos permita gestionar los personajes de un videojuego. Es como si tuviéramos una pequeña base de datos de nuestros héroes, con sus estadísticas y habilidades, pero en lugar de usar algo complejo como SQL, lo haremos todo desde archivos de texto y usando estructuras en C.

---

## 🧠 ¿Cómo funciona?

Cuando ejecutas el programa, lo primero que hace es buscar un archivo con los personajes. Si ese archivo **ya existe**, el programa simplemente lo lee y te muestra toda la información: los nombres, clases, niveles, vida, etc.

Pero si ese archivo **no existe**, el programa asume que estás empezando desde cero. Entonces te pide que ingreses los datos de tus personajes a mano (nombre, clase, nivel, etc.) y luego los guarda en un archivo para que la próxima vez ya estén disponibles.

Después de tener la lista de personajes cargada, el programa hace un par de cosas más:

1. **Calcula la media de los niveles** de todos los personajes.
2. Crea un nuevo archivo aparte con solo los personajes que tienen un nivel **mayor a 7** (es decir, los que ya están más fuertes).

---

## 👾 ¿Qué datos tiene cada personaje?

A cada personaje le vamos a guardar lo siguiente:

- Nombre
- Clase (pero ojo, solo puede ser una de estas: `guerrero`, `mago`, `arquero`, `paladín` o `rogue`)
- Nivel
- Vida
- Poder de ataque
- Defensa
- Magia



