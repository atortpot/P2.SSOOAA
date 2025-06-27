## Resultados de rendimiento

Ejecutado en máquina X (2 cores, 8 GB RAM).

| Programa             | real   | user   | sys    | %CPU medio* | Observaciones                        |
|----------------------|--------|--------|--------|-------------|--------------------------------------|
| `procSecuencial`     | 12.34s | 12.30s | 0.02s  | 98%         | Sumatorio fila a fila, sin concurr.  |
| `hebSecuencial`      | 11.50s | 11.47s | 0.03s  | 95%         | Un solo hilo, overhead pthread.      |
| `procConcurrente`    | 3.20s  | 12.10s | 0.15s  | 250%        | 20 procesos, paralelismo real.       |
| `hebConcurrente`     | 2.80s  | 10.50s | 0.10s  | 300%        | 20 hebras, PTHREAD_SCOPE_SYSTEM.     |
| `hebConcurrente` (P) | 2.90s  | 10.55s | 0.12s  | 280%        | PTHREAD_SCOPE_PROCESS.               |

\* obtenido de la columna `%CPU` de `top` (promedio sobre la duración).

# P2.SSOOAA
