# Traductor de Python a C++ (Proyecto Incompleto)

Este repositorio contiene el código fuente de un proyecto cuyo objetivo era desarrollar un traductor de código de Python a C++ utilizando análisis sintáctico, léxico y semántico implementado en C++. Debido a limitaciones de tiempo, el proyecto no fue terminado.

---

## Índice

- [Objetivo](#objetivo)
- [Tecnologías Utilizadas](#tecnologías-utilizadas)
- [Arquitectura del Proyecto](#arquitectura-del-proyecto)
- [Estado Actual](#estado-actual)

---

## Objetivo

El objetivo del proyecto era desarrollar un traductor automatizado capaz de convertir código escrito en Python a un código equivalente en C++ a partir de los siguientes componentes:
  
- **Análisis Léxico:** Lectura y tokenización del código Python.
- **Análisis Sintáctico:** Construcción del árbol de sintaxis abstracta (AST).
- **Análisis Semántico:** Verificación y traducción de la semántica del lenguaje a estructuras equivalentes en C++.

El proyecto fue diseñado para facilitar la migración de proyectos Python a C++ manteniendo la estructura y lógica original.

---

## Tecnologías Utilizadas

- **Lenguaje Principal:** C++
- **Paradigma de Análisis:** 
  - Análisis Léxico
  - Análisis Sintáctico
  - Análisis Semántico

---

## Arquitectura del Proyecto

El proyecto se estructuró en varios módulos:

- **Lexer:** Encargado de convertir el código Python en una secuencia de tokens.
- **Parser:** Utiliza los tokens para construir un árbol de sintaxis abstracta, siguiendo las reglas gramaticales definidas.
- **Analizador Semántico:** Recorre el AST para verificar la semántica del código original y asegurar que la conversión respete la lógica y operatividad del código fuente. (Incompleto)
- **Generador de Código:** Traduce el árbol y las estructuras semánticas a código C++. (Incompleto)

Cada uno de estos módulos fue diseñado para trabajar de forma conjunta, permitiendo un flujo de traducción que abarca desde la entrada de código Python hasta la salida del código en C++.

---

## Estado Actual

El proyecto se encuentra **incompleto**.

---
