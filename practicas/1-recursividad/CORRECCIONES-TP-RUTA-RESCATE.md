# Correcciones — TP Integrador de Recursividad: Ruta de Rescate en Mina

**Fecha de corrección:** 2026-05-06
**Referencia evaluada:** `origin/main` (commit `0bd1a83`, merge del PR #2 "TP Integrador - Ruta de escape")
**Repositorio:** https://github.com/valentinolavigna/EDA1

> Esta corrección reemplaza una versión previa de este archivo que se había generado contra el `main` local desactualizado y concluía erróneamente que el TP no había sido entregado. El TP sí fue entregado: el PR #2 fue mergeado a `origin/main` y aporta la implementación, los tests y los archivos de prueba del TP integrador. La evaluación que sigue se hace sobre `origin/main`.

---

## Integrantes del equipo

Fuente canónica: `README.md` de la raíz.

| Integrante (README)    | Líneas aportadas (+/-) en alcance TP | % estimado por líneas | Commits (referencia) | Committers unificados                        |
|------------------------|--------------------------------------|-----------------------|----------------------|----------------------------------------------|
| Valentino Lavigna Jara | 0 / 0                                | 0%                    | 0                    | —                                            |
| Andoni Gallego         | +285 / -0                            | 100%                  | 1                    | Andoni Gallego <andonigallego20@gmail.com>   |
| Ignacio Walsh          | 0 / 0                                | 0%                    | 0                    | —                                            |

Alcance considerado para las métricas: `practicas/1-recursividad/ruta_mina.c`, `practicas/1-recursividad/tests/test_tp_ruta_mina.c` y `practicas/1-recursividad/archivos/prueba*`. La modificación del header `recursividad.h` para declarar `resolver_ruta_mina` también pertenece al mismo commit (`ad61300`).

Observación: el commit del TP integrador fue realizado únicamente por Andoni Gallego. La integración a `main` se hizo vía PR #2 abierto desde `valentinolavigna/feature/TP-Ruta-Escape`. Esto no es un defecto formal, pero queda registrado para que el equipo lo tenga presente.

---

## Método aplicado

- Tests del grupo: **Ejecutados** (`test_tp_ruta_mina`).
- Tests de cátedra / verificación cruzada: **Ejecutada** sobre los 3 casos de `guia-de-ejercicios-2023-profesores/practicas/1-recursividad/archivos/ruta_mina_prueba*`.
- Revisión estática del código: **Sí**, sobre `ruta_mina.c`, `recursividad.h`, `test_tp_ruta_mina.c` y los archivos de prueba.
- Evidencia breve:
  - `git fetch --all --tags --prune` y `git checkout origin/main` (detached HEAD en `0bd1a83`).
  - Build: `cmake -S . -B /tmp/equipo04-build && cmake --build /tmp/equipo04-build --target test_tp_ruta_mina` → OK (un warning preexistente en `recursividad.c:166` ajeno al TP integrador).
  - Ejecución `./test_tp_ruta_mina` → todos los `assert(file_eq(...))` pasan, exit 0.
  - Runner mínimo (link contra `librecursividad.a`) ejecutado sobre las 3 entradas de cátedra; `diff -u` contra los `_salida_esperada.txt` de cátedra → sin diferencias en los 3 casos.

---

## Estado del TP integrador

| Función                  | Estado          |
|--------------------------|-----------------|
| `cargar_mapa` (rol cumplido por `leer_mapa`, estática) | ✅ Correcto |
| `buscar_ruta` (rol cumplido por `buscar`, estática)    | ✅ Correcto |
| `resolver_ruta_mina`                                  | ✅ Correcto |

Nota: el grupo no expone `cargar_mapa`/`buscar_ruta` con esos nombres en el header (la cátedra solo recomienda nombres). Internamente, `leer_mapa` cumple el rol de carga y `buscar` el rol de exploración recursiva. Los criterios específicos del TP no exigen nombres idénticos a la referencia, así que se evalúa por comportamiento.

### `leer_mapa` (carga del mapa)
**Estado: ✅ CORRECTO**

- Lee dimensiones con `fscanf("%d %d\n")`, reserva la grilla fila por fila (`malloc(columnas+1)` para alojar el `'\0'`) y lee cada fila con `fscanf("%s", ...)`.
- Detecta `I` y `S` durante la carga y los guarda en `mapa->inicio` / `mapa->salida` con coordenadas en base 1.
- En cualquier fallo (apertura, malloc, fscanf) libera lo asignado hasta el momento, cierra el archivo y retorna `NULL`. La cadena de limpieza es consistente.

Sugerencia (no degrada el estado):
- La validación de contenido del mapa es mínima: no chequea presencia y unicidad de `I`/`S`, ni que cada celda esté dentro del alfabeto válido (`I S # . 0-9`). Para los casos del enunciado y del runner de cátedra esto no afecta el resultado, pero entradas inválidas (sin `I`, con `I` duplicado, con caracteres extraños) podrían ser interpretadas como entrada válida con resultados indefinidos.

### `buscar` (exploración recursiva)
**Estado: ✅ CORRECTO**

- Backtracking recursivo de exhaustividad: prueba las 4 direcciones, marca la celda destino como visitada, llama recursivamente y la desmarca al volver. Eso satisface el requisito pedagógico de recursión real.
- Orden de iteración de movimientos: `A`, `B`, `D`, `I`. Coincide con el orden lexicográfico exigido por la cátedra para el desempate final.
- Manejo correcto del caso base: cuando `(fila, columna)` coincide con `salida`, evalúa `es_mejor` y, si corresponde, actualiza la mejor solución.
- Bloquea `#` y respeta los límites de la grilla.
- Suma puntaje solo cuando la celda destino es `0..9`; las celdas `.`, `S` e `I` no aportan puntaje (consistente con el enunciado: el puntaje viene de tesoros).

Análisis de desempates en `es_mejor` + `actualizar_solucion`:
- Si `nuevo_puntaje > puntaje` → reemplaza.
- Si `nuevo_puntaje == puntaje` y `nuevos_pasos < pasos` → reemplaza.
- En caso de empate total (mismo puntaje y mismos pasos), `es_mejor` retorna `false` y se conserva la primera solución encontrada. Como la DFS itera en orden `A, B, D, I` en cada llamada, la primera solución óptima alcanzada es la lexicográficamente mínima. El criterio jerárquico `puntaje > pasos > lexicográfico` queda satisfecho. Esto está corroborado por el caso de prueba 4 del grupo y por la prueba 2 de cátedra (ambos resuelven empates por lexicográfico y dan `BBDD`).

### `resolver_ruta_mina`
**Estado: ✅ CORRECTO**

- Orquesta correctamente: `leer_mapa` → reservar `visitado`, `camino`, `movimientos` → fijar punto inicial → `buscar` → emitir resultado → liberar todo.
- Salida exacta:
  - Sin camino: `RESULTADO: SIN_CAMINO\n`.
  - Con camino: `RESULTADO: ENCONTRADO`, `PUNTAJE`, `PASOS`, `MOVIMIENTOS`, `CAMINO` con coordenadas en base 1 separadas por ` -> `, terminado en `\n`.
  - Coincide línea a línea con los `_salida_esperada.txt` del grupo y con los 3 de cátedra.
- Memoria: libera `mejor.movimientos`, `mejor.camino`, `movimientos`, `camino`, cada fila de `visitado`, `visitado` y el mapa. No se observan leaks en la ruta normal.

⚠️ ADVERTENCIA — Comportamiento ante fallo de I/O al abrir el archivo de salida:
- Si `fopen(archivo_salida, "w")` falla (por ejemplo, ruta no escribible), la función retorna sin emitir ningún diagnóstico ni archivo. Para los casos de prueba esto no se dispara, pero la consigna espera salida determinística incluso ante fallos. Es una advertencia de robustez, no un error de lógica.

⚠️ ADVERTENCIA — Comportamiento ante mapa con `filas`/`columnas` no positivos:
- Si la entrada trae `filas <= 0` o `columnas <= 0`, `leer_mapa` igual reservará estructuras de tamaño 0 o negativo (cast a `size_t`) y la salida resultante puede no reflejar correctamente que la entrada era inválida. No se gatilla en los casos provistos pero queda como hueco de validación.

Sugerencia (no degrada el estado):
- `leer_mapa` y `resolver_ruta_mina` mezclan responsabilidades de I/O, validación, asignación y orquestación; podrían dividirse para facilitar tests unitarios. No es exigido por la consigna.

---

## Revisión de tests

| Test                          | Estado          | Observaciones                                                                                                                              |
|-------------------------------|-----------------|--------------------------------------------------------------------------------------------------------------------------------------------|
| `test_tp_ruta_mina.c`         | ✅ Completo     | Cubre los 4 casos pedidos por los criterios: camino con puntaje vs. atajo, sin camino, empate por pasos, empate por lexicográfico. Compara archivo completo con `file_eq`. |

Detalle de cobertura frente a los criterios mínimos del TP:

- Caso con camino válido: ✅ (prueba 1).
- Caso sin camino: ✅ (prueba 2).
- Empate por puntaje resuelto por pasos: ✅ (prueba 3).
- Empate por puntaje y pasos resuelto lexicográficamente: ✅ (prueba 4).
- Comparación de salida por archivo completo: ✅ (función `file_eq` línea a línea, incluyendo control de líneas extra al final).

Sugerencias (opcionales):
- Agregar un caso con celdas `#` que obliguen a rodear (la prueba 2 las usa solo para bloquear toda salida; un caso con `#` parcial que fuerce un detour daría mayor confianza).
- Reportar el detalle del archivo que falla en `file_eq` (qué línea difiere) facilitaría depurar regresiones; actualmente el `assert` solo dice "falló".

---

## Verificación cruzada con entradas de cátedra

Se compiló un runner mínimo (`runner.c` que invoca `resolver_ruta_mina`) enlazado contra `librecursividad.a` del grupo y se ejecutó sobre las 3 entradas oficiales de `guia-de-ejercicios-2023-profesores/practicas/1-recursividad/archivos/`. Comparación con `diff -u` contra los `_salida_esperada.txt` de cátedra:

| Entrada de cátedra                  | Resultado del grupo          | Diferencias vs. esperado de cátedra |
|-------------------------------------|------------------------------|--------------------------------------|
| `ruta_mina_prueba1_entrada.txt`     | ENCONTRADO, P=3, S=4, DDBD   | ✅ Coincide línea a línea            |
| `ruta_mina_prueba2_entrada.txt`     | ENCONTRADO, P=0, S=4, BBDD   | ✅ Coincide línea a línea            |
| `ruta_mina_prueba3_entrada.txt`     | SIN_CAMINO                   | ✅ Coincide línea a línea            |

No hay discrepancias de formato ni de lógica en ninguno de los 3 casos.

---

## Archivos de cátedra (.h)

- Único `.h` modificado en el alcance: `practicas/1-recursividad/recursividad.h`.
- Diferencia respecto del primer commit del repo (`d1f593a`): se agrega la línea `void resolver_ruta_mina(const char *archivo_entrada, const char *archivo_salida);`. Esta es una declaración necesaria para exponer la API del TP y no altera el resto del header. Se considera **CAMBIO_REAL pero esperado y consistente con la consigna**, no se marca como error.

---

## Resumen

| Categoría                                                | Estado                                |
|----------------------------------------------------------|---------------------------------------|
| TP integrador entregado                                  | ✅ Entregado en `origin/main`          |
| `recursividad.h` (cambios solo agregan API del TP)       | ✅ Aceptable                           |
| `leer_mapa` (rol `cargar_mapa`)                          | ✅ Correcto (con sugerencia opcional)  |
| `buscar` (rol `buscar_ruta`, recursivo)                  | ✅ Correcto                            |
| `resolver_ruta_mina`                                     | ✅ Correcto (con 2 advertencias de robustez no críticas) |
| Formato de salida exacto                                 | ✅ Coincide con cátedra y grupo        |
| Desempates `puntaje > pasos > lexicográfico`             | ✅ Correctos                           |
| Recursión real en exploración                            | ✅ DFS recursivo con backtracking      |
| Manejo de memoria                                        | ✅ Sin leaks observables                |
| Tests del grupo (`test_tp_ruta_mina`)                    | ✅ 4/4 casos pasan                     |
| Verificación cruzada contra entradas de cátedra          | ✅ 3/3 casos coinciden línea a línea   |

**Cierre:** el TP integrador está implementado correctamente en `origin/main`. La lógica recursiva, los desempates y el formato de salida cumplen el enunciado y validan tanto contra los tests propios del grupo como contra las entradas de cátedra. Las dos advertencias señaladas (fallo de I/O al abrir salida y dimensiones no positivas) son huecos de robustez frente a entradas o entornos no contemplados por las pruebas, no afectan la corrección sobre los casos válidos.
