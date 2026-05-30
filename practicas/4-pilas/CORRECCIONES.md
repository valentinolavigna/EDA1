# Correcciones — Práctica 4: TAD Pila

**Fecha de corrección:** 2026-05-30
**Referencia evaluada:** tag `TP-pilas` (commit `773509d`)
**Repositorio:** `https://github.com/valentinolavigna/EDA1`

---

## Integrantes del equipo

Integrantes declarados en `README.md` de la raíz: **Valentino Lavigna Jara**, **Andoni Gallego**, **Ignacio Walsh**.

| Integrante (README) | Líneas aportadas (+/-) | % estimado por líneas | Commits (referencia) | Committers unificados |
|---------------------|------------------------|-----------------------|----------------------|------------------------|
| Valentino Lavigna Jara | +533/-0 | 70.41% | 1 | `Valentino Lavigna Jara` |
| Ignacio Walsh | +223/-1 | 29.59% | 1 | `Walsh97` (`Ignacio Walsh`) |
| Andoni Gallego | 0 | 0% | 0 | — (sin commits en el alcance) |

Observaciones sobre la métrica (es un **estimado** y conviene leerlo con cuidado):

- El alcance medido es `practicas/4-pilas/` + `tads/pilas/`.
- El aporte de **Valentino Lavigna Jara** (+533) corresponde casi por completo al **commit inicial** que importó el
  template de cátedra (no a resolución de ejercicios).
- La **única edición sustantiva** del alcance es `practica_pilas.c`, hecha por **Ignacio Walsh** (`Update practica_pilas.c`).
- **Andoni Gallego** no registra commits en el alcance evaluado.

---

## Método aplicado

- Tests del grupo: **No ejecutados**.
- Tests de cátedra: **No ejecutados**.
- Revisión estática del código: **Sí**.
- Evidencia breve: el TAD Pila (`pilas_arreglos.c` y `pilas_punteros.c`) tiene sus operaciones núcleo **vacías**
  (idénticas al template), por lo que el proyecto no puede ejecutarse ni testearse: cualquier llamada a `p_crear` /
  `p_apilar` / `p_desapilar` devuelve basura y rompe en tiempo de ejecución. Además, los 12 tests de
  `practicas/4-pilas/tests/` son stubs vacíos (solo imprimen el título). La corrección de los ejercicios se hizo por
  **revisión estática**, asumiendo un TAD Pila correcto. Comandos usados: `git diff d1f593a HEAD -- tads/pilas/...`,
  lectura de `practica_pilas.c` y headers de cátedra.

Verificación de archivos de cátedra (`.h`): los headers `pilas.h`, `util_pilas.h`, `aserciones_pilas.h` y
`practica_pilas.h` son **idénticos** al commit base (template). No hay modificaciones de cátedra. ✅

---

## Implementación del TAD Pila

> Nota crítica: ambos archivos de implementación del TAD son **idénticos al commit inicial del repositorio** (template
> de cátedra). El grupo **no implementó ninguna de las dos representaciones**. Solo `p_to_string` viene resuelta (y es
> parte del template, accede a la representación interna porque es el propio TAD). Sin el TAD implementado, los
> ejercicios de la práctica no pueden compilarse/ejecutarse de forma útil.

### `pilas_arreglos.c` — Estado: 🚫 NO IMPLEMENTADO

- Operaciones vacías (stub sin cuerpo): `p_crear`, `p_apilar`, `p_desapilar`, `p_tope`, `p_es_vacia`, `p_es_llena`,
  `p_mostrar`.
- `p_crear`, `p_apilar`, `p_desapilar`, `p_tope`, `p_es_vacia`, `p_es_llena` con tipo de retorno no-`void` y **sin
  `return`**: comportamiento indefinido al usarse.
- Único cuerpo presente: `p_to_string` (proviene del template).

### `pilas_punteros.c` — Estado: 🚫 NO IMPLEMENTADO

- Operaciones vacías (stub sin cuerpo): `p_crear`, `p_apilar`, `p_desapilar`, `p_tope`, `p_es_vacia`, `p_es_llena`,
  `p_mostrar`.
- Únicos cuerpos presentes: `p_longitud` (rutina interna del template) y `p_to_string` (template).

---

## Resolución de ejercicios

> Criterio transversal aplicado: el enunciado pide explícitamente **analizar la complejidad algorítmica** de las
> soluciones (iterativa/recursiva). El grupo **no presentó análisis de complejidad en ningún ejercicio** ni resolvió
> versiones recursivas. Por eso, los ejercicios algorítmicamente correctos cuyo **único** déficit es la ausencia del
> análisis requerido quedan en ⚠️ **ADVERTENCIA** (el algoritmo es correcto; falta el entregable de análisis). En cada
> ejercicio se indica la complejidad que correspondería.

### Ejercicio 1 — `buscarElemento`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: vacía la pila hacia una auxiliar comparando `clave`, y luego restaura. Lógica **correcta**.
- Preserva la pila original: **sí** (la restaura desde la auxiliar).
- Análisis de complejidad: **no presentado**. Correspondería O(n) (un recorrido completo desapilando/apilando, cada
  operación del TAD O(1)).
- Casos borde: pila vacía (devuelve `false`, correcto); clave en tope/base/inexistente: bien.
- Sugerencias: podría cortar antes al encontrar el elemento, aunque igual debe restaurar; nombrar la auxiliar de forma
  descriptiva.

### Ejercicio 2 — `insertarElemento`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: mueve `pos-1` elementos del tope a una auxiliar, apila `e` y restaura. Inserta en la
  posición `pos` **contada desde el tope** (1-indexada). Coherente con el enunciado ("se empieza a contar desde el
  tope"). Modifica in place. **Correcto**.
- Análisis de complejidad: **no presentado**. Correspondería O(n).
- Casos borde: `pos = 1` apila en el tope (bien); `pos` mayor a la cantidad: inserta en la base (comportamiento
  razonable). No valida `pos <= 0`.

### Ejercicio 3 — `eliminarElemento`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: elimina la **primera ocurrencia** (desde el tope) de `clave` y restaura el resto. Coincide
  con el enunciado ("primera ocurrencia encontrada"). Modifica in place, preserva el orden del resto. **Correcto**.
- Análisis de complejidad: **no presentado**. Correspondería O(n).
- Casos borde: clave inexistente (no cambia la pila, bien); clave en tope/base: bien.
- Sugerencias: el `TipoElemento` eliminado **no se libera** (`free`), queda un leak menor del elemento removido.
  Conviene `free(te)` del elemento descartado.

### Ejercicio 4 — `intercambiarElementos`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: vuelca toda la pila a un arreglo local `TipoElemento elementos[1000]`, intercambia
  `pos1`/`pos2` (1-indexadas desde el tope) y reconstruye. Para posiciones válidas el resultado es **correcto** y
  preserva el orden. Usa solo operaciones del TAD para la pila (el arreglo es scratch local; no rompe la abstracción).
- Análisis de complejidad: **no presentado**. Correspondería O(n).
- Casos borde / problema real: **no valida el rango** de `pos1`/`pos2`. Con posiciones fuera de `[1, n]` accede al
  arreglo fuera de límites (comportamiento indefinido). Debería validar contra `contarElementos(p)`.
- Sugerencias: resolver con pila auxiliar en vez de arreglo fijo de 1000 mantiene mejor el espíritu del TP.

### Ejercicio 5 — `copiar`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: invierte a una auxiliar y reconstruye apilando a la vez en `p` (restaurando) y en `copia`.
  La copia queda en el **mismo orden** que el original. **Correcto**.
- Preserva la pila original: **sí**.
- Análisis de complejidad: **no presentado**. Correspondería O(n).
- Sugerencias: la copia comparte los mismos punteros `TipoElemento` que el original (copia superficial); si luego se
  destruyen ambas pilas con `destruir_pila`, habría doble `free`. Documentar/clonar el `TipoElemento` si se espera
  independencia total.

### Ejercicio 6 — `contarElementos`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: cuenta vaciando a una auxiliar y restaurando. **Correcto**.
- Preserva la pila original: **sí**.
- Análisis de complejidad: **no presentado**. Correspondería O(n).

### Ejercicio 7 — `compararPilas`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: compara clave a clave usando **una única pila auxiliar** (apila `e1` y `e2` intercalados) y
  luego restaura ambas pilas. Cumple la restricción de una sola auxiliar. Maneja correctamente pilas de **distinta
  longitud** (los elementos no consumidos quedan en la pila larga y se preservan). **Correcto**, y deja **ambas pilas
  intactas**.
- Preserva las pilas originales: **sí** (ambas).
- Análisis de complejidad: **no presentado**. Correspondería O(min(n, m)).

### Ejercicio 8 — `cambioDeBase`

**Estado: ❌ INCORRECTO**

- Modalidad entregada: iterativa.
- Problemas:
    - **No valida la base** fuera del rango 2–16 que pide el enunciado. Con `base <= 1` el bucle `while (numero > 0)`
      no decrece (`numero / 1 == numero`) → **bucle infinito**; con `base > 16` indexa `digitos[]` fuera de rango.
    - **No reserva el resultado con `malloc`**: usa un buffer `static char resultado[100]`. El contrato del enunciado es
      retornar un `char *` reservado dinámicamente; el buffer estático se **pisa entre llamadas** (dos resultados vivos
      a la vez comparten memoria) y no puede liberarse con `free` (si el llamador lo intenta, rompe).
- Lo que sí maneja bien: `numero = 0` (devuelve `"0"`), dígitos hexadecimales A–F vía la tabla `digitos`.
- Análisis de complejidad: **no presentado**. Correspondería O(log_base(numero)).
- Sugerencias: validar `base` (2–16) al inicio; reservar con `malloc(cantidad_digitos + 1)` el `char *` de salida.

### Ejercicio 9 — `invertirPila`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: construye una pila nueva invertida y restaura la original desde una auxiliar. **Correcto**.
- Preserva la pila original: **sí**.
- Análisis de complejidad: **no presentado**. Correspondería O(n).

### Ejercicio 10 — `eliminarTodasOcurrencias`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: arma una pila resultado sin las ocurrencias de `clave` (reusando `invertirPila` para dejar
  el orden correcto) y restaura el original. **Correcto**.
- Preserva la pila original: **sí**.
- Análisis de complejidad: **no presentado**. Correspondería O(n).
- Sugerencias: reutiliza bien `invertirPila`; las auxiliares quedan vacías (aceptable).

### Ejercicio 11 — `elementosEnComun`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: copia `p1`, recorre y agrega a la resultante los que `buscarElemento(p2, te)` encuentra;
  invierte para mantener el orden. **Correcto**.
- Preserva las pilas originales: **sí** (ambas: `copiar` y `buscarElemento` las restauran).
- Análisis de complejidad: **no presentado**. Correspondería O(n·m) (por cada elemento de `p1`, una búsqueda completa
  en `p2`).
- Sugerencias: si hay claves repetidas en `p1`, se agregan repetidas a la resultante; aclarar si se espera unicidad.

### Ejercicio 12 — `eliminarRepetidos`

**Estado: ⚠️ ADVERTENCIA**

- Modalidad entregada: iterativa.
- Implementación revisada: corregida según el header (`eliminarRepetidos` retorna una **nueva** pila sin repetidos).
  Copia el original, agrega a la resultante solo claves no vistas (`!buscarElemento(resultado, te)`) e invierte para el
  orden. **Correcto**.
- Preserva la pila original: **sí**.
- Análisis de complejidad: **no presentado**. Correspondería O(n²).

### Ejercicio 13 — Mazo de cartas españolas (opcional)

**Estado: 😏 NO ENTREGADO**

- No figura en `practica_pilas.h` ni hay implementación. Es opcional; no se penaliza.

---

## Revisión de tests

Todos los archivos de `practicas/4-pilas/tests/` son los **stubs del template** (idénticos al commit inicial): el
`main()` solo llama `imprimir_titulo(...)` y hace `return 0`, sin invocar ninguna función de la práctica ni `assert`.

| Test | Estado | Observaciones |
|------|--------|----------------|
| `test_01_buscar_elemento.c` | 🚫 No entregado | `main` sin pruebas |
| `test_02_insertar_elemento.c` | 🚫 No entregado | `main` sin pruebas (incluye headers de aserciones, pero no los usa) |
| `test_03_eliminar_elemento.c` | 🚫 No entregado | `main` sin pruebas |
| `test_04_intercambiar_elementos.c` | 🚫 No entregado | `main` sin pruebas |
| `test_05_copiar_pila.c` | 🚫 No entregado | `main` sin pruebas |
| `test_06_contar_elementos.c` | 🚫 No entregado | `main` sin pruebas |
| `test_07_comparar_pilas.c` | 🚫 No entregado | `main` sin pruebas |
| `test_08_cambio_base.c` | 🚫 No entregado | `main` sin pruebas |
| `test_09_invertir_pila.c` | 🚫 No entregado | `main` sin pruebas |
| `test_10_eliminar_todas_ocurrencias.c` | 🚫 No entregado | `main` sin pruebas |
| `test_11_elementos_en_comun.c` | 🚫 No entregado | `main` sin pruebas |
| `test_12_eliminar_repetidos.c` | 🚫 No entregado | `main` sin pruebas; además el título dice "elementos en común" (copiado del test 11) |

### Tests con casos de borde faltantes

- No aplica: ningún test contiene pruebas. Faltan **todos** los casos (normales y de borde) para los 12 ejercicios, y
  no hay tests para el TAD (`p_crear`/`p_apilar`/`p_desapilar`/`p_tope`/`p_es_vacia`/`p_es_llena`) en ninguna de las dos
  representaciones.

---

## Resumen

| Categoría | Estado |
|-----------|--------|
| Archivos `.h` sin modificar (contenido) | ✅ |
| TAD Pila — `pilas_arreglos.c` | 🚫 No implementado |
| TAD Pila — `pilas_punteros.c` | 🚫 No implementado |
| Ejercicio 1 — `buscarElemento` | ⚠️ Advertencia (falta análisis de complejidad) |
| Ejercicio 2 — `insertarElemento` | ⚠️ Advertencia (falta análisis de complejidad) |
| Ejercicio 3 — `eliminarElemento` | ⚠️ Advertencia (leak menor + falta análisis) |
| Ejercicio 4 — `intercambiarElementos` | ⚠️ Advertencia (sin validación de rango + falta análisis) |
| Ejercicio 5 — `copiar` | ⚠️ Advertencia (falta análisis de complejidad) |
| Ejercicio 6 — `contarElementos` | ⚠️ Advertencia (falta análisis de complejidad) |
| Ejercicio 7 — `compararPilas` | ⚠️ Advertencia (falta análisis de complejidad) |
| Ejercicio 8 — `cambioDeBase` | ❌ Incorrecto (sin validar base; buffer `static` en vez de `malloc`) |
| Ejercicio 9 — `invertirPila` | ⚠️ Advertencia (falta análisis de complejidad) |
| Ejercicio 10 — `eliminarTodasOcurrencias` | ⚠️ Advertencia (falta análisis de complejidad) |
| Ejercicio 11 — `elementosEnComun` | ⚠️ Advertencia (falta análisis de complejidad) |
| Ejercicio 12 — `eliminarRepetidos` | ⚠️ Advertencia (falta análisis de complejidad) |
| Ejercicio 13 — Mazo de cartas (opcional) | 😏 No entregado |
| Ejercicios correctos | 0 de 12 sin observaciones; 10 con advertencias; 1 incorrecto (`cambioDeBase`); el TAD subyacente no está implementado |
| Tests entregados | 0 de 12 |
| Tests con buena cobertura | 0 de 12 |

### Comentario de cierre

La resolución de los ejercicios en `practica_pilas.c` muestra un **buen manejo de la disciplina LIFO**: se usa el TAD
como caja negra (solo `p_apilar`/`p_desapilar`/`p_tope`/`p_es_vacia`), se preservan correctamente las pilas que deben
quedar intactas y se reutilizan funciones propias (`copiar`, `invertirPila`). Las dos cuestiones de fondo a corregir
son: (1) **implementar el TAD Pila** en sus dos representaciones (`pilas_arreglos.c` y `pilas_punteros.c`), hoy vacías —
sin eso nada puede ejecutarse ni testearse; (2) **completar los tests** y **agregar el análisis de complejidad**
(iterativo/recursivo) que pide el enunciado. Aparte, corregir `cambioDeBase` (validar base 2–16 y reservar la salida
con `malloc`).
