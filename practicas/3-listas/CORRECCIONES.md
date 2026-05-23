# Correcciones — Práctica 3: TAD Lista

**Fecha de corrección:** 2026-05-23
**Referencia evaluada:** `origin/main` (commit `79baa66`)
**Repositorio:** `https://github.com/valentinolavigna/EDA1`

> **Nota sobre la referencia evaluada:** el equipo **no creó ningún tag** para la entrega de la práctica `3-listas`. Por
> indicación del docente, se evaluó la última versión disponible en `origin/main`. El repositorio se dejó en detached
> HEAD sobre `origin/main` durante la corrección.

---

## Integrantes del equipo

Integrantes declarados en el `README.md` de la raíz:

- Valentino Lavigna Jara
- Andoni Gallego
- Ignacio Walsh

Contribuciones dentro del alcance de la práctica (`practicas/3-listas/` y `tads/listas/`):

| Integrante (README)    | Líneas aportadas (+/-) | % estimado por líneas | Commits (referencia) | Committers unificados  |
|------------------------|------------------------|-----------------------|----------------------|------------------------|
| Valentino Lavigna Jara | — (solo "Initial commit" con template) | — | 1 (template) | Valentino Lavigna Jara |
| Andoni Gallego         | 0                      | 0%                    | 0                    | —                      |
| Ignacio Walsh          | 0                      | 0%                    | 0                    | —                      |

Observaciones:

- Ningún integrante realizó commits con código propio sobre la práctica 3. El único commit que toca el alcance es
  `d1f593a Initial commit`, que corresponde al template provisto por la cátedra.
- A nivel repositorio (global, fuera de esta práctica) los tres integrantes aparecen como committers en otras prácticas;
  para la práctica 3 específicamente, las contribuciones son nulas.

---

## Método aplicado

- Tests del grupo: No ejecutados (todos los `main()` están vacíos: solo `imprimir_titulo(...)` y `return 0`).
- Tests de cátedra: No ejecutados (no aplica: las implementaciones del TAD y de los ejercicios están vacías y no
  retornan valor, por lo que ningún test podría correr).
- Revisión estática del código: Sí.
- Evidencia breve:
    - `git checkout origin/main` (detached HEAD en `79baa66`).
    - `git log -- practicas/3-listas/ tads/listas/` → un único commit (`d1f593a Initial commit`).
    - Inspección de los tres `tads/listas/*.c`, de `practicas/3-listas/practica_listas.c` y de cada test bajo
      `practicas/3-listas/tests/`.
    - `git diff d1f593a HEAD -- tads/listas/*.h practicas/3-listas/practica_listas.h` → sin diferencias.

---

## Implementación del TAD Lista (Ejercicio 1)

Las tres implementaciones esperadas existen como **archivos**, pero todas sus operaciones núcleo están vacías (sin
`return`, sin lógica). Solo `l_to_string` tiene cuerpo (provisto por el template). El iterador completo está vacío en
las tres representaciones.

### `tads/listas/listas_arreglos.c` — Estado: 🚫 NO IMPLEMENTADO

Todas las operaciones son stubs con cuerpo vacío:

- `l_crear`, `l_es_vacia`, `l_es_llena`, `l_longitud`, `l_agregar`, `l_borrar`, `l_buscar`, `l_insertar`, `l_eliminar`,
  `l_recuperar`, `l_mostrar`: cuerpo vacío. Funciones declaradas como retornando `Lista`/`bool`/`int`/`TipoElemento` sin
  `return`: comportamiento indefinido si se invocan.
- Iterador: `iterador`, `hay_siguiente`, `siguiente`: cuerpo vacío.
- `l_to_string`: implementación provista por el template (recorre `lista->valores[i]->clave`); no es trabajo del grupo.

No es posible usar esta implementación.

### `tads/listas/listas_punteros.c` — Estado: 🚫 NO IMPLEMENTADO

Mismo diagnóstico que arreglos:

- Todas las operaciones del TAD (`l_crear` … `l_mostrar`) están vacías.
- Iterador: `iterador`, `hay_siguiente`, `siguiente` vacíos.
- `l_to_string`: provista por el template (recorre `inicio->siguiente`).

No es posible usar esta implementación.

### `tads/listas/listas_cursores.c` — Estado: 🚫 NO IMPLEMENTADO

- Todas las operaciones del TAD vacías.
- Iterador vacío.
- `l_to_string`: provista por el template (recorre el arreglo de cursores desde `inicio`).
- No se inicializa la lista de slots libres (`libre`) ni se mantiene en ninguna parte.

No es posible usar esta implementación.

### Sobre los archivos de cátedra

- `tads/listas/listas.h`, `tads/listas/util_listas.h` y `practicas/3-listas/practica_listas.h` están **idénticos** al
  commit base (template de cátedra). No se modificaron, lo que es correcto.

---

## Resolución de ejercicios

Todos los ejercicios del 2 al 13 están definidos como prototipos en `practica_listas.h`. En `practica_listas.c` el
grupo solo dejó definidas (vacías) las funciones `invertirListaRec`, `invertirLista`, `evaluar` y `valores`. El resto
de los ejercicios (`menorYPosicion`, `mayorYOcurrencias`, `promedio`, `multiplos`, `numerosAlAzar`, `reflejarLista`,
`listaEsMultiplo`, `compararListas`, `subLista`, `subConjuntosQueSumanN`) **no aparecen ni siquiera como stubs** en
`practica_listas.c`: faltan sus definiciones por completo. Esto haría fallar la compilación del módulo si se intentara
enlazar contra los tests.

No hay análisis de complejidad (ni para TAD ideal ni para TAD real) en ninguna parte del repo para esta práctica.

### Ejercicio 2 — `invertirLista`

**Estado: 🚫 NO IMPLEMENTADO**

- Modalidad entregada: no determinable. Existen dos firmas vacías en `practica_listas.c`: `invertirListaRec(Iterador)` y
  `invertirLista(Lista)`. Ambas con cuerpo vacío y sin `return`.
- Implementación revisada: no hay código.
- Análisis de complejidad (TAD ideal): no entregado.
- Análisis de complejidad (TAD real): no entregado.
- Casos borde: no cubiertos (no hay implementación).

### Ejercicio 3 — `menorYPosicion`

**Estado: 🚫 NO IMPLEMENTADO**

- No existe definición de la función en `practica_listas.c` (solo el prototipo en `.h`). El módulo no compilaría.

### Ejercicio 4 — `mayorYOcurrencias`

**Estado: 🚫 NO IMPLEMENTADO**

- No existe definición de la función en `practica_listas.c`.

### Ejercicio 5 — `promedio`

**Estado: 🚫 NO IMPLEMENTADO**

- No existe definición de la función en `practica_listas.c`.

### Ejercicio 6 — `multiplos`

**Estado: 🚫 NO IMPLEMENTADO**

- No existe definición de la función en `practica_listas.c`.

### Ejercicio 7 — `numerosAlAzar`

**Estado: 🚫 NO IMPLEMENTADO**

- No existe definición de la función en `practica_listas.c`.

### Ejercicio 8 — `reflejarLista`

**Estado: 🚫 NO IMPLEMENTADO**

- No existe definición de la función en `practica_listas.c`.

### Ejercicio 9 — `listaEsMultiplo`

**Estado: 🚫 NO IMPLEMENTADO**

- No existe definición de la función en `practica_listas.c`.

### Ejercicio 10 — `compararListas`

**Estado: 🚫 NO IMPLEMENTADO**

- No existe definición de la función en `practica_listas.c`.

### Ejercicio 11 — `evaluar` y `valores` (TAD Polinomio)

**Estado: 🚫 NO IMPLEMENTADO**

- Modalidad entregada: no determinable. Las funciones `evaluar(struct Polinomio, double)` y
  `valores(struct Polinomio, int, int, double)` existen en `practica_listas.c` pero con cuerpo vacío y sin `return`.
- Implementación revisada: no hay lógica.
- Casos borde: no cubiertos. Tampoco se valida `paso = 0`.

### Ejercicio 12 — `subLista`

**Estado: 🚫 NO IMPLEMENTADO**

- Ejercicio opcional. No existe definición de la función en `practica_listas.c`. Tampoco se registra intención de
  abordarlo.

### Ejercicio 13 — `subConjuntosQueSumanN`

**Estado: 🚫 NO IMPLEMENTADO**

- Ejercicio opcional. No existe definición de la función en `practica_listas.c`.

---

## Revisión de tests

Todos los archivos de test existen pero solo contienen `imprimir_titulo("…")` y `return 0`. Ninguno crea listas, ni
invoca funciones de la práctica, ni hace `assert`.

| Test                                  | Estado          | Observaciones                                                                                                            |
|---------------------------------------|-----------------|--------------------------------------------------------------------------------------------------------------------------|
| `test_invertir_lista.c`               | 🚫 No entregado | `main` vacío.                                                                                                            |
| `test_menor_datos.c`                  | 🚫 No entregado | `main` vacío.                                                                                                            |
| `test_dato_maximo.c`                  | 🚫 No entregado | `main` vacío.                                                                                                            |
| `test_promedio_lista.c`               | 🚫 No entregado | `main` vacío.                                                                                                            |
| `test_lista_multiplo_escalar.c`       | 🚫 No entregado | `main` vacío.                                                                                                            |
| `test_lista_azar.c`                   | 🚫 No entregado | `main` vacío.                                                                                                            |
| `test_lista_reflejada.c`              | 🚫 No entregado | `main` vacío.                                                                                                            |
| `test_lista_es_multiplo.c`            | 🚫 No entregado | `main` vacío.                                                                                                            |
| `test_comparacion_de_listas.c`        | 🚫 No entregado | `main` vacío.                                                                                                            |
| `test_polinomio.c`                    | 🚫 No entregado | Solo trae helpers `compararPuntoXY`, `toStringPuntoXY`, `crear_lista_puntos_desde_array` del template; `main` sin pruebas.|
| `test_sublistas.c`                    | 🚫 No entregado | `main` vacío. (Ejercicio opcional.)                                                                                      |
| `test_subconjuntos_suman_n.c`         | 🚫 No entregado | `main` vacío. (Ejercicio opcional.)                                                                                      |

### Tests con casos de borde faltantes

No aplica detallar casos faltantes: ningún test ejercita la práctica.

---

## Resumen

| Categoría                                | Estado                       |
|------------------------------------------|------------------------------|
| Archivos `.h` sin modificar (contenido)  | ✅ Idénticos al commit base   |
| TAD Lista — `listas_arreglos.c`          | 🚫 No implementado            |
| TAD Lista — `listas_punteros.c`          | 🚫 No implementado            |
| TAD Lista — `listas_cursores.c`          | 🚫 No implementado            |
| Ejercicio 2 — `invertirLista`            | 🚫 No implementado            |
| Ejercicio 3 — `menorYPosicion`           | 🚫 No implementado            |
| Ejercicio 4 — `mayorYOcurrencias`        | 🚫 No implementado            |
| Ejercicio 5 — `promedio`                 | 🚫 No implementado            |
| Ejercicio 6 — `multiplos`                | 🚫 No implementado            |
| Ejercicio 7 — `numerosAlAzar`            | 🚫 No implementado            |
| Ejercicio 8 — `reflejarLista`            | 🚫 No implementado            |
| Ejercicio 9 — `listaEsMultiplo`          | 🚫 No implementado            |
| Ejercicio 10 — `compararListas`          | 🚫 No implementado            |
| Ejercicio 11 — `evaluar` / `valores`     | 🚫 No implementado            |
| Ejercicio 12 — `subLista` (opcional)     | 🚫 No implementado            |
| Ejercicio 13 — `subConjuntosQueSumanN` (opcional) | 🚫 No implementado   |
| Ejercicios correctos                     | 0 de 12 correctos; 0 con advertencias; 0 incorrectos; 12 no implementados (incluye los 2 opcionales) |
| Tests entregados                         | 0 de 12                       |
| Tests con buena cobertura                | 0 de 12                       |

**Observación general:** la práctica 3 (`3-listas`) no fue trabajada. El único commit que toca el alcance es el
"Initial commit" con el template de cátedra. Ni el TAD (en sus tres representaciones) ni los ejercicios 2 a 13 ni los
tests fueron implementados. Los `.h` de cátedra están intactos, lo cual es correcto, pero no hay nada para evaluar
funcionalmente.
