# Correcciones — Práctica 1: Recursividad

**Fecha de corrección:** 2026-04-20
**Tag/Branch evaluado:** `main`
**Repositorio:** `git@github.com:valentinolavigna/EDA1.git`

---

## Integrantes del equipo

| Integrante (README) | Líneas aportadas (+/-) | % estimado por líneas | Commits (referencia) | Committers unificados |
|---------------------|-------------------------|-----------------------|----------------------|------------------------|
| Valentino Lavigna Jara | +273/-7 | 54.58% | 2 | Valentino Lavigna Jara |
| Andoni Gallego | +141/-13 | 30.02% | 1 | Andoni Gallego |
| Ignacio Walsh | +66/-13 | 15.40% | 3 | Ignacio Walsh |

---

## Método aplicado

- Tests del grupo: Ejecutados
- Tests de cátedra: No ejecutados
- Revisión estática del código: Sí
- Evidencia breve: `cmake -S . -B cmake-build-debug && cmake --build cmake-build-debug && ctest --test-dir cmake-build-debug --output-on-failure`; además se ejecutaron individualmente `test_capicua`, `test_palindromos`, `test_producto`, `test_fibonacci`, `test_resto`, `test_separador_miles`, `test_mafia_china`, `test_onda_digital`, `test_divisible_por_7` y `test_explosion`. No se ejecutaron tests de cátedra porque no hay una suite adicional provista en el repositorio.

---

## Corrección de la práctica

### Ejercicio 1 — `esCapicua()`

**Estado: ✅ CORRECTO**

La solución usa recursión real a través de `invertir()`, tiene caso base claro (`numero == 0`) y devuelve correctamente `false` para negativos. Para el dominio esperado del ejercicio resuelve bien los casos nominales y borde.

### Ejercicio 2 — `esPalindromo()`

**Estado: ❌ INCORRECTO**

La idea recursiva y el caso base están bien encaminados, pero la implementación modifica la cadena de entrada (`palabra[largo - 1] = '\0'`). Eso rompe cuando se pasa un string literal, que es exactamente lo que hace `test_palindromos`, y termina en `Bus error`. Además, alterar la entrada no era necesario para resolver el ejercicio.

### Ejercicio 3 — `productoRecursivo()`

**Estado: ✅ CORRECTO**

Está resuelto de forma recursiva, con caso base en `n == 0` y avance correcto hacia ese caso. También contempla multiplicadores negativos sin perder el comportamiento esperado por el enunciado.

### Ejercicio 4 — `terminoSerieDeFibonacci()`

**Estado: ✅ CORRECTO**

La definición recursiva y los casos base usados (`n < 2`) producen los valores esperados en los tests entregados. Correcta para el objetivo de la práctica; no se penaliza complejidad alta en este TP.

### Ejercicio 5 — `restoRecursivo()`

**Estado: 🚫 NO IMPLEMENTADO**

La función quedó vacía y además el compilador emite una advertencia por no retornar un valor. No hay implementación para el cálculo del resto mediante restas sucesivas.

### Ejercicio 6 — `agregarSeparadorMiles()`

**Estado: ⚠️ MEJORA OPCIONAL**

La función principal está resuelta recursivamente y arma correctamente el resultado para entradas como las del enunciado. Como detalle a mejorar, quedó declarada una auxiliar `agregarSeparadoresRecursivo()` sin implementación ni uso, lo que deja código sobrante y genera una advertencia de compilación.

### Ejercicio 7 — `chinos()`

**Estado: ⚠️ MEJORA OPCIONAL**

Para niveles mayores o iguales a 1 la construcción recursiva del string es correcta y la memoria intermedia se libera. Como mejora, conviene contemplar explícitamente `nivel == 0`; al ser `unsigned int`, hoy ese caso no corta y puede derivar en recursión inválida.

### Ejercicio 8 — `ondaDigital()`

**Estado: ✅ CORRECTO**

La salida se construye de forma recursiva, distingue bien entre continuidad del mismo nivel y cambio de nivel, y devuelve memoria propia para el resultado. También contempla correctamente la cadena vacía.

### Ejercicio 9 — `esDivisiblePor7()`

**Estado: ✅ CORRECTO**

La reducción recursiva implementa el método pedido, avanza hacia el caso base y resuelve tanto positivos como negativos. La lógica del resultado final (`reducido % 7 == 0`) es consistente con el algoritmo del enunciado.

### Ejercicio 10 — `explosion()`

**Estado: ✅ CORRECTO**

La descomposición recursiva sigue el orden solicitado por el ejemplo y genera los fragmentos esperados. La acumulación dinámica del resultado funciona para los casos probados y devuelve el tamaño por referencia.

---

## Revisión de tests

| Test | Estado | Observaciones |
|------|--------|---------------|
| `test_capicua.c` | ✅ Completo | Prueba caso nominal, casos borde (`1`, `11`, `10`) y negativo. |
| `test_palindromos.c` | ✅ Completo | Cubre caso nominal, vacío, longitud 1 y no palíndromo; hoy falla por la implementación que escribe sobre un literal. |
| `test_producto.c` | ✅ Completo | Cubre caso nominal, cero y signos negativos con más de un nivel de recursión. |
| `test_fibonacci.c` | ✅ Completo | Cubre bases (`0`, `1`, `2`) y un caso recursivo (`6`). |
| `test_resto.c` | 🚫 No entregado | El `main()` está vacío y no prueba ninguna función de la práctica. |
| `test_separador_miles.c` | 🚫 No entregado | El `main()` solo imprime el título y retorna sin hacer pruebas. |
| `test_mafia_china.c` | 🚫 No entregado | El `main()` solo imprime el título y retorna sin hacer pruebas. |
| `test_onda_digital.c` | ✅ Completo | Cubre cambios de nivel, repeticiones consecutivas y cadena vacía con aserciones correctas. |
| `test_divisible_por_7.c` | ⚠️ Incompleto | Verifica casos positivos y negativos, pero falta un caso que fuerce varias reducciones recursivas como `32291`. |
| `test_explosion.c` | ⚠️ Incompleto | Cubre dos casos nominales con varias explosiones, pero falta al menos un caso borde (`n <= b` o `b <= 1`). |

### Tests con casos de borde faltantes
- `test_divisible_por_7.c`: falta un caso que fuerce más de un nivel de recursión.
- `test_explosion.c`: falta cubrir cuando el número ya no explota o cuando la bomba no es válida.
- `test_separador_miles.c`: no prueba string vacío, longitud menor o igual a 3 ni casos con más de un separador.
- `test_mafia_china.c`: no prueba nivel 1 ni niveles recursivos mayores.
- `test_resto.c`: no prueba dividendos negativos, divisor negativo ni resto cero.

---

## Resumen

| Categoría | Estado |
|-----------|--------|
| Archivos `.h` sin modificar (contenido) | ✅ |
| `esCapicua` | ✅ Correcto |
| `esPalindromo` | ❌ Incorrecto |
| `productoRecursivo` | ✅ Correcto |
| `terminoSerieDeFibonacci` | ✅ Correcto |
| `restoRecursivo` | 🚫 No implementado |
| `agregarSeparadorMiles` | ⚠️ Mejora opcional |
| `chinos` | ⚠️ Mejora opcional |
| `ondaDigital` | ✅ Correcto |
| `esDivisiblePor7` | ✅ Correcto |
| `explosion` | ✅ Correcto |
| Ejercicios correctos | 6 de 10 correctos; 2 con mejoras opcionales; 1 incorrecto; 1 no implementado |
| Tests entregados | 7 de 10 |
| Tests con buena cobertura | 5 de 10 |
